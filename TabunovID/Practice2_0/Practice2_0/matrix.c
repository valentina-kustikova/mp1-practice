#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void allocate_matrix(TMatrix** matrix, int n) {
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
	(*matrix)->n = n;
	(*matrix)->x = (float*)malloc(sizeof(float) * n * n);
}

void fill_matrix(TMatrix* matrix) {
	int i, j;
	for (i = 0; i < matrix->n; i++) {
		for (j = 0; j < matrix->n; j++) {
			scanf("%f", &(matrix->x[i * matrix->n + j]));
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