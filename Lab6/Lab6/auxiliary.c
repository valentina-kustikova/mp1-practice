#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliary.h"

Book* readBooks(char* filename, int* count) {
    FILE* file = fopen(filename, "r");
    Book* books = NULL;
    char line[1000];
    int size = 0;


    while (fgets(line, sizeof(line), file) != NULL) {
        size++;
    }


    books = (Book*)malloc(sizeof(Book) * size);


    rewind(file);


    *count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {

        line[strcspn(line, "\n")] = 0;


        char* token;

        token = strtok(line, ";");
        books[*count].authors = (char*)malloc(strlen(token) + 1);
        strcpy(books[*count].authors, token);


        token = strtok(NULL, ";");
        books[*count].title = (char*)malloc(strlen(token) + 1);
        strcpy(books[*count].title, token);


        token = strtok(NULL, ";");
        books[*count].publisher = (char*)malloc(strlen(token) + 1);
        strcpy(books[*count].publisher, token);

        // Год
        token = strtok(NULL, ";");
        books[*count].year = atoi(token);

        (*count)++;
    }

    fclose(file);
    return books;
}

void freeBooks(Book* books, int count) {
    for (int i = 0; i < count; i++) {
        free(books[i].authors);
        free(books[i].title);
        free(books[i].publisher);
    }
    free(books);
}