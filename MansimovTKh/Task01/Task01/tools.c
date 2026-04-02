#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"

#define BUFFER_SIZE 1024

void print_found_books(book_info* found_books, int found) {
	int i;
	printf("The author's found works in the library:\n\n");
	for (i = 0; i < found; i++) {
		printf("%s -- %s -- %s -- %d\n", found_books[i].authors, found_books[i].title,
			found_books[i].publisher, found_books[i].year);
	}
}


void read_library(const char* filename, book_info** books, int* lines) {
	int i;
	char* a; char* t; char* p; char* year_str;
	char buffer[BUFFER_SIZE];
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		(*books) = NULL;
		(*lines) = 0;
		printf("ERROR\n\n"); return;
	}
	while (fgets(buffer, BUFFER_SIZE, fp) != NULL) (*lines)++;  //считаем количество строк
	*books = (book_info*)malloc((*lines) * sizeof(book_info));   //выделение памяти для lines строк


	rewind(fp); //возвращение в начало файла
	if ((*books) == NULL) {
		printf("ERROR\n\n");
		fclose(fp);
		return;
	}

	for (i = 0; i < (*lines); i++) {
		fgets(buffer, BUFFER_SIZE, fp);

		if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n') {  //убираем \n, чтобы в year не записался \n
			buffer[strlen(buffer) - 1] = '\0';
		}

		a = strtok(buffer, ";"); //возвращает указатель на имя автора
		t = strtok(NULL, ";");   //возвращает указатель на имя книги
		p = strtok(NULL, ";");   //возвращает указатель на имя издательства
		year_str = strtok(NULL, ";");  //возвращает указатель на год
		int y;

		if (a && t && p && year_str) {
			(*books)[i].authors = (char*)malloc((strlen(a) + 1) * sizeof(char));  //выделяем память под каждое поле char*
			(*books)[i].title = (char*)malloc((strlen(t) + 1) * sizeof(char));
			(*books)[i].publisher = (char*)malloc((strlen(p) + 1) * sizeof(char));

			if ((*books)[i].authors && (*books)[i].title && (*books)[i].publisher) {
				strcpy((*books)[i].authors, a);
				strcpy((*books)[i].title, t);
				strcpy((*books)[i].publisher, p);

				if (sscanf(year_str, "%d", &y) == 1) {
					(*books)[i].year = y;
				}
				else {
					printf("Ошибка в файле: %s не является годом в строке %d\n\n", year_str, i + 1);
					(*books)[i].year = 0;
				}

			}
		}
		else {
			printf("Ошибка в чтении строки %d\n\n", i + 1);
			(*books)[i].authors = NULL;
			(*books)[i].title = NULL;
			(*books)[i].publisher = NULL;
			(*books)[i].year = 0;
		}
	}
	fclose(fp);
}

