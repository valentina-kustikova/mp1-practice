#include "repertoir.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void director_counter(char* director_name, FilmLibrary* _rep, FilmLibrary* dir_rep) {
	int i;
	for (i = 0; i < _rep->cnt; i++) if (strstr(_rep->info[i].director, director_name) != NULL) (dir_rep->cnt)++;
	if (dir_rep->cnt == 0) {
		printf("FILMS NOT FOUND\n");
	}
	return;
}

void director_finder(char* director_name, FilmLibrary* _rep, FilmLibrary* dir_rep) {
	int i, j = 0;
	for (i = 0; i < _rep->cnt; i++) {
		if ((strstr(_rep->info[i].director, director_name) != NULL)) {
			dir_rep->info[j].name = (char*)malloc((strlen(_rep->info[i].name) + 1) * sizeof(char));
			dir_rep->info[j].director = (char*)malloc((strlen(_rep->info[i].director) + 1) * sizeof(char));
			dir_rep->info[j].country = (char*)malloc((strlen(_rep->info[i].country) + 1) * sizeof(char));
			strcpy(dir_rep->info[j].name, _rep->info[i].name);
			strcpy(dir_rep->info[j].director, _rep->info[i].director);
			strcpy(dir_rep->info[j].country, _rep->info[i].country);
			dir_rep->info[j].year = _rep->info[i].year;
			dir_rep->info[j].budget = _rep->info[i].budget;
			dir_rep->info[j].fees = _rep->info[i].fees;
			j++;
		}
	}
	return;
}

void free_array(FilmLibrary* arr) {
	int i;
	for (i = 0; i < arr->cnt; i++) {
		free(arr->info[i].name);
		free(arr->info[i].director);
		free(arr->info[i].country);
	}
	free(arr->info);
	return;
}