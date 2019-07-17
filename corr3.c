# include <stdio.h>
# include <math.h>
#include <stdlib.h>
#include <string.h>


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
void read_csv(int row, int col, char *filename, double **data){
	FILE *file;
	file = fopen(filename, "r");
    char *datas;
	int i = 0;
    char line[4098];
	while ((datas = fgets(line, 4098, file)) && (i < row)) {
    	// double row[ssParams->nreal + 1];
        char* tmp = strtok(datas, ",");
        printf("tmp is 00>>>%d\n", tmp[0]);

	    printf("\n");

        free(tmp);
        i++;
    }
}

float differences(float *a, int n, float *b)
{
    int c;
    for(c = 0; c < n -1 ; c++) {
        b[c] = a[c+1]- a[c];
    }

    
   // int size_v = sizeof(b) / sizeof(b[0]);
   // printf("size of -->>b%d\n", size_v);
}
void residual(float *a, int n, float * b)
{
   for(int i =0 ; i < n; i++){
        b[i] = a[i] - ave(a, n);
   } 
}
void reslut3(float * a, int size_a, float standard_y[size_a])
{
    float resdual_v[size_a];
    float ave_data = ave(a, size_a);
    float deviation_s = calculateSD(a, size_a);
    for(int i =0 ; i < size_a; i++) {
        if(deviation_s == 0) {
            resdual_v[i] = a[i] - ave_data;
            standard_y[i] = 0;
        } else {
            resdual_v[i] = a[i] - ave_data;
            standard_y[i] = fabs(resdual_v[i]) / deviation_s; 
        }
    } 
}
int main( int argc, char const * argv[])
{
    //int i;
    //float a[] = {1, 9, 2, 139, 6, 7, 
    //    277, 23,1,32,34,1,32,4,12,31,22,4,
    //    23,23,4,12,31,22,4,23,234,12,31,22,4,23,234,12,31,22,4,23,234,12,31,22,4,23,23};
    //
    int row = atoi(argv[1]);
    int col = atoi(argv[2]);
    printf("col is-->>%d\n", col);
    char fname[20] = "02.csv";
    double * *data;
    data = (double **)malloc(row * sizeof(double *));
    for(int i = 0; i < row; i++){
        data[i] = (double *)malloc(col * sizeof(double));
    }
    read_csv(row, col, fname, data);

    float a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    //float c[] = {1, 9, 2, 139, 6, 7, 277};
    
    int size_a = sizeof(a) / sizeof(a[0]);
    float b[size_a - 1];
    differences(a, size_a, b);

    int size = sizeof(a) / sizeof(a[0]);
    float standard_y[size];
    reslut3(b, size, standard_y);


    float threshold = 2;
    

    int ab = 2; 
    for(int i = 0; i < size -2; i ++) {
        printf("standard_y is -> %0.2f\n", standard_y[i]);
       if(standard_y[i] < threshold) {
            ab += 1;
       } else if (standard_y[i + 1] < threshold ) {
            ab += 1;
       } 
    }
    
    float arr[size_a];
    arr[0] = a[0];


    int i = 1;
    int j = 1;
    while( i <  size_a - 1) {
       if(standard_y[i -1] < threshold) {
            arr[j] = a[i];
            i+=1;
            j+= 1;
       } else if (standard_y[i] < threshold ) {
           arr[j] = a[i];
            i+=1;
            j+= 1;
       } else {
            i += 1;
       }
    }
    arr[ab -1 ] = a[size_a -1];

    for(int i = 0; i < ab; i++) {
        printf("arr number is -> %0.2f\n", arr[i]);
    }
    /*
    
    //int ab = 0; 
    //for(int i = 0; i < size_a; i++){
    //    if (standard_y[i] < threshold) {
    //        ab +=1;
    //       arr[i] = a[i];
    //    }
    //    printf("the new data is -> %0.2f\n",arr[i]);
    //    
    //}
    //printf("threshold is -->>%d\n",ab);
    //free(arr);
    //v = differences(a, size_a);
     
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
