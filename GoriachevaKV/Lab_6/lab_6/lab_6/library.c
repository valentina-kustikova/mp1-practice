#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "library.h"

void find_authors_books(int* found_cnt, int lines, BOOK* library, BOOK** found_books, char* needed_author) {
	int i, j = 0;
	for (i = 0; i < lines; i++) {
		if (strstr(library[i].authors, needed_author) != NULL) {
			(*found_cnt)++;
		}
	}

	(*found_books) = (BOOK*)malloc((*found_cnt) * sizeof(BOOK));
	for (i = 0; i < lines; i++) {
		if ((strstr(library[i].authors, needed_author) != NULL)) {
			(*found_books)[j].authors = (char*)malloc((strlen(library[i].authors) + 1) * sizeof(char));
			(*found_books)[j].name = (char*)malloc((strlen(library[i].name) + 1) * sizeof(char));
			(*found_books)[j].publishing = (char*)malloc((strlen(library[i].publishing) + 1) * sizeof(char));

			strcpy((*found_books)[j].authors, library[i].authors);
			strcpy((*found_books)[j].name, library[i].name);
			strcpy((*found_books)[j].publishing, library[i].publishing);
			(*found_books)[j].publishing_year = library[i].publishing_year;
			j++;
		}
	}
}