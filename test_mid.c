#include <assert.h>  
#include <fcntl.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
  
#include <sys/time.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
  
typedef struct bucket_t {  
    int *buf;       /* 输出缓冲区 */  
    int count;      /* 当前有多少个数 */  
    int idx;        /* 缓冲区的指针 */  
} bucket_t;  
  
static unsigned int BUF_PAGES;      /* 缓冲区有多少个page */  
static unsigned int PAGE_SIZE;      /* page的大小 */  
static unsigned int BUF_SIZE;       /* 缓冲区的大小, BUF_SIZE = BUF_PAGES*PAGE_SIZE */  
static unsigned int nbuckets;       /* 分成多少个桶 */  
static unsigned int BUCKET_BUF_SIZE;  
  
static int *buffer;                 /* 输入缓冲区 */  
  
long get_time_usecs();  
void write_to_file(bucket_t *bucket, int pos);  
int partition(int *a, int s, int t);  
int quick_select(int *a, int s, int t, int i);  
void swap(int *p, int *q);  
  
int main(int argc, char **argv)  
{  
    char                filename[20];  
    unsigned int        bp, length, bucket_size, k;  
    int                 fd, i, bytes;  
    bucket_t            *bucket;  
  
    long start_usecs = get_time_usecs();  
  
    strcpy(filename, argv[1]);  
    fd = open(filename, O_RDONLY);  
    if (fd < 0) {  
        printf("can't open file %s\n", filename);  
        exit(0);  
    }  
    nbuckets = 1024;  
    k = atoi(argv[2]);  
    PAGE_SIZE = 4096;                           /* page = 4KB */  
    BUF_PAGES = 1024;  
    BUF_SIZE = PAGE_SIZE*BUF_PAGES;             /* 4KB * 1024 = 4M */  
    BUCKET_BUF_SIZE = PAGE_SIZE*128;            /* 4KB * 128 = 512KB */  
    buffer = (int *)malloc(BUF_SIZE);  
  
    //把1-2^32个数分成nbucket个组, nbuckets必须等于2的n次幂  
    bucket = malloc(sizeof(bucket_t)*nbuckets);   
    if (bucket == NULL) exit(0);  
    for (i = 0; i < nbuckets; i++) {  
        bucket[i].buf = malloc(BUCKET_BUF_SIZE);  
        if (bucket[i].buf == NULL) {  
            exit(0);  
        }  
        bucket[i].idx = 0;  
        bucket[i].count = 0;  
    }  
    bucket_size = (1<<22);        /* 分成1024个桶，每个桶容纳2^22个数 */  
  
    // 读入第一批数据到输入缓冲区   
    bytes = read(fd, buffer, BUF_SIZE);  
    length = bytes/4;  
    bp = 0;  
  
    int             element, pos;  
    unsigned int    base;  
    bucket_t        *p;  
      
    base = 2147483648;  
    while (1) {  
        //从输入缓冲区取出一个数，加到对应的桶  
        element = buffer[bp++];  
        pos = (((long)element)+base)>>22;  
        p = &bucket[pos];  
        p->buf[p->idx++] = element;  
        p->count++;  
        //桶内的缓冲区已满，写入文件  
        if (p->idx*4 == BUCKET_BUF_SIZE) {  
            write_to_file(p, pos);  
            p->idx = 0;  
        }  
        //输入缓冲区的数已用完  
        if (bp == length) {  
            bytes = read(fd, buffer, BUF_SIZE);  
            if (bytes == 0) {   
                break;  
            }  
            length = bytes/4;  
            bp = 0;  
        }  
    }  
  
    //把每个桶剩下的数写入文件  
    for (i = 0; i < nbuckets; i++) {  
        write_to_file(bucket+i, i);  
    }  
  
    free(buffer);  
    close(fd);  
  
    buffer = malloc(bucket_size*4);  
    if (buffer == NULL)  exit(0);   
  
    //找出第k大的数位于哪个文件  
    unsigned sum = 0;  
    for (i = 0; i < nbuckets && sum < k; i++) {  
        sum += bucket[i].count;  
    }  
    i--;  
  
    //把该文件读入内存  
    sprintf(filename, "foo_%d.dat", i);  
    printf("第%d大的数位于文件%s的第%d大的数\n", k, filename, k+bucket[i].count-sum);  
    fd = open(filename, O_RDONLY);  
    if (fd < 0) {  
        printf("can't open file %s\n", filename);  
        free(buffer);  
        exit(0);  
    }  
    bytes = read(fd, buffer, bucket_size*4);  
    length = bytes/4;  
  
    //选择文件内第(k+bucket[i].count-sum)大的数  
    int answer;  
    answer = quick_select(buffer, 1, length-1, k+bucket[i].count-sum);  
    printf("第%d大的数 = %d\n", k, answer);  
  
    close(fd);  
    free(buffer);  
  
    //free buckets  
    for (i = 0; i < nbuckets; i++) {  
        free(bucket[i].buf);  
    }  
    free(bucket);  
  
    long end_usecs = get_time_usecs();  
    double secs = (double)(end_usecs - start_usecs) / (double)1000000;  
    printf("it took %.02f seconds.\n", secs);  
  
    return 0;  
}  
  
void write_to_file(bucket_t *bucket, int pos)  
{  
    char    filename[20];  
    int     fd, bytes;  
  
    sprintf(filename, "foo_%d.dat", pos);  
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);     
    if (fd < 0) {  
        printf("can't open file %s\n", filename);  
        exit(0);  
    }  
    bytes = write(fd, bucket->buf, bucket->idx*4);  
    if (bucket->idx*4 != bytes) {  
        printf("idx = %d, bytes = %d, write error\n", bucket->idx, bytes);  
        close(fd);  
        exit(0);  
    }  
    close(fd);  
}  
  
long get_time_usecs()  
{  
    struct timeval time;  
    struct timezone tz;  
    memset(&tz, '\0', sizeof(struct timezone));  
    gettimeofday(&time, &tz);  
    long usecs = time.tv_sec*1000000 + time.tv_usec;  
  
    return usecs;  
}  
  
void swap(int *p, int *q)  
{  
    int     tmp;  
  
    tmp = *p;  
    *p = *q;  
    *q = tmp;  
}  
  
/* 把a[t]作为参考，将数组分成三部分: 小于等于a[t]， 
 * a[t]以及大于a[t]，分割完毕后，a[t]所在的下标即是a[t]的顺序 
 */  
int partition(int *a, int s, int t)  
{  
    int     i, j;   /* i用来遍历a[s]...a[t-1], j指向大于x部分的第一个元素 */  
  
    for (i = j = s; i < t; i++) {  
        if (a[i] < a[t]) {  
            swap(a+i, a+j);  
            j++;  
        }  
    }  
    swap(a+j, a+t);  
  
    return j;  
}  
  
/* 选择数组中第i大的元素并返回 */  
int quick_select(int *a, int s, int t, int i)  
{  
    int     p, m;  
  
    if (s == t) return a[t];  
    p = partition(a, s, t);  
    m = p - s + 1;  
    if (m == i) return a[p];  
    if (m > i) {  
        return quick_select(a, s, p-1, i);  
    }  
    return quick_select(a, p+1, t, i-m);  
}
