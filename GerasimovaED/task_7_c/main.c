#include "repertoir.h"
#include "auxiliary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
	FilmLibrary _rep;
	FilmLibrary dir_rep;
	_rep.cnt = 0;
	_rep.info = NULL;
	dir_rep.cnt = 0;
	dir_rep.info = NULL;
	char director_name[MAX_SIZE + 1];
	char pathway[MAX_SIZE + 1];

	while (_rep.cnt == 0) {
		printf("INPUT PATHWAY: ");
		scanf_s("%256s", pathway, sizeof(pathway));
		printf("\n");
		rep_counter(pathway, &_rep);
		if (_rep.cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	_rep.info = (Film*)malloc(_rep.cnt * sizeof(Film));
	rep_reader(pathway, &_rep);

	while (dir_rep.cnt == 0) {
		printf("INPUT DIRECTOR NAME: ");
		scanf_s("%256s", director_name, sizeof(director_name));
		printf("\n");
		director_counter(director_name, &_rep, &dir_rep);
		if (dir_rep.cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	dir_rep.info = (Film*)malloc(dir_rep.cnt * sizeof(Film));
	director_finder(director_name, &_rep, &dir_rep);
	rep_printer(&dir_rep);
	free_array(&_rep);
	free_array(&dir_rep);

	return 0;
}