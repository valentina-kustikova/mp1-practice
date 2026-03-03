#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void search(BookData* array, int cnt,char* author, BookData** result, int* foundBooks) {
	int i;
	int k = 0;

	*foundBooks = 0;
	for (i = 0; i < cnt; i++) {
		if (strstr(array[i].author, author) != NULL) {
			(*foundBooks)++;

		}
	}

	if (*foundBooks == 0) {
		*result = NULL;
		return;
	}

	*result = (BookData*)malloc(*foundBooks * sizeof(BookData));
	
	for (i = 0; i < cnt; i++) {
		if (strstr(array[i].author, author) != NULL) {
			(*result)[k++] = array[i];
		}
	}
}