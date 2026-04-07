#define _CRT_SECURE_NO_WARNINGS

#include "auxiliary.h"
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int books_r(int* lines, char* filename) {
	char buff[BUFFER_SIZE];
	FILE* fp = fopen(filename, "r");

	if (fp == NULL) {
		printf("ERROR!\nProbably, the library is empty or the file does not exist.\n\n");
		return 1;
	}

	while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
		(*lines)++;
	}
	fclose(fp);
	printf("The library found.\n\n");
	return 0;
}

void put_books_into_array(int* lines, char* filename, BOOK** library) {
	int i;
	char buff[BUFFER_SIZE];
	FILE* fp = fopen(filename, "r");
	(*library) = (BOOK*)malloc((*lines) * sizeof(BOOK));
	char* a, * n, * p;
	int py = 0;
	char delimiter[1] = ";";

	for (i = 0; i < (*lines); i++) {
		fgets(buff, BUFFER_SIZE, fp);
		if (buff[strlen(buff) - 1] == '\n') {
			buff[strlen(buff) - 1] = '\0';
		}

		a = strtok(buff, delimiter);
		n = strtok(0, delimiter);
		p = strtok(0, delimiter);
		sscanf(strtok(0, delimiter), "%d", &py);

		(*library)[i].authors = (char*)malloc((strlen(a) + 1) * sizeof(char));
		(*library)[i].name = (char*)malloc((strlen(n) + 1) * sizeof(char));
		(*library)[i].publishing = (char*)malloc((strlen(p) + 1) * sizeof(char));

		strcpy((*library)[i].authors, a);
		strcpy((*library)[i].name, n);
		strcpy((*library)[i].publishing, p);
		(*library)[i].publishing_year = py;
	}
	fclose(fp);
}

void print_books(int found_cnt, BOOK* found_books, char* needed_author) {
	int i;
	if (found_cnt == 0) {
		printf("There is no books by %s.\n\n", needed_author);
	}
	else {
		printf("There is %d books by %s.\n\n", found_cnt, needed_author);
		for (i = 0; i < found_cnt; i++) {
			printf("%s, %s, %s, %d\n", found_books[i].authors, found_books[i].name, found_books[i].publishing,
				found_books[i].publishing_year);
		}
	}
}