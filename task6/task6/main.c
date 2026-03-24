#define _CRT_SECURE_NO_WARNINGS 
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

#include "funcs.h"
#define MAX_LINE_LEN 512 


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