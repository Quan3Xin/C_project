#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA 820
#define IN 2
#define OUT 1
#define NEURON 45
#define TRANIC 5500
#define A  0.2
#define B  0.4
#define a  0.2
#define b  0.3



double d_in[DATA][IN],d_out[DATA][OUT];
double w[NEURON][IN],o[NEURON],v[OUT][NEURON];
double max_in[IN],min_in[IN],max_out[OUT],min_out[OUT];
double out_put_data[OUT];
double dv[OUT][NEURON],dw[NEURON][IN];
double e;


void computO(int var);
void backUpdate(int var);

void initBPNetwork()
{

    int i, j;
    for(i = 0; i < IN; i++){
        min_in[i] = max_in[i] = d_in[0][i];
        for(j = 0; j < DATA; j++){
            max_in[i] = max_in[i] > d_in[j][i] ? max_in[i] : d_in[j][i];
            min_in[i] = min_in[i] < d_in[j][i] ? min_in[i] : d_in[j][i];
        }
    }
    // 归一化处理
    for(i = 0; i < OUT; i++){
       min_out[i] = max_out[i] = d_out[0][i];
       for(j=0; j < DATA; j++){
            max_out[i] = max_out[i] > d_out[j][i] ? max_out[i] : d_out[j][i];
            min_out[i] = max_in[i] < d_out[j][i] ? min_out[i] : d_out[j][i];
       }
    }

    for(i = 0; i < IN; i++){
        for(j = 0; j < DATA; j++){
           d_in[j][i] = (d_in[j][i] - min_in[i] - 1)/ (max_in[i] - min_in[i] +1 );
        }
    }
    for(i = 0; i < OUT; i++){
        for(j = 0; j < OUT; j++){
           d_out[j][i] = (d_out[j][i] - min_out[i] - 1)/ (max_out[i] - min_out[i] + 1);
        }
    }
    // 初始化神经元
    
    for(i = 0; i < NEURON; ++i){
        for(j = 0; j < OUT; j++){
            v[j][i] = (rand() * 2.0 /RAND_MAX -1) /2;
            dv[j][i] = 0;
        }
    }

}
double result(double var1, double var2)
{
    int i, j;
    double sum;
    var1 =(var1 - min_in[0]+1) / (max_in[0] - min_in[0] +1);
    var2 =(var2 - min_in[1]+1) / (max_in[1] - min_in[1] +1);
    for(i = 0; i < NEURON; ++i){
        sum = 0;
        sum = w[i][0] * var1 + w[i][1] * var2;
        o[i] = 1 / (1 + exp(-1*sum));
    
    }
    sum = 0;
    for(j = 0; j < NEURON; ++j){
       sum += v[0][j] * o[j]; 
    }
    return sum *(max_out[0] - min_out[0] +1) + min_out[0] -1;
    
}
void trainNetwork()
{
    int i, c= 0;
    int e;
    do{
        e = 0;
        for(i = 0; i < DATA; ++i){
           computO(i);
           e += fabs((out_put_data[0]- d_out[0][i]) / d_out[i][0]);
           backUpdate(i);
        }
        c++;
    } while(c < TRANIC && e / DATA > 0.01);
}
void computO(int var)
{
    int i, j;
    double sum;
    double v[OUT][NEURON];
    double w[NEURON][IN];
    

    for(i = 0; i < NEURON; i++){
        sum = 0;
        for(j = 0; j < IN; ++j){
            sum += w[i][j]*d_in[var][j];
        }
    }
    for(i = 0; i < OUT; ++i){
    
        sum = 0;
        for(j = 0; j < NEURON; ++j){
            sum += v[i][j] * o[j];
            out_put_data[i] = sum;
        }
    }
}
void backUpdate(int var)
{
    int i, j;
    double t;
    double v[OUT][NEURON];
    double w[NEURON][IN];
    double dw[NEURON][IN];
    for(i = 0; i < NEURON; ++i){
        t = 0;
        for(j = 0; j < OUT; ++j){
            t += (out_put_data[j] - d_out[var][j]) * v[j][i];
        }
    
    }
    for(j = 0; j < IN; ++j){
        dw[i][j] = a * dw[i][j] + b * t * o[i]* (1-o[i]) *d_in[var][j];
        w[i][j] -= dw[i][j];
    }
}
