#define _CRT_SECURE_NO_WARNINGS 
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

#include "funcs.h"
#define MAX_LINE_LEN 512 


int main() {
    int n, i = 0;
    const char* filename = "kartoteka.txt";
    Book* books;
    FILE* file;
    char find_author[100];

    setlocale(LC_ALL, "Russian");

    books = file_open("kartoteka.txt", &n);

    show_books(books, n);

    printf("¬ведите фамилию автора: ");
    fgets(find_author, 100, stdin);
    find_author[strlen(find_author) - 1] = '\0';

    find_by_author(books, n, find_author);
    free_books(books, n);

    return 0;
}