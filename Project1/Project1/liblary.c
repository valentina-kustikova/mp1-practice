#include <string.h>
#include "liblary.h"
int searching(struct Book* array, int count, const char* author[], struct Book* search) {
	int k = 0;
	for (int i = 0; i < count; i++) {
		if (strcmp(author, array[i].author) == 0) {
			search[k] = array[i];
			k++;
		}
	}
	return k;
}

