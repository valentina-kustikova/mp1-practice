#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	TMatrix matrix;
	TMatrix* m;
	allocate_matrix(&m, 2);
	fill_matrix(m);
	print_matrix(m, 2);
	free_matrix(m);
	return 0;
}