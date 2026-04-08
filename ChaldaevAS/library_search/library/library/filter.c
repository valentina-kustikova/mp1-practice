#define _CRT_SECURE_NO_WARNINGS
#include "filter.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int* search_by_author(struct Book* books, int book_count, char* author, int* found_count) {
	if (books == NULL || book_count == 0) {
		printf("\n[ERROR]: No book loaded!\n");
		return NULL;
	}
	int* temp_indexes = (int*)malloc(book_count * sizeof(int));
	int count = 0;
	int i = 0;
	for (i; i < book_count; i++) {
		if (strstr(books[i].authors, author) != NULL) {
			temp_indexes[count] = i;
			count++;
		}
	}
	int* result = (int*)malloc(count * sizeof(int));
	if (result == NULL) {
		*found_count = 0;
		free(temp_indexes);
		return NULL;
	}
	for (int i = 0; i < count; i++) {
		result[i] = temp_indexes[i];
	}

	free(temp_indexes);
	*found_count = count;
	return result;
}

int* search_by_title(struct Book* books, int book_count, char* title, int* found_count) {
	if (books == NULL || book_count == 0) {
		printf("\n[ERROR]: No book loaded!\n");
		return;
	}
	int* temp_indexes = (int*)malloc(book_count * sizeof(int));
	int count = 0;
	int i = 0;
	for (i; i < book_count; i++) {
		if (strstr(books[i].name, title) != NULL) {
			temp_indexes[count] = i;
			count++;
		}
	}
	int* result = (int*)malloc(count * sizeof(int));
	if (result == NULL) {
		*found_count = 0;
		free(temp_indexes);
		return NULL;
	}
	for (int i = 0; i < count; i++) {
		result[i] = temp_indexes[i];
	}

	free(temp_indexes);
	*found_count = count;
	return result;
}

void print_filtered_books(struct Book* books, int* indexes, int count) {
	int i = 0;

	if (books == NULL || indexes == NULL || count == 0) {
		printf("\n[INFO]: No books to display.\n");
		return;
	}
	printf("\n_______________[FOUND BOOKS]_(%d)_____________\n", count);
	for (i; i < count; i++) {
		int idx = indexes[i];
		printf("| Book #%d\n", i + 1);
		printf("+---------\n");
		printf("| Author(s):	%30s\n", books[idx].authors);
		printf("| Title:		%30s\n", books[idx].name);
		printf("| Publisher:	%30s\n", books[idx].publisher);
		printf("| Year:			%30d\n", books[idx].year);
		printf("+---------\n");

	}
}

void free_indexes(int* indexes) {
	if (indexes != NULL) {
		free(indexes);
		printf("[INFO]: Filter indexes memory is free\n");
	}
}