#include <string.h>
#include "library.h"
int searching(struct Book* library, int count, const char* author, struct Book* found_books) {
	int i, k = 0;
	for (i = 0; i < count; i++) {
		if (_stricmp(author, library[i].author) == 0) {
			found_books[k] = library[i];
			k++;
		}
	}
	return k;
}