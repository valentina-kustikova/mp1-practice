#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxli.h"

int main(int argc, char** argv) {
	char author[MAX_LEN], *filename;
	int count_book, countAuthorBooks;
	Book* search;
	Book* mas_book;
	if (argc < 2) {
		printf("incorrect of argument");
		return 1;
	}
	filename = argv[1];

	count_book = countingBooks(filename);
	mas_book = (Book*)malloc(count_book * sizeof(Book));
	readFile(count_book, mas_book, filename);

	printf("\nEnter, please, the favorite author in stroka\n");
	scanf("%[^\n]", author);

	
	searching(mas_book, count_book, author, &search, &countAuthorBooks);
	printRes(search, countAuthorBooks);

	free(mas_book);
	free(search);

	return 0;
}
