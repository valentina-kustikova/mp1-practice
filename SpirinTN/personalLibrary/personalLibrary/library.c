#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "library.h"
#include "auxiliary.h"


STATUS readLibrary(BOOK** books, int* countBooks, char* fileName) {
	STATUS status—orrectnessLines;
	FILE* fp = fopen(fileName, "r");
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

STATUS stringToStruct(FILE* fp, BOOK* books, int count) {
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

void changeField(BOOK* book, int indexField, char* str) {
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

STATUS searchBooksByAuthor(BOOK* books, int countBooks, char* author, BOOK** authorBooks, int* countAuthorBooks) {
    int i, k = 0;
	BOOK* tempBooks = NULL;
	char tempAuthor[LENGTH_STRING + 1];

	strncpy(tempAuthor, author, sizeof(tempAuthor));
	tempBooks = (BOOK*)malloc(sizeof(BOOK) * countBooks);

	if (tempBooks == NULL) {
		return ERROR_MEMORY;
	}

	toLowerCase(tempAuthor);
	for (i = 0; i < countBooks; i++) {
		tempBooks[i] = books[i];
		toLowerCase(tempBooks[i].authors);
	}

	*countAuthorBooks = 0;
    for (i = 0; i < countBooks; i++) {
        if (strstr(tempBooks[i].authors, tempAuthor) != NULL) {
			(*countAuthorBooks)++;
        }
    }
	if ((*countAuthorBooks) == 0) {
		free(tempBooks);
		tempBooks = NULL;
		return ERROR_NO_FILTRED_BOOKS;
	}
	*authorBooks = (BOOK*)malloc(sizeof(BOOK) * (*countAuthorBooks));
	if ((*authorBooks) == NULL) {
		return ERROR_MEMORY;
	}
	for (i = 0; i < countBooks; i++) {
		if (strstr(tempBooks[i].authors, tempAuthor) != NULL) {
			(*authorBooks)[k++] = books[i];
		}
	}
	free(tempBooks);
	tempBooks = NULL;
    return SUCCESS;
}

void toLowerCase(char* str) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		str[i] = tolower(str[i]);
	}
}