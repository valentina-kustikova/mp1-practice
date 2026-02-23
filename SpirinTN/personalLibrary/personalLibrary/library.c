#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"
#include "auxiliary.h"


STATUS readLibrary(BOOK** books, int* countBooks) {
	STATUS status—orrectnessLines;
	FILE* fp = fopen("books.txt", "r");
	if (fp == NULL) {
		return FILE_OPENING_ERROR;
	}

	*countBooks = getCountBooks(fp);
	if (*countBooks == 0) {
		return ERROR_NO_BOOKS;
	}

	rewind(fp);
	*books = (BOOK*)malloc((*countBooks) * sizeof(BOOK));
	if (*books == NULL) {
		return ERROR_MEMORY;
	}
	status—orrectnessLines = stringToStruct(fp, *books, *countBooks);

	if (fclose(fp) != 0) {
		return FILE_CLOSE_ERROR;
	}

	return status—orrectnessLines;
}

int getCountBooks(FILE* fp) {
	int count = 0;
	char line[800];

	while (fgets(line, sizeof(line), fp)) {
		count++;
	}
	return count;
}

STATUS stringToStruct(FILE* fp, BOOK* books, const int count) {
	int indexBook = 0;
	char line[800];
	while (indexBook < count && fgets(line, sizeof(line), fp)) {
		int i;
		line[strcspn(line, "\n")] = '\0';
		char* token = strtok(line, ";");
		for (i = 0; token != NULL; i++) {
			changeField(&(books[indexBook]), i, token);
			token = strtok(NULL, ";");
		}

		if (i != 4) {
			return INVALID_FILE;
		}

		indexBook++;
	}
	return SUCCESS;
}

void changeField(BOOK* book, const int indexField, const char* str) {
	switch (indexField) {
	case 0:
		strncpy(book->authors, str, sizeof(book->authors));
		book->authors[sizeof(book->authors) - 1] = '\0';
		break;
	case 1:
		strncpy(book->title, str, sizeof(book->title));
		book->authors[sizeof(book->title) - 1] = '\0';
		break;
	case 2:
		strncpy(book->publishingHouse, str, sizeof(book->publishingHouse));
		book->authors[sizeof(book->publishingHouse) - 1] = '\0';
		break;
	case 3:
		sscanf(str, "%d", &book->yearPublishing);
		break;
	}
}

STATUS searchBooksByAuthor(BOOK* books, const int countBooks, const char* author, BOOK** authorBooks, int* countAuthorBooks) {
    int i, k = 0;
	*countAuthorBooks = 0;
    for (i = 0; i < countBooks; i++) {
        if (strstr(books[i].authors, author) != NULL) {
			(*countAuthorBooks)++;
        }
    }
	if ((*countAuthorBooks) == 0) {
		return ERROR_NO_FILTRED_BOOKS;
	}
	*authorBooks = (BOOK*)malloc(sizeof(BOOK) * (*countAuthorBooks));
	if ((*authorBooks) == NULL) {
		return ERROR_MEMORY;
	}
	for (i = 0; i < countBooks; i++) {
		if (strstr(books[i].authors, author) != NULL) {
			(*authorBooks)[k++] = books[i];
		}
	}
    return SUCCESS;
}