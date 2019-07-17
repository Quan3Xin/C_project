#include <math.h>
#include <unistd.h>
#include <stdio.h>

#define FILENAME "data.txt"

int sum(int a, int b);
int main()
{
    printf("hello\n");
    int count = 0;
    double x, y, first, last, sumx=0, sumx2=0, sumy=0,
           sumxy=0, denominator, m ,b;
    
    FILE *data;
    data = fopen(FILENAME, "r");
    if(data == NULL){
        printf("read data file error.   \n ");
        _exit(0);
    } else{
        fprintf(data, "data is=>>");
        while((fscanf(data, "%1lf %1lf", &x, &y)) == 2)
        {
            ++count;
            if(count == 1){ first = x;}
            sumx += x;
            sumy += y;
            sumx2 += x*x;
            sumxy += x*y;
        }
        last = x;
        denominator =  sumx*sumx - count * sumx2;
        m = (sumx * sumy- count* sumxy) / denominator;
        b = (sumx * sumxy - sumx2 * sumy) /denominator;
        printf("Range of altitudes in k:\n");
        printf("%0.2f to %.2f\n\n", first, last);
        printf("Linear model: \n");
        printf("ozone-mix-ratio = %.2f altitude + %.2f\n", m, b);
        fclose(data);

    }
    return 0;

}
