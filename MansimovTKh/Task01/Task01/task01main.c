#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "libarg.h"

#define BUFFER_SIZE 1024
#define SURNAME_SIZE 30

int main() {
	int lines=0, i;
	book_info* books=NULL;

	read_library("library.txt", &books, &lines);

	//for (i = 0; i < lines; i++) {
	//	//printf("%s %s %s %d\n", books[i].authors, books[i].title, books[i].publisher, books[i].year);
	//	printf("%s\n", books[i].authors);
	//}

	char* author_surname = (char*)malloc(sizeof(char) * SURNAME_SIZE);
	if (author_surname == NULL) {
		printf("Error of memory allocation\n\n");
		return 1;
	}
	printf("Enter the surname of the author whose works you want to view : ");
	fgets(author_surname, SURNAME_SIZE, stdin);
	if (strlen(author_surname) > 0 && author_surname[strlen(author_surname) - 1] == '\n') {  //убираем \n, чтобы в year не записался \n
		author_surname[strlen(author_surname) - 1] = '\0';
	}

	printf("Searching for author: %s ...\n\n", author_surname);
	book_info* found_books = NULL; int found=0;
	find_books(author_surname, &found_books, books, lines, &found);

	if (found != 0) print_found_books(found_books, found);

	for (i = 0; i < lines; i++) {
		free(books[i].authors);
		free(books[i].title);
		free(books[i].publisher);
	}

	if (found_books != NULL) {
		for (int i = 0; i < found; i++) {
			free(found_books[i].authors);
			free(found_books[i].title);
			free(found_books[i].publisher);
		}
		free(found_books);
	}

	free(books);
	free(author_surname);
	return 0;
}




