#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxli.h"

int main(int argc, char** argv) {
	char author[100], * filename;
	int count_book, countAuthorBooks;
	if (argc < 2) {
		printf("incorrect number of argc");
		return 1;
	}
	filename = argv[1];

	count_book = countingBooks(filename);
	Book* mas_book = (Book*)malloc(count_book * sizeof(Book));
	readFile(count_book, mas_book, filename);

	printf("\nEnter the author\n");
	scanf("%[^\n]", author);

	Book* search;
	searching(mas_book, count_book, author, &search, &countAuthorBooks);
	printRes(search, countAuthorBooks);

	free(mas_book);
	free(search);

	return 0;
}
