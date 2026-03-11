#include <string.h>
#include <stdlib.h>
#include "library.h"

//реализация самого поиска

void searching(Book* masbook, int count_book, const char* author, Book** search, int* countAuthorBooks) {
	int kol = 0;
	int i, j;
	*countAuthorBooks = 0;
	for (i = 0; i < count_book; i++) {
		if (strstr(masbook[i].author, author) != NULL) {
			(*countAuthorBooks)++;
		}
	}
	if (*countAuthorBooks == 0) {
		*search = NULL;
		return;
	}
	*search = (Book*)malloc((*countAuthorBooks) * sizeof(Book));
	for (j = 0; j < count_book; j++) {
		if (strstr(masbook[j].author, author) != NULL) {
			strcpy((*search)[kol].author, masbook[j].author);
			strcpy((*search)[kol].name, masbook[j].name);
			strcpy((*search)[kol].publish, masbook[j].publish);
			(*search)[kol].year = masbook[j].year;
			kol++;

		}
	}
}
