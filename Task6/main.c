#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

int main() {
    char filename[100];
    char author[100];
    Book* library;
    int count;

    printf("Введите имя файла: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;

    library = readBooks(filename, &count);
    printf("Загружено книг: %d\n\n", count);

    while (1) {
        printf("Введите автора (или 'exit'): ");
        fgets(author, 100, stdin);
        author[strcspn(author, "\n")] = 0;

        if (strcmp(author, "exit") == 0)
            break;

        printf("\nРезультаты поиска:\n");
        searchByAuthor(library, count, author);
    }

    freeBooks(library, count);
    return 0;
}