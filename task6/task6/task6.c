#include <stdio.h>
#include <stdlib.h>
#include "auxilary.h"
#include "library.h"

int main(int argc, char *argv[]) {
	FILE* file;
	char aut[100];
	Fbooks tmp;
	if (argc < 2) {
		printf("no args");
		return 1;
	}
	file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("no file");
		return 0;
	}
	tmp.len = getrange(file);
	tmp.books = (book*)malloc(sizeof(book) * tmp.len);
	loadbooks(file, &tmp);
	if (fgets(aut, sizeof(aut), stdin) == NULL) {
		printf("getting error");
		return 0;
	}
	tmp = find(tmp.books, aut, tmp.len);
	printer(tmp);
	free(tmp.books);
	fclose(file);
	return 0;
}