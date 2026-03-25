#define _CRT_SECURE_NO_WARNINGS 
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 
#include <string.h>


#define MAX_LINE_LEN 512 
#include "funcs.h"

void file_open(FILE* file, Book* books, const char* filename, int n, int i) {

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    books = (Book*)malloc(sizeof(Book) * n);

    while (!feof(file))
    {
        char line[MAX_LINE_LEN];
        if (fgets(line, MAX_LINE_LEN, file)) {
            books[i++] = divide_line(line);
        }
    }
    fclose(file);
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
    Book arr;
    for (int i = 0; i < n; i++) {

        strcpy(arr[i].authors, books[i].authors);
        to_lower(arr[i].authors); // при поиске создать копию и в ней регитр поменять

        if (strstr(arr[i].authors, author)) {
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