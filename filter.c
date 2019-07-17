# include <stdio.h>
# include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIMGEA  1

// 计算最大值
float max(double *a, int n)
{
    
 	double array=a[0];
 	for (int i=1;i<n;i++)
 	{
 		if (a[i]>array)
 		array=a[i];
	 }
	 return array;
}

// 计算平均值
float ave(float a[],int n)
{
  	int sum=0;
  	for (int i=0;i<n;i++)
        sum+=a[i];
  	return sum/n;
}

// 计算方差
float calculateSD(float data[], int n)
{
    float sum = 0.0, mean, standardDeviation = 0.0;
 
    int i;
 
    for(i=0; i<n; ++i){
    
        sum += data[i];
    }
 
    mean = sum/n;
 
    for(i=0; i < n; ++i)
        standardDeviation += pow(data[i] - mean, 2);
 
    return sqrt(standardDeviation/n);
}
// 差分
float * differences(float *a, int n, float *b)
{
    int c;
    for(c = 0; c < n -1 ; c++) {
        b[c] = a[c+1]- a[c];
    }

    
   // int size_v = sizeof(b) / sizeof(b[0]);
   // printf("size of -->>b%d\n", size_v);
   return b;
}

void filter(float * a, int size_a, float standard_y[size_a])
{
    float resdual_v[size_a];
    float ave_data = ave(a, size_a);
    float deviation_s = calculateSD(a, size_a);
    for(int i =0 ; i < size_a; i++){
        resdual_v[i] = a[i] - ave_data;
        standard_y[i] = fabs(resdual_v[i]) / deviation_s;
    } 
}
void organzier_data(float *standard_y, int size_a, float *data, float *original_data)
{

    int i = 1;
    int j = 1;
    
    data[0] = original_data[0];
    while( i <  size_a - 1) {
       if(standard_y[i -1] < SIMGEA) {
            data[j] = original_data[i];
            i+=1;
            j+= 1;
       } else if (standard_y[i] < SIMGEA ) {
           data[j] = original_data[i];
            i+=1;
            j+= 1;
       } else {
            i += 1;
       }
    }

}
void readFile(char *line, char *filename)
{

    char buffer[1024];
    char *recode;
    FILE *fp;
    if((fp = fopen(filename, "r")) != NULL){
        fseek(fp, 1L, SEEK_SET);
        const char *delims = ",";
        while((line = fgets(buffer, sizeof(buffer), fp)) != NULL) {
            if(line == NULL){
                return ;
            }
            recode = strtok(line, delims);
            while(recode){
                printf("recode -->> %s\n",recode);
                recode = strtok(NULL, delims);
            }
        }
    }

}

int main()
{
    //int i;
    float a[] = {1, 9, 2, 139, 6, 7, 
        277, 23,1,32,34,1,32,4,12,31,22,4,
        23,23,4,12,270,22,4,23,234,12,31,22,4,23,234,12,31,22,4,23,234,12,31,22,4,23,23};
    
    int size_a = sizeof(a) / sizeof(a[0]);
    float b[size_a - 1];
    differences(a, size_a, b);

    int size = sizeof(a) / sizeof(a[0]);
    float standard_y[size];
    filter(b, size, standard_y);

    int num = 2; 
    for(int i = 0; i < size -2; i ++) {
        printf("standard_y is -> %0.2f\n", standard_y[i]);
       if(standard_y[i] < SIMGEA) {
            num += 1;
       } else if (standard_y[i + 1] < SIMGEA ) {
            num += 1;
       } 
    }
    float data[num];
    organzier_data(standard_y, size_a, data, a);


    for(int i = 0; i < num; i++) {

        printf("arr number is -> %0.2f\n", data[i]);
    }
    
    return 0; 

}
