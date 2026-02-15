#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

STATUS readLibrary(BOOK** books, int* countBooks) {
    FILE* fp = fopen("books.txt", "r");
    if (fp == NULL) {
        printf("Файла не существует!\n");
        return ERROR_FILE;
    }

    *countBooks = getCountBooks(fp);
    rewind(fp);
    *books = (BOOK*)malloc((*countBooks) * sizeof(BOOK));
    if (*books == NULL) {
        printf("Ошибка выделения памяти!\n");
        return ERROR_MEMORY;
    }
    stringToStruct(fp, *books, *countBooks);

    if (fclose(fp) != 0) {
        printf("Ошибка при закрытии файла!\n");
        return ERROR_FILE;
    }

    return SUCCESS;
}

int getCountBooks(FILE* fp) {
    int count = 0;
    char line[800];

    while (fgets(line, sizeof(line), fp)) {
        count++;
    }
    return count;
}

void stringToStruct(FILE* fp, BOOK* books, const int count) {
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
        
        indexBook++;
    }
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

STATUS printListBooks(const BOOK* books, const int countBooks) {
    int i;
    if (countBooks == 0) {
        printf("В картотеке пусто!\n");
        return ERROR_NO_BOOKS;
    }

    for (i = 0; i < countBooks; i++) {
        printf("%d. %s\nАвторы: %s\nИздательство: %s\nГод изд-ва: %d\n\n", 
        i+1, books[i].title, books[i].authors, books[i].publishingHouse, books[i].yearPublishing);
    }
    system("pause");
    return SUCCESS;
}