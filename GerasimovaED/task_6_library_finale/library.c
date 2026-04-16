#define _CRT_SECURE_NO_WARNINGS

#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int author_counter(char author_name[], int cnt, BOOK _lib[], int* au_cnt) {
	int i;
	for (i = 0; i < cnt; i++) if (strstr(_lib[i].author, author_name) != NULL) (*au_cnt)++;
	if (au_cnt == 0) {
		printf("BOOKS NOT FOUND\n");
	}
}

void author_finder(char author_name[], int cnt, BOOK _lib[], int au_cnt, BOOK au_lib[]) {
	int i, j = 0;
	for (i = 0; i < cnt; i++) {
		if ((strstr(_lib[i].author, author_name) != NULL)) {
			au_lib[j].author = (char*)malloc((strlen(_lib[i].author) + 1) * sizeof(char));
			au_lib[j].name = (char*)malloc((strlen(_lib[i].name) + 1) * sizeof(char));
			au_lib[j].publishing = (char*)malloc((strlen(_lib[i].publishing) + 1) * sizeof(char));
			strcpy(au_lib[j].author, _lib[i].author);
			strcpy(au_lib[j].name, _lib[i].name);
			strcpy(au_lib[j].publishing, _lib[i].publishing);
			au_lib[j].year = _lib[i].year;
			j++;
		}
	}
	return;
}

void free_arrays(int cnt, int au_cnt, BOOK _lib[], BOOK au_lib[]) {
	int i;
	for (i = 0; i < cnt; i++) {
		free(_lib[i].author);
		free(_lib[i].name);
		free(_lib[i].publishing);
	}
	for (i = 0; i < au_cnt; i++) {
		free(au_lib[i].author);
		free(au_lib[i].name);
		free(au_lib[i].publishing);
	}
	free(_lib);
	free(au_lib);
	return;
}