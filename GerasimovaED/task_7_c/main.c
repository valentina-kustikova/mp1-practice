#include "repertoir.h"
#include "auxiliary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
	FilmLibrary _rep;
	FilmLibrary dir_rep;
	int cnt = 0, dir_cnt = 0;
	char director_name[MAX_SIZE + 1];
	char pathway[MAX_SIZE + 1];

	while (cnt == 0) {
		printf("INPUT PATHWAY: ");
		scanf_s("%256s", pathway, sizeof(pathway));
		printf("\n");
		cnt = rep_counter(pathway);
		if (cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	_rep = rep_reader(pathway, cnt);

	while (dir_cnt == 0) {
		printf("INPUT DIRECTOR NAME: ");
		scanf_s("%256s", director_name, sizeof(director_name));
		printf("\n");
		dir_cnt = director_counter(director_name, &_rep);
		if (dir_cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	dir_rep = director_finder(director_name, &_rep, dir_cnt);
	rep_printer(dir_rep);
	free_array(&_rep);
	free_array(&dir_rep);

	return 0;
}