#include<stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct {

	int rows;
	int cols;
	double **data;
} Matrix;

Matrix alloc_matrix(int rows, int cols)
{

	Matrix m;
	int i, j;
	m.cols = cols;
	m.rows = rows;
	m.data = (double **)malloc(sizeof(double*) * m.rows);
	for(i = 0; i < m.rows; ++i){
		m.data[i] = (double*) malloc(sizeof(double) * m.cols);
		assert(m.data[i]);
		for(j = 0; j < m.cols; ++j){
			m.data[i][j] = 0.0;
		}
	}
	return m;
}

void free_matrix(Matrix m)
{
	int i;
	assert(m.data != NULL);
	for( i = 0; i < m.rows; ++i){
		free(m.data[i]);
	}
	free(m.data);
}

