#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <stdbool.h>

book* search(char* author, book* lib, int n, int* cnt) {
	int i, k, j;
	*cnt = 0;
	bool* flags = (bool*)malloc(n * sizeof(bool));
	book* result;
	for (i = 0; i < n; i++) {
		flags[i] = false;
		for (j = 0; j < lib[i].cnt_aut; j++) {
			if (strcmp(lib[i].authors[j], author) == 0) {
				flags[i] = true;
				(*cnt)++;
				break;
			}
		}	
	}
	j = 0;
	if (*cnt == 0) return NULL;
	result = (book*)malloc(*cnt * sizeof(book));
	for (i = 0; i < n; i++) {
		if (flags[i] == true) {
			result[j++] = lib[i];
		}
	}
	free(flags);
	return result;
}

