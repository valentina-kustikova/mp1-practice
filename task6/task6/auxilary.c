#include "auxilary.h"
#include "library.h"
#include <stdio.h>

int getrange(FILE* file) {
	int a = 0;
	char str[100];
	while (fgets(str, 100, file) != NULL) {
		a++;
	}
	return a;
}

book* loadbooks(FILE* file, int n) {
	int i = 0;
	book* books = (book*)malloc(sizeof(book) * n);
	for (i = 0; i < n; i++) {
		fscanf(file, "%39s;%19s;%19s;%d", books[i].autors, books[i].name, books[i].publisher, books[i].year);
	}
	return books;
}