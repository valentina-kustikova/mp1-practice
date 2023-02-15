#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	TMatrix* m1, *m2, *res;
	int n;

	printf("enter matrix size\t");
	scanf("%d", &n);

	printf("enter the elements of the first matrix\n");
	allocate_matrix(&m1, n);
	fill_matrix(m1, n);
	print_matrix(m1, n);

	printf("enter the elements of the second matrix\n");
	allocate_matrix(&m2, n);
	fill_matrix(m2, n);
	print_matrix(m2, n);

	res = add_matrix(m1, m2, n);
	printf("add_matrix result:\n");
	print_matrix(res, n);
	free_matrix(&res);

	res = add_const(m1, 2);
	printf("add_const result:\n");
	print_matrix(res, n);
	free_matrix(&res);

	res = multi_const(m1, 2);
	printf("multi_const result:\n");
	print_matrix(res, n);
	free_matrix(&res);

	res = multi_matrix(m1, m2, n);
	printf("multi_matrix result:\n");
	print_matrix(res, n);
	free_matrix(&res);

	free_matrix(&m1);
	free_matrix(&m2);
	return 0;
}