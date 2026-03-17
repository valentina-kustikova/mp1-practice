#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxlib.h"

#define BUFFER 1024
void get_library(const char* filename, book_info** books, int* lines) {
	FILE* filep = fopen(filename, "r");
	int i;
	char buff[BUFFER];
	if (filep == NULL) {
		*books = NULL;
		*lines = 0;
		printf("Error\n\n");
		return;
	}
	while (fgets(buff, BUFFER, filep) != NULL) {
		(*lines)++;
	}
	*books = (book_info*)malloc(*lines * sizeof(book_info));
	rewind(filep);
	if ((*books) == NULL) {
		printf("ERROR\n\n");
		fclose(filep);
		return;
	}

	for (i = 0; i < (*lines); i++) {
		fgets(buff, BUFFER, filep);
		if (strlen(buff) > 0 && buff[strlen(buff) - 1] == '\n') {
			buff[strlen(buff) - 1] = '\0';
		}
		char* autr = strtok(buff, ";");
		char* name = strtok(NULL, ";");
		char* publ = strtok(NULL, ";");
		char* year = strtok(NULL, ";");
		int y;
		if (autr && name && publ && year) {
			(*books)[i].author = malloc((strlen(autr) + 1) * sizeof(char));
			(*books)[i].book_name = malloc((strlen(name) + 1) * sizeof(char));
			(*books)[i].publisher = malloc((strlen(publ) + 1) * sizeof(char));
			if ((*books)[i].author && (*books)[i].book_name && (*books)[i].publisher) {
				strcpy((*books)[i].author, autr);
				strcpy((*books)[i].book_name, name);
				strcpy((*books)[i].publisher, publ);

				if (sscanf(year, "%d", &y) == 1) {
					(*books)[i].book_year = y;
				}
				else {
					printf("Год не указан.\n\n");
					(*books)[i].book_year = 0;
				}
			}

		}
		else {
			printf("Ошибка чтения книги.\n\n");
			(*books)[i].author = NULL;
			(*books)[i].book_name = NULL;
			(*books)[i].publisher = NULL;
			(*books)[i].book_year = 0;
		}
	}
	fclose(filep);
}

void printer(book_info* found_books, int found_count) {
	int i;
	for (i = 0; i < found_count; i++) {
		printf("%s -- %s -- %s -- %d\n", found_books[i].author, found_books[i].book_name, found_books[i].publisher, found_books[i].book_year);
	}
}
//void print_books(book_info* books, int lines) {
//	int i;
//	for (i = 0; i < lines; i++) {
//		printf("%s -- %s -- %s -- %d\n", books[i].author, books[i].book_name, books[i].publisher, books[i].book_year);
//	}
//}