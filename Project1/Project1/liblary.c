#include <string.h>
#include <stdlib.h>
#include "liblary.h"
void searching(struct Book* array, int count, const char* author, struct Book** search, int *countAuthorBooks) {
	int k = 0, i, j;
	*countAuthorBooks = 0;
	for (i = 0; i < count; i++) {
		if (strcmp(author, array[i].author) == 0) {
			(*countAuthorBooks)++;	
		}
	}
	*search = (struct Book*)malloc((*countAuthorBooks) * sizeof(struct Book));
	for (j = 0; j < count; j++) {
		if (strcmp(author, array[j].author) == 0) {
			(*search)[k++] = array[j];
		}
	}
}

