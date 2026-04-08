#define _CRT_SECURE_NO_WARNINGS
#include "reader.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 



void get_filepath(char* filepath, int size) {
	printf("\nPlease, write your filepath: ");
	fgets(filepath, size, stdin);
	filepath[strcspn(filepath, "\n")] = '\0';
}

int check_correct_path(char* filepath) {
	FILE* file = fopen(filepath, "r");
	if (file == NULL) {
		printf("Error: can not open the file %s\n", filepath);
		return 0;
	}
	fclose(file);
	return 1;
}

int count_lines_(char* filepath) {
	FILE* file = fopen(filepath, "r");
	if (file == NULL) {
		printf("Error: can not open the file %s\n", filepath);
		return 0;
	}

	int lines = 0;
	char ch;
	while ((ch = fgetc(file)) != EOF) {
		if (ch == '\n') lines++;
	}
	fclose(file);
	return lines;
}

struct Book* memory_allocate_(int book_count) {
	if (book_count <= 0) return NULL;

	struct Book* books = (struct Book*)malloc(book_count * sizeof(struct Book));
	if (books == NULL) {
		printf("Error: memory allocation failed!\n");
		return NULL;
	}
	return books;
}

void free_books(struct Book* books) {
	if (books != NULL) {
		free(books);
		printf("Memory freed successfully\n");
	}
}


struct Book* read_books_from_file(char* filepath, int* book_count) {
	FILE* file = fopen(filepath, "r");
	int lines = 0;
	struct Book* books = NULL;
	int count = 0;
	char line[MAX_TOKEN * 5];
	char* token = NULL;

	if (file == NULL) {
		printf("Error: can not open the file %s\n", filepath);
		return NULL;
	}

	lines = count_lines_(filepath);

	if (lines <= 0) {
		printf("Error: File is empty or error reading!\n");
		return NULL;
	}

	books = memory_allocate_(lines);

	if (books == NULL) return NULL;

	while ((fgets(line, sizeof(line), file) != NULL) && count < lines) {
		line[strcspn(line, "\n")] = '\0';


		token = strtok(line, ";");
		if (token) strcpy(books[count].authors, token);

		token = strtok(NULL, ";");
		if (token) strcpy(books[count].name, token);

		token = strtok(NULL, ";");
		if (token) strcpy(books[count].publisher, token);

		token = strtok(NULL, ";");
		if (token) books[count].year = atoi(token);

		count++;
	}

	fclose(file);
	*book_count = count;
	return books;
}

void print_all_books(struct Book* books, int book_count) {
	int i;
	for (i = 0; i < book_count; i++) {
		printf("%30s | %30s | %30s | %d\n", books[i].authors, books[i].name, books[i].publisher, books[i].year);
	}
}