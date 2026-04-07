#include <string.h>
#include "library.h"
int searching(Book* library, int count, const char* author, Book* found_books) {
	int i, j, k = 0;
	for (i = 0; i < count; i++) {
		for (j = 0; j < library[i].authors_count; j++) {
			if (_stricmp(author, library[i].authors[j]) == 0) {
				found_books[k] = library[i];
				k++;
				break;
			}
		}
	}
	return k;
}

void free_library(Book* library, int count) {
	for (int i = 0; i < count; i++) {
		if (library[i].authors != NULL) {
			free(library[i].authors);
		}
	}
}