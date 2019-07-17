#include <stdio.h>
#include <math.h>


double ave(double a[],int n)
 {
   int sum=0;
   for (int i=0;i<n;i++)
       sum+=a[i];
   return sum/n;
 }

double standardDeviation(double a[], int n, double ave)
{
    double spow = 0;
    for(int i = 0; i<n; i++){
        spow += (a[i] - ave) * (a[i] - ave);
    } 
    return sqrt(spow / n);
}

int main()
{

}
