#define _CRT_SECURE_NO_WARNINGS 
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

#include "funcs.h"
#define MAX_LINE_LEN 512 

//typedef struct {
//    char* authors;
//    char* title;
//    char* publisher;
//    int year;
//}Book;
//
//
//Book divide_line(char* line) {
//    Book book;
//    char* token = strtok(line, ";");
//    book.authors = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//    strcpy(book.authors, token);
//
//    token = strtok(NULL, ";");
//    book.title = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//    strcpy(book.title, token);
//
//    token = strtok(NULL, ";");
//    book.publisher = (char*)malloc(sizeof(char) * (strlen(token) + 1));
//    strcpy(book.publisher, token);
//
//    token = strtok(NULL, ";");
//    book.year = atoi(token);
//
//    return book;
//}
//
//void show_books(Book* books, int n) {
//    for (int i = 0; i < n; i++)
//    {
//        printf("%s;%s;%s;%d\n", books[i].authors, books[i].title, books[i].publisher, books[i].year);
//    }
//    printf("\n");
//}
//
//char* to_lower(char* arr) {
//    for (int i = 0; arr[i] != '\0'; i++) {
//        arr[i] = tolower(arr[i]);
//    }
//    return arr;
//}
//
//
//
//void find_by_author(Book* books, int n, char* author) {
//    for (int i = 0; i < n; i++) {
//        if (strstr(books[i].authors, author)) {
//            printf("%s;%s;%s;%d\n", books[i].authors, books[i].title, books[i].publisher, books[i].year);
//        }
//    }
//}
//
//void free_books(Book* books, int n) {
//    for (int i = 0; i < n; i++) {
//        free(books[i].authors);
//        free(books[i].title);
//        free(books[i].publisher);
//    }
//    free(books);
//}


int main() {
    const char* filename = "kartoteka.txt";
    setlocale(LC_ALL, "Russian");

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 1;
    }

    int n = 0;
    Book* books = (Book*)malloc(sizeof(Book) * n);

    while (!feof(file))
    {
        char line[MAX_LINE_LEN];
        if (fgets(line, MAX_LINE_LEN, file)) {
            books = (Book*)realloc(books, sizeof(Book) * (n + 1));

            books[n] = divide_line(line);
            n++;
        }
    }
    fclose(file);

    show_books(books, n);

    char find_author[100];
    printf("¬ведите фамилию автора: ");
    fgets(find_author, 100, stdin);
    find_author[strlen(find_author) - 1] = '\0';

    to_lower(find_author);

    for (int i = 0; i < n; i++) {
        to_lower(books[i].authors);
    }

    find_by_author(books, n, find_author);
    free_books(books, n);

}