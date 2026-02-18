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
	book* books = (book*)malloc(sizeof(book * n));
}