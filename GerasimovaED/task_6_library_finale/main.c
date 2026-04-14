#define _CRT_SECURE_NO_WARNINGS

#include "library.h"
#include "auxiliary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
	BOOK* _lib = NULL;
	BOOK* au_lib = NULL;
	int cnt = 0, is_exist = 0, au_cnt = 0, i;
	char author_name[MAX_SIZE+1];
	char pathway[MAX_SIZE+1];

	while (cnt == 0) {
		printf("INPUT PATHWAY: ");
		scanf_s("%256s", pathway, sizeof(pathway));
		printf("\n");
		is_exist = cab_counter(&cnt, pathway);
		if (is_exist == 404) {
			system("pause");
			system("cls");
		}
	}
	cab_reader(&cnt, pathway, &_lib);

	printf("INPUT AUTHOR NAME: ");
	scanf_s("%256s", author_name, sizeof(author_name));
	printf("\n");
	author_finder(author_name, &au_cnt, &au_lib, cnt, _lib);
	cab_printer(au_cnt, au_lib);

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

	return 0;
}