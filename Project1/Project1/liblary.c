#include <string.h>
#include <stdlib.h>
#include "liblary.h"
void searching(Book* array, int count, const char* author, Book** search, int *countAuthorBooks) {
	int k = 0, i, j;
	*countAuthorBooks = 0;
	for (i = 0; i < count; i++) {
		if (strstr(array[i].author, author) != NULL) {
			(*countAuthorBooks)++;	
		}
	}
	if (*countAuthorBooks == 0) {
		*search = NULL;
		return;
	}
	*search = (Book*)malloc((*countAuthorBooks) * sizeof(Book));
	for (j = 0; j < count; j++) {
		if (strstr(array[j].author, author) != NULL) {
			(*search)[k++] = array[j];
		}
	}
}

