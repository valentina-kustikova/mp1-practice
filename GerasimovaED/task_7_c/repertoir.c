#define _CRT_SECURE_NO_WARNINGS

#include "repertoir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int director_counter(char director_name[], int cnt, FILM _rep[], int* dir_cnt) {
	int i;
	for (i = 0; i < cnt; i++) if (strstr(_rep[i].director, director_name) != NULL) (*dir_cnt)++;
	if (dir_cnt == 0) {
		printf("FILMS NOT FOUND\n");
	}
}

void director_finder(char director_name[], int cnt, FILM _rep[], int dir_cnt, FILM dir_rep[]) {
	int i, j = 0;
	for (i = 0; i < cnt; i++) {
		if ((strstr(_rep[i].director, director_name) != NULL)) {
			dir_rep[j].name = (char*)malloc((strlen(_rep[i].name) + 1) * sizeof(char));
			dir_rep[j].director = (char*)malloc((strlen(_rep[i].director) + 1) * sizeof(char));
			dir_rep[j].country = (char*)malloc((strlen(_rep[i].country) + 1) * sizeof(char));
			strcpy(dir_rep[j].name, _rep[i].name);
			strcpy(dir_rep[j].director, _rep[i].director);
			strcpy(dir_rep[j].country, _rep[i].country);
			dir_rep[j].year = _rep[i].year;
			dir_rep[j].budget = _rep[i].budget;
			dir_rep[j].fees = _rep[i].fees;
			j++;
		}
	}
	return;
}

void free_arrays(int cnt, int dir_cnt, FILM _rep[], FILM dir_rep[]) {
	int i;
	for (i = 0; i < cnt; i++) {
		free(_rep[i].name);
		free(_rep[i].director);
		free(_rep[i].country);
	}
	for (i = 0; i < dir_cnt; i++) {
		free(dir_rep[i].name);
		free(dir_rep[i].director);
		free(dir_rep[i].country);
	}
	free(_rep);
	free(dir_rep);
	return;
}