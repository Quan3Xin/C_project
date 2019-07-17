#include <stdio.h>
#include <stdlib.h>

#define __CRT_SECURE_NO_ WARNINGS

#define NOA 10
#define  ILIMIT 50 

#define Q 3
#define RHO 0.8
#define SETP 10
#define SEED 32768
#define EPSILON 0.15


void printp(double phermone[2][SETP]);
void walk(int cost[2][SETP], double pheromone[2][SETP], int mstep[NOA][SETP]);
void update(int cost[2][SETP], double pheromone[2][SETP], int mstep[NOA][SETP]);
double round01();



int main()
{
    int cost[2][SETP] = {
        {1,8,1,1,2,1,3},
        {5,5,5,2,9,5,5}};
    
    
        for(int j=0; j < 7;j++){
            printf("while, costs[%d, %d]\n", cost[0][j], cost[1][j+1]);
    }
    
    return 0;
}

void update(int cost[2][SETP], double pheromone[2][SETP], int mstep[NOA][SETP])
{
    int m;
    int lm;
    int i, j;
    double sum_lm = 0;
    for(i = 0; i< 2; ++i){
        for(j=0; j < SETP; ++j){
            pheromone[i][j] *= RHO;
        }
    }
    for(m=0; m < NOA; ++m){
        lm=0;
        for(i=0; i<SETP; i++){
            lm += cost[mstep[m][i]][j];
        }
        for(i=0; i< SETP; i++){
            pheromone[mstep[m][i]][i] += Q * (1.0 / lm);
        }
        sum_lm += lm;
    }
    printf("%1F\n", sum_lm);
}
