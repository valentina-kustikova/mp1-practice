#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "library.h"
#include "funcs.h"

int find_book(Book* arr, int size, int** id_books) {
	char* users_choice;
	int i, j, cnt_auth, id_cnt=0, k=0, id_i, id_j;

	enter_the_author(&users_choice);

	for (i = 0; i < size; i++) {
		cnt_auth = arr[i].cnt_authors;
		for (j = 0; j < cnt_auth; j++) {
			if (strncmp(arr[i].authors[j], users_choice, strlen(users_choice)) == 0) {
				id_cnt++;
				id_i = i;
				id_j = j;
			}
		}
	}
	
	*id_books = (int*)malloc(sizeof(int) * id_cnt);

	for (i = 0; i < size; i++) {
		cnt_auth = arr[i].cnt_authors;
		for (j = 0; j < cnt_auth; j++) {
			if (strncmp(arr[i].authors[j], users_choice, strlen(users_choice)) == 0) {
				(*id_books)[k++] = i;
			}
		}
	}

	system("cls");
	printf("Author: %s\n", arr[id_i].authors[id_j]);

	free(users_choice);
	return id_cnt;
}