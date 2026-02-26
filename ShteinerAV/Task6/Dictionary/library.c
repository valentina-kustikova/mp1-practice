#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "library.h"
#include "funcs.h"

int find_book(Book* arr, int size, Book** id_books, char* users_choice) { 
	int i, j, cnt_auth, id_cnt = 0, k = 0;

	for (i = 0; i < size; i++) {
		cnt_auth = arr[i].cnt_authors;
		for (j = 0; j < cnt_auth; j++) {
			if (_strnicmp(arr[i].authors[j], users_choice, strlen(users_choice)) == 0) {
				id_cnt++;
			}
		}
	}

	*id_books = (Book*)malloc(sizeof(Book) * id_cnt);

	for (i = 0; i < size; i++) {
		cnt_auth = arr[i].cnt_authors;
		for (j = 0; j < cnt_auth; j++) {
			if (_strnicmp(arr[i].authors[j], users_choice, strlen(users_choice)) == 0) {
				(*id_books)[k].authors = (char**)malloc(sizeof(char*));
				(*id_books)[k].authors[0] = _strdup(arr[i].authors[j]);
				(*id_books)[k].cnt_authors = 1;
				(*id_books)[k].books_name = _strdup(arr[i].books_name);
				(*id_books)[k].publishing = _strdup(arr[i].publishing);
				(*id_books)[k++].year = arr[i].year;
			}
		}
	}

	free(users_choice);
	return id_cnt;
}