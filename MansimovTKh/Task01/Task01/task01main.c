#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "libarg.h"

#define BUFFER_SIZE 1024
#define SURNAME_SIZE 30

int main(int argc, char **argv) {
	int lines=0, i, found;
	book_info* books=NULL;
	book_info* found_books = NULL;
	char author_surname[SURNAME_SIZE]; 

	if (argc < 2) {
		printf("Incorrect number of arguments\n"); return 1;
	}
	printf("%d %s %s\n\n", argc, argv[0], argv[1]);

	read_library(argv[1], &books, &lines); // todo: args

	printf("Enter the surname of the author whose works you want to view : ");
	scanf("%s", author_surname);

	printf("Searching for author: %s ...\n\n", author_surname);
	find_books(author_surname, &found_books, books, lines, &found);

	if (found != 0) print_found_books(found_books, found);

	for (i = 0; i < lines; i++) {
		free(books[i].authors);
		free(books[i].title);
		free(books[i].publisher);
	}

	if (found_books != NULL) {
		for (int i = 0; i < found; i++) {
			free(found_books[i].authors);
			free(found_books[i].title);
			free(found_books[i].publisher);
		}
		free(found_books);
	}

	free(books);
	return 0;
}




