#include "auxiliary.h"
#include "library.h"

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int books_r(int* lines) {
	char buff[BUFFER_SIZE];
	FILE* fp = fopen("in.txt", "r");

	if (fp == NULL) {
		printf("ERROR!\nProbably, the library is empty.\n\n");
		return 1;
	}

	while (fgets(buff, BUFFER_SIZE, fp) != NULL) { //counting rows
		(*lines)++;
	}
	return 0;
}

int put_books_into_array(int* lines, BOOK* library) {

	return 0;
}