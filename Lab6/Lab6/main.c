#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "library.h"
#include "auxiliary.h"

int main(int argc, char** argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    char author[100];
    Book* library;
    int count;
    Book* foundBooks;
    int foundCount;

    library = readBooks(argv[1], &count);

    if (argc < 2) {
        return 1;
    }

    if (library == NULL) {
        printf("Ошибка: не удалось открыть файл library.txt\n");
        return 1;
    }

    printf("Загружено книг: %d\n\n", count);

    while (1) {
        printf("Введите автора (или 'exit'): ");
        fgets(author, 100, stdin);
        author[strcspn(author, "\n")] = 0;

        if (strcmp(author, "exit") == 0)
            break;

        printf("\nРезультаты поиска:\n");

        foundBooks = NULL;
        foundCount = 0;

        searchByAuthor(library, count, author, &foundBooks, &foundCount);

        printBooks(foundBooks, foundCount);
        free(foundBooks);

        printf("\n");
    }

    freeBooks(library, count);
    return 0;
}