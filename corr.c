# include <stdio.h>
# include <math.h>
#include <stdlib.h>

double max(double *a, int n)
{
    
 	double array=a[0];
 	for (int i=1;i<n;i++)
 	{
 		if (a[i]>array)
 		array=a[i];
	 }
	 return array;
}

float ave(float a[],int n)
{
  	int sum=0;
  	for (int i=0;i<n;i++)
        sum+=a[i];
  	return sum/n;
}
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
double * differences(double *a, int n)
{
    int c;
    double b[9] ;
    for(c = 0; c < n; c++) {
        printf("n --->>%d\n", c);
        b[c] = a[c+1]- a[c];
        printf("bs is->>>>%.2f\n", b[c]);
    }

    
   // int size_v = sizeof(b) / sizeof(b[0]);
   // printf("size of -->>b%d\n", size_v);
    return 0;
}
void residual(float *a, int n, float * b)
{
   for(int i =0 ; i < n; i++){
        b[i] = a[i] - ave(a, n);
   } 
}
int main()
{
    //int i;
    float a[] = {1, 9, 2, 139, 6, 7, 
        277, 23,1,32,34,1,32,4,12,31,22,4,
        23,23,4,12,31,22,4,23,234,12,31,22,4,23,234,12,31,22,4,23,234,12,31,22,4,23,23};
    //float c[] = {1, 9, 2, 139, 6, 7, 277};
    int size_a = sizeof(a) / sizeof(a[0]);

    float *arr = (float*)malloc(size_a * sizeof(float));
    
    float resdual_v[size_a];
    float ave_data = ave(a, size_a);
    printf("ave data -->>>%0.2f\n", ave_data);
    float deviation_s = calculateSD(a, size_a);
    float standard_y[size_a];
    for(int i =0 ; i < size_a; i++){
        resdual_v[i] = a[i] - ave_data;
        standard_y[i] = fabs(resdual_v[i]) / deviation_s;
        printf("standard_y -->>%0.2f\n", standard_y[i]);
    } 
    float simga = 3;
    for(int i = 0; i < size_a; i++){
        if (standard_y[i] < simga) {
           arr[i] = a[i];
        }
        printf("the new data is -> %0.2f\n",arr[i]);
        
    } 
    printf("simga is -->>%.2f\n", simga);
    free(arr);
    //v = differences(a, size_a);
   /*
    double v[size_a-1];
    
   
    for(i = 0; i < size_a -1 ; i++) {
        v[i] = a[i+1]- a[i];
        printf("the v[i] is ->%.2f\n", v[i]);
    }

    printf("calculate -->%0.2f\n", calculateSD(v, size_a-1));
    */
    /*

    double b[] = {3, 56, 2, 341, 41, 1123};

    int size_b = sizeof(b) / sizeof(b[0]);
    double ava_a = ave(a, size_a);
    double ava_b = ave(b, size_b);
    double c = 0.0;
    for(int i = 0; i < size_a; i++){
        c = (double)(a[i] - ava_a) * (double)(b[i] - ava_b)
            / sqrt((double)(fabs(a[i]-ava_a))) * sqrt((double)(fabs(b[i] - ava_b))); 

        printf("c is -->>>%f\n", c);
    }
    */


}
