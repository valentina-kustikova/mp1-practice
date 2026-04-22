#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void author_counter(char* author_name, int cnt, BOOK* _lib, int* au_cnt) {
	int i;
	for (i = 0; i < cnt; i++) if (strstr(_lib[i].author, author_name) != NULL) (*au_cnt)++;
	if (au_cnt == 0) {
		printf("BOOKS NOT FOUND\n");
	}
	return;
}

void author_finder(char* author_name, int cnt, BOOK* _lib, int au_cnt, BOOK* au_lib) {
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

void free_array(int cnt, BOOK* arr) {
	int i;
	for (i = 0; i < cnt; i++) {
		free(arr[i].author);
		free(arr[i].name);
		free(arr[i].publishing);
	}
	free(arr);
	return;
}