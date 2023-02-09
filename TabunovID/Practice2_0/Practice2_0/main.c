#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	int i, j;
	TMatrix matrix;
	TMatrix* matrix_dynamic, * m1, * m2, * res;


	int		  n = 3;
	float	add = 5.5f;
	float multi = 2.0f;

	allocate_matrix(&m1, n);
	allocate_matrix(&m2, n);
	fill_matrix(m1); // 1 2 3 4 5 6 7 8 9
	fill_matrix(m2); // 9 8 7 6 5 4 3 2 1
	print_matrix(m1);
	print_matrix(m2);

	printf("add_matrix:\n");
	res = add_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("add_const:\n");
	res = add_const(m1, add);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_matrix:\n");
	res = multi_matrix(m1, m2);
	print_matrix(res);
	free_matrix(&res);

	printf("multi_const:\n");
	res = multi_const(m1, multi);
	print_matrix(res);
	free_matrix(&res);

	free_matrix(&m1);
	free_matrix(&m2);


	return 0;
}