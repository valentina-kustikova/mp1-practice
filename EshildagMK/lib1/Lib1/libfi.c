
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libfi.h"	


void searcher(book_info* books, int lines, const char* auth_name, book_info** found_books, int* found_count) {
	int i, j, kfound = 0;
	j = 0;
	for (i = 0; i < lines; i++) {
		if (strstr(books[i].author, auth_name) != NULL) {
			kfound++;
		}
	}
	if (kfound == 0) {
		*found_books = NULL;
		printf("Books not found\n");
		return;
	}
	(*found_books) = (book_info*)malloc(kfound * sizeof(book_info));
	for (i = 0; i < lines; i++) {
		if (strstr(books[i].author, auth_name) != NULL) {
			(*found_books)[j].author = malloc((strlen(books[i].author) + 1) * sizeof(char));
			(*found_books)[j].book_name = malloc((strlen(books[i].book_name) + 1) * sizeof(char));
			(*found_books)[j].publisher = malloc((strlen(books[i].publisher) + 1) * sizeof(char));

			if ((*found_books)[j].author && (*found_books)[j].book_name && (*found_books)[j].publisher) {
				strcpy((*found_books)[j].author, books[i].author);
				strcpy((*found_books)[j].book_name, books[i].book_name);
				strcpy((*found_books)[j].publisher, books[i].publisher);
				(*found_books)[j].book_year = books[i].book_year;
			}
			j++;
		}
	}
	*found_count = kfound;
}
