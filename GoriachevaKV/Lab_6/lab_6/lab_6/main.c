#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "auxiliary.h"

#define SURNAME_MAX_LEN 21
#define FILENAME_MAX_LEN 101

int main() {
	int i, lines = 0, found_cnt = 0, error = 0;
	char needed_author[SURNAME_MAX_LEN];
	char filename[FILENAME_MAX_LEN];
	BOOK* library = NULL;
	BOOK* found_books = NULL;

	printf("Input the filename >> ");
	scanf_s("%100s", &filename, sizeof(filename));

	error = books_r(&lines, filename);
	if (error == 1) return 1;

	printf("Input the surname >> ");
	scanf_s("%20s", &needed_author, sizeof(needed_author));

	put_books_into_array(&lines, filename, &library);
	find_authors_books(&found_cnt, lines, library, &found_books, needed_author);
	print_books(found_cnt, found_books, needed_author);

	for (i = 0; i < found_cnt; i++) {
		free(found_books[i].authors);
		free(found_books[i].name);
		free(found_books[i].publishing);
	}

	for (i = 0; i < lines; i++) {
		free(library[i].authors);
		free(library[i].name);
		free(library[i].publishing);
	}
	free(found_books);
	free(library);
	return 0;
}