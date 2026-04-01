#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

int main() {
	int lines = 0;
	int err = 0, i;

	err = books_r(&lines);
	if (err == 1) return 1;
	else {
		printf("Lines count: %d", lines);
	}

	BOOK* library = (BOOK*)malloc(lines * sizeof(BOOK));

	free(library);

	return 0;
}