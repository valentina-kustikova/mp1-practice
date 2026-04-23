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

	library = (BOOK*)malloc(lines * sizeof(BOOK));

	printf("Input the surname >> ");
	scanf_s("%20s", &needed_author, sizeof(needed_author));

	put_books_into_array(lines, filename, library);
	find_authors_books(needed_author, lines, library, &found_cnt, &found_books);
	print_books(found_cnt, found_books, needed_author);

	free_lib(found_books, found_cnt);
	free_lib(library, lines);
	return 0;
}