#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int s[][10] = {{3,3,3,3,3,3},{123,23,12,4,124,12,312,4}};
    for(int i=0; i<2;i++){
        for(int j=0; j<9;j++){
            printf("vector is ->.%d\n",s[i][j]);
        }
    }

    int i,j,k;
    double a[3][3],b[3][3],c[3][3];

    for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                    printf("Enter the number in a[%d][%d]\n",i,j);
                    scanf("%lf",&a[i][j]);
            }
    }

    for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                    c[i][j]=0;
                    for(k=0;k<3;k++){
                            c[i][j]=a[i][k]*b[k][j]+c[i][j];
                    }
            }
    }
    
    return 0;
}
