#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "auxilary.h"
#include <stdbool.h>

book* search(char* author, book* lib, int n, int* cnt) {
	int i, k, j;
	*cnt = 0;
	bool* flags = (bool*)malloc(n * sizeof(bool));
	book* result;
	author[0] = toupper(author[0]);
	for (j = 1; j < strlen(author); j++) if (author[j - 1] == ' ') author[j] = toupper(author[j]);
	for (i = 0; i < n; i++) {
		flags[i] = false;
		for (j = 0; j < lib[i].cnt_aut; j++) {
			if (strstr(lib[i].authors[j], author)) {
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
			result[j].cnt_aut = lib[i].cnt_aut;
			result[j].authors = (char**)malloc(lib[i].cnt_aut * sizeof(char*));
			result[j].authors[0] = _strdup(lib[i].authors[0]);
			for (k = 1; k < lib[i].cnt_aut; k++) result[j].authors[k] = _strdup(lib[i].authors[k]);
			result[j].name = lib[i].name;
			result[j].publisher = lib[i].publisher;
			result[j].year = lib[i].year;
			j++;
		}
	}
	free(flags);
	return result;
}

