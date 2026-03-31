#define _CRT_SECURE_NO_WARNINGS 
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 
#include <string.h>


#define MAX_LINE_LEN 512 
#include "funcs.h"


Book* file_open(const char* filename, int* n) {

    char line[MAX_LINE_LEN];
    int i = 0;
    int book_count;

    FILE* file = fopen(filename, "r");
    if (file==NULL) {
        printf("File not found\n");
        *n = 0;
        return NULL;
    }

    if (fscanf(file, "%d\n", &book_count) != 1) {
        printf("Error reading book count\n");
        fclose(file);
        *n = 0;
        return NULL;
    }

    Book* books = (Book*)malloc(sizeof(Book) * book_count);

    while (i < book_count && fgets(line, MAX_LINE_LEN, file)) {
        books[i] = divide_line(line);
        i++;
    }

    fclose(file);

    *n = i;
    return books;
}


Book divide_line(char* line) {
    Book book;
    char* token = strtok(line, ";");
    book.authors = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(book.authors, token);

    token = strtok(NULL, ";");
    book.title = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(book.title, token);

    token = strtok(NULL, ";");
    book.publisher = (char*)malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(book.publisher, token);

    token = strtok(NULL, ";");
    book.year = atoi(token);

    return book;
}

void show_books(Book* books, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%s;%s;%s;%d\n", books[i].authors, books[i].title, books[i].publisher, books[i].year);
    }
    printf("\n");
}

char* to_lower(char* arr) {
    for (int i = 0; arr[i] != '\0'; i++) {
        arr[i] = tolower(arr[i]);
    }
    return arr;
}



void find_by_author(Book* books, int n, char* author) {
    char author_copy[100];
    strcpy(author_copy, author);
    to_lower(author_copy);
    char buffer[512];

    for (int i = 0; i < n; i++) {

        strcpy(buffer, books[i].authors);
        to_lower(buffer);
        if (strstr(buffer, author_copy)) {
            printf("%s;%s;%s;%d\n", books[i].authors, books[i].title, books[i].publisher, books[i].year);
        }
    }
}

void free_books(Book* books, int n) {
    for (int i = 0; i < n; i++) {
        free(books[i].authors);
        free(books[i].title);
        free(books[i].publisher);
    }
    free(books);
}