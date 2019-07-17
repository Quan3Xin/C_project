#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    double *p = (double*)malloc(10);
    
    if (p == NULL) { 
      printf("Memory not allocated.\n"); 
      exit(0); 
    } 
    int i = 0;
    for(i=0; i < 1000;i++){
        *(p+i) = i;
        printf("p is ->>>.%f\n", p[i]);
    }
    free(p);
    return 0;
}
