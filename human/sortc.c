#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct  
{
    int *arr;
    int len;
}data;
void swap(int *x, int * y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    

}
void quick_sort_recursive(int  arr[], int start, int end)
{
    int a =0;
    if (start >=end){
        return;}
    
 
    
    int mid = arr[end];
    int left = start, right = end-1;
    while(left < right){
        while(arr[left] < mid && left < right){
            left++;
        }
        while(arr[right] >= mid && left < right){
           right --; 
        }
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[right]){
        swap(&arr[left], &arr[end]);
    } else{
        left++;
    }

    if(left)
        quick_sort_recursive(arr, start, left -1 );
    quick_sort_recursive(arr, start+1, end);
    a++;
    
}
void *quick_sort(void *arg)
{
    data *put;
    put = (data *)arg;
    printf("run here--->>\n");
    quick_sort_recursive(put->arr, 0, put->len-1);

    return ((void *)0);
    

}
typedef struct get_num
{
    float a;
    float b;
    float c;
    
}get_num;

void print_num(get_num *a)
{
    printf("%p\n", &a);
    printf("%f\n", a->a);
}

int main()
{
    srand(time(NULL));
    clockid_t start, end, time_data;
    start = clock();
   // int a[] = {2,43,23,4,123,4,12,34,123,5,1,23,4,12,3,123,4214,123,123,413,43,23,4,123,4,12,34,123,5,1,23,4,12,3,123,4214,123,123,41,29};
    
    get_num a;
    a.a =10;
    a.b = 2;
    a.c= 3;
    print_num(&a);

//
//    int a[100000] = {};
//    for(int i = 0; i < 100;i++){
//        a[i] = rand();
//    }
//    
//    time_data = clock();
//    printf("run time is -->>>%f\n", (double)(time_data-start) / CLOCKS_PER_SEC);
//    
//    int temp;
//    int len_a = sizeof(a) / sizeof(a[0]);
//    printf("size of %d\n",(int)(sizeof(a)/ sizeof(a[0])));
   /* 
    for(int i = 0; i< len_a-1; i++){
        for(int j = 0; j < len_a- 1 -i; j++){
           if (a[j] < a[j+1]){
 
               //printf("a[i] is :%d\n", a[i]);
               swap(&a[j],&a[j+1]);
            } 
        }
     

    }*/
   
    /*
    pthread_t thread1;
    data datas;
    datas.arr = (int *)malloc(sizeof (datas.arr)* 10000);
    memcpy(datas.arr, a,10000);
    datas.len = len_a;
    int ret_thrd1;
    for(int i =0; i< 10; i++){
        datas.arr = (int *)malloc(sizeof (datas.arr)* 10000);
        memcpy(datas.arr, a,10000);
        datas.len = len_a;
        ret_thrd1 = pthread_create(&thread1, NULL, &quick_sort, &datas);}
}
    
//    quick_sort(a, len_a);
   // for(int i = 0; i< 1000; i++){
   //     printf("b is -->>>%d\n", b[i]) ;

   // }
    end = clock();
    printf("run time is -->>>%f\n", (double)(end-start) / CLOCKS_PER_SEC);
    
    */
    return 0;
}
