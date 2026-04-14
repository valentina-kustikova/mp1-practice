#define _CRT_SECURE_NO_WARNINGS

#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void author_finder(char* author_name, int* au_cnt, BOOK** au_lib, int cnt, BOOK* _lib) {
	int i, j = 0;
	for (i = 0; i < cnt; i++) if (strstr(_lib[i].author, author_name) != NULL) (*au_cnt)++;
	*au_lib = (BOOK*)malloc(*au_cnt * sizeof(BOOK));
	for (i = 0; i < cnt; i++) {
		if ((strstr(_lib[i].author, author_name) != NULL)) {
			(*au_lib)[j].author = (char*)malloc((strlen(_lib[i].author) + 1) * sizeof(char));
			(*au_lib)[j].name = (char*)malloc((strlen(_lib[i].name) + 1) * sizeof(char));
			(*au_lib)[j].publishing = (char*)malloc((strlen(_lib[i].publishing) + 1) * sizeof(char));
			strcpy((*au_lib)[j].author, _lib[i].author);
			strcpy((*au_lib)[j].name, _lib[i].name);
			strcpy((*au_lib)[j].publishing, _lib[i].publishing);
			(*au_lib)[j].year = _lib[i].year;
			j++;
		}
	}

	return;
}