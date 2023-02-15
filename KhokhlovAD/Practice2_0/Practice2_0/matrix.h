#ifndef _MATRIX_H
#define _MATRIX_H


typedef struct
{
	int* x;
	int n;    //number of elements in a column
} TMatrix;

void allocate_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);

void fill_matrix(TMatrix* matrix, int n);
void print_matrix(TMatrix* matrix, int n);

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2, int n);
TMatrix* add_const(TMatrix* matrix, int n);
TMatrix* multi_const(TMatrix* matrix, int n);
TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2, int n);
#endif 
