#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void allocate_matrix(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n*n;
	(*matrix)->x = (int*)malloc(sizeof(int) * n * n);
}

void fill_matrix(TMatrix* matrix, int n)
{
	int i = 0;
	for (; i < n; i++) {
		int j = 0;
		for (; j < n; j++) {
			scanf("%d", &(matrix->x[i * n + j]));
		}
	}
	printf("\n");
}

void print_matrix(TMatrix* matrix, int n)
{
	int j = 0;
	for (; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d ", matrix->x[j * n + i]);
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2, int n)
{
	TMatrix* res;
	int i = 0;
	allocate_matrix(&res, n);
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

TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2, int n)
{
	TMatrix* res;
	int count = 0, k = 0, l = 0;
	allocate_matrix(&res, matrix1->n);
	while (count < matrix1->n)
	{
		int i = 0, j = 0, flag = 0;
		while (flag < n)
		{
			res->x[count] += matrix1->x[k * n + i++] * matrix2->x[j++ * n + l];   //i dont know why it isnt working
			flag++;
		}
		k++;
		l++;
		count++;
	}
	return res;
}