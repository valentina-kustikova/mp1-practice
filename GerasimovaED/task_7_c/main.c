#define _CRT_SECURE_NO_WARNINGS

#include "repertoir.h"
#include "auxiliary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
	FILM* _rep = NULL;
	FILM* dir_rep = NULL;
	int cnt = 0, dir_cnt = 0;
	char director_name[MAX_SIZE + 1];
	char pathway[MAX_SIZE + 1];

	while (cnt == 0) {
		printf("INPUT PATHWAY: ");
		scanf_s("%256s", pathway, sizeof(pathway));
		printf("\n");
		rep_counter(pathway, &cnt);
		if (cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	_rep = (FILM*)malloc(cnt * sizeof(FILM));
	rep_reader(cnt, pathway, _rep);

	while (dir_cnt == 0) {
		printf("INPUT DIRECTOR NAME: ");
		scanf_s("%256s", director_name, sizeof(director_name));
		printf("\n");
		director_counter(director_name, cnt, _rep, &dir_cnt);
		if (dir_cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	dir_rep = (FILM*)malloc(dir_cnt * sizeof(FILM));
	director_finder(director_name, cnt, _rep, dir_cnt, dir_rep);
	rep_printer(dir_cnt, dir_rep);
	free_arrays(cnt, dir_cnt, _rep, dir_rep);

	return 0;
}