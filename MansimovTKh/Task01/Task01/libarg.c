#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libarg.h"

void find_books(const char* author_surname, book_info** found_books, book_info* books, int lines, int* found) {
	int j, index = 0;
	*found = 0;
	for (j = 0; j < lines; j++) {
		if (strstr(books[j].authors, author_surname) != NULL) {
			(*found)++;
		}
	}
	if ((*found) == 0) {
		printf("No works found for author: %s\n", author_surname);
		*found_books = NULL;
		return;
	}
	(*found_books) = (book_info*)malloc(sizeof(book_info) * (*found));
	if ((*found_books) == NULL) {
		printf("Error of memory allocation\n\n");
		return;
	}

	for (j = 0; j < lines; j++) {
		if ((strstr(books[j].authors, author_surname)) != NULL) {

			(*found_books)[index].authors = (char*)malloc(sizeof(char) * (strlen(books[j].authors) + 1));
			strcpy((*found_books)[index].authors, books[j].authors);

			(*found_books)[index].title = (char*)malloc(sizeof(char) * (strlen(books[j].title) + 1));
			strcpy((*found_books)[index].title, books[j].title);

			(*found_books)[index].publisher = (char*)malloc(sizeof(char) * (strlen(books[j].publisher) + 1));
			strcpy((*found_books)[index].publisher, books[j].publisher);

			(*found_books)[index].year = books[j].year;
			index++;

		}
	}

}