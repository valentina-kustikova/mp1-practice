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
	int cnt = 0, au_cnt = 0;
	char author_name[MAX_SIZE+1];
	char pathway[MAX_SIZE+1];

	while (cnt == 0) {
		printf("INPUT PATHWAY: ");
		scanf_s("%256s", pathway, sizeof(pathway));
		printf("\n");
		cab_counter(pathway, &cnt);
		if (cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	_lib = (BOOK*)malloc(cnt * sizeof(BOOK));
	cab_reader(cnt, pathway, _lib);

	while (au_cnt == 0) {
		printf("INPUT AUTHOR NAME: ");
		scanf_s("%256s", author_name, sizeof(author_name));
		printf("\n");
		author_counter(author_name, cnt, _lib, &au_cnt);
		if (au_cnt == 0) {
			system("pause");
			system("cls");
		}
	}
	au_lib = (BOOK*)malloc(au_cnt * sizeof(BOOK));
	author_finder(author_name, cnt, _lib, au_cnt, au_lib);
	cab_printer(au_cnt, au_lib);
	free_arrays(cnt, au_cnt, _lib, au_lib);

	return 0;
}