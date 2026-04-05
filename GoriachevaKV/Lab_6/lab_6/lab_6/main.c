#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

int main() {
	int lines = 0;
	int err = 0;

	char s[100] = "author1;name1;publishment1;2001";
	char delimiter[1] = ";";
	char* a, b, c, d;
	a = strtok(s, delimiter);
	b = strtok(0, delimiter);
	c = strtok(0, delimiter);
	d = strtok(0, delimiter);

	BOOK book_1;
	book_1.author = (char*)malloc((strlen(a) + 1) * sizeof(char));
	strcpy(book_1.author, a);
	printf("%s\n\n", book_1.author);
	free(book_1.author);

	err = books_r(&lines);
	if (err == 1) return 1;
	else {
		printf("Lines count: %d\n\n", lines);
	}

	//BOOK* library = NULL;

	return 0;
}