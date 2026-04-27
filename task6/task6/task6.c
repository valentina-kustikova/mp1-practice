#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"

int main(int argc, char *argv[]) {
	FILE* file;
	char aut[100];
	Fbooks libr;
	Fbooks finded;
	if (argc < 2) {
		printf("no args");
		return 1;
	}
	file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("no file");
		return 0;
	}
	libr.len = getrange(file);
	libr.books = (book*)malloc(sizeof(book) * libr.len);
	loadbooks(file, &libr);
	if (fgets(aut, sizeof(aut), stdin) == NULL) {
		printf("getting error");
		return 0;
	}
	finded = find(&libr, aut);
	printer(&finded);
	free(libr.books);
	free(finded.books);
	fclose(file);
	return 0;
}