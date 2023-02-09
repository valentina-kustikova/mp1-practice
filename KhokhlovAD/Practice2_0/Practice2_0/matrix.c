#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void allocate_matrix(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 10);
	(*matrix)->n = n*n;
	(*matrix)->x = (int*)malloc(sizeof(int) * n);
}

void fill_matrix(TMatrix* matrix)
{
	int i = 0;
	for (i = 0; i < matrix->n; i++);
	{
		scanf("%d", &(matrix->x[i]));
	}
}

void print_matrix(TMatrix* matrix, int n)
{
	int i = 0;
	for (; i < matrix->n; i++)
	{
		if (i % n == 0)
			printf("\n");
		printf("%d", matrix->x[i]);
		
	}
	printf("\n");
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
	TMatrix* res;
	int i = 0;
	allocate_matrix(&res, matrix1->n);
	for (; i < res->n; i++)
	{
		res->x[i] = matrix1->x[i] + matrix2->x[i];
	}
	return res;
}

TMatrix* add_const(TMatrix* matrix, int n)
{
	TMatrix* res;
	int i = 0;
	allocate_matrix(&res, matrix->n);
	for (; i < res->n; i++)
	{
		res->x[i] = matrix->x[i] + n;
	}
	return res;
}

TMatrix* multi_const(TMatrix* matrix, int n)
{
	TMatrix* res;
	int i = 0;
	allocate_matrix(&res, matrix->n);
	for (; i < res->n; i++)
	{
		res->x[i] = matrix->x[i] * n;
	}
	return res;
}

TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
	TMatrix* res;
	int i = 0, j = 0;
	allocate_matrix(&res, matrix1->n);
	for (; i < res->n; i++)
	{
		for (; j < res->n; j++)
		{

		}
	}
	return res;
}