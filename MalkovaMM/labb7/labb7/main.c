#include <stdio.h>
#include <stdlib.h>
#include "pol.h"
#include <locale.h>

int main(int argc, char** argv) {
	char* fname;
	int* coeff;
	int deg;
	setlocale(LC_ALL, "Rus");
	if (argc < 2) {
		printf("Incorrect parametres");
		return 1;
	}
	fname = argv[1];
	deg = degpol(fname);
	printf("%d", deg);
	return 0;
}