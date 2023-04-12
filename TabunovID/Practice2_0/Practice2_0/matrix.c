#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#define _CRT_SECURE_NO_WARNINGS

void allocate_matrix(TMatrix** matrix, int n) {
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->x = (float*)malloc(sizeof(float) * n * n);
}

void fill_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			scanf_s("%f", &(matrix->x[i * matrix->n + j]));
		}
	}
	printf("\n");
}

void print_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			printf("%.3f ", matrix->x[i * matrix->n + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void free_matrix(TMatrix** matrix) {
	free((*matrix)->x);
	free(*matrix);
}

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2) {
	TMatrix* res;
	int i, j;
	if (matrix1->n != matrix2->n) {
		printf("ERROR: Square matrixes should have the same lenght and height.\n");
		return NULL;
	}
	allocate_matrix(&res, matrix1->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = matrix1->x[i * res->n + j] + matrix2->x[i * res->n + j];
		}
	}
	return res;
}

TMatrix* add_const(TMatrix* matrix, float c) {
	TMatrix* res;
	int i, j;
	allocate_matrix(&res, matrix->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = matrix->x[i * res->n + j] + c;
		}
	}
	return res;
}

TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2) {
	TMatrix* res;
	int i, j, k;
	if (matrix1->n != matrix2->n) {
		printf("ERROR: Square matrixes should have the same lenght and height.\n");
		return NULL;
	}
	allocate_matrix(&res, matrix1->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = 0.0f;
			for (k = 0; k < res->n; k++) {
				res->x[i * res->n + j] += matrix1->x[i * res->n + k] * matrix2->x[k * res->n + j];
			}
		}
	}
	return res;
}

TMatrix* multi_const(TMatrix* matrix, float c) {
	TMatrix* res;
	int i, j;
	allocate_matrix(&res, matrix->n);
	for (i = 0; i < res->n; i++) {
		for (j = 0; j < res->n; j++) {
			res->x[i * res->n + j] = matrix->x[i * res->n + j] * c;
		}
	}
	return res;
}

void main_action() {
	TMatrix* matrix_dynamic, * m1, * m2, * res;

	int action = 0;
	int		  n;
	float	add;
	float multi;

	printf("n = ");
	scanf_s("%d", &n);

	allocate_matrix(&m1, n);
	allocate_matrix(&m2, n);
	printf("Enter 1st matrix:\n");
	fill_matrix(m1);
	printf("Enter 2nd matrix:\n");
	fill_matrix(m2);
	print_matrix(m1);
	print_matrix(m2);

	printf("what i have to do?\n");
	printf("choose an action: 1 - '+ add const', 2 - '+ add matrix', 3 - '* mylty const', 4 - '* multy matrix' \n");
	printf("action = ");
	scanf_s("%d", &action);



	if (action == 1) {
		printf("add = ");
		scanf_s("%f", &add);
		printf("add_const:\n");
		res = add_const(m1, add);
		print_matrix(res);
		free_matrix(&res);

		return 0;
	}
	else if (action == 2) {
		printf("add_matrix:\n");
		res = add_matrix(m1, m2);
		print_matrix(res);
		free_matrix(&res);
	}
	else if (action == 3) {
		printf("multi = ");
		scanf_s("%f", &multi);
		printf("multi_const:\n");
		res = multi_const(m1, multi);
		print_matrix(res);
		free_matrix(&res);
	}
	else if (action == 4) {
		printf("multi_matrix:\n");
		res = multi_matrix(m1, m2);
		print_matrix(res);
		free_matrix(&res);
	}
	else
	{
		printf("gg, start again");
		return 0;
		free_matrix(&m1);
		free_matrix(&m2);

	}
	free_matrix(&m1);
	free_matrix(&m2);
}