#include "auxilary.h"
#include "library.h"
#include <stdio.h>
#include <string.h>

int getrange(FILE* file) {
	int a = 0;
	char str[100];
	while (fgets(str, 100, file) != NULL) {
		a++;
	}
	rewind(file);
	return a;
}

void loadbooks(FILE *file, Fbooks *books) {
	int i = 0;
	char tmp[1000];
	rewind(file);
	for (i = 0; i < books->len; i++) {
		fgets(tmp, 999, file);
		strcpy(books->books[i].authors, strtok(tmp, ":"));
		strcpy(books->books[i].name, strtok(NULL, ":"));
		strcpy(books->books[i].publisher, strtok(NULL, ":"));
		if (sscanf(strtok(NULL, ":"), "%d", &books->books[i].year) != 1) {
			printf("error");
		}
	}
}

