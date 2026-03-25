#define _CRT_SECURE_NO_WARNINGS 
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h> 
#include <string.h>

#include "funcs.h"
#define MAX_LINE_LEN 512 


int main() {
    int n = 0, i = 0;
    const char* filename = "kartoteka.txt";
    Book* books;
    FILE* file;
    char find_author[100];

    setlocale(LC_ALL, "Russian");

    /// отдельная функция чтения
    /*file = fopen(filename, "r");
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
    ///*/

    show_books(books, n);

    printf("Введите фамилию автора: ");
    fgets(find_author, 100, stdin);
    find_author[strlen(find_author) - 1] = '\0';

    to_lower(find_author);

    for (int i = 0; i < n; i++) {
        to_lower(books[i].authors); // при поиске создать копию и в ней регитр поменять
    }

    find_by_author(books, n, find_author);
    free_books(books, n);

    return 0;
}