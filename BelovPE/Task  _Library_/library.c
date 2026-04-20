#include "library.h"
#include <string.h>

Book* lib = NULL;
int bookCount = 0;
int maxBooks = 10;

void readFile(FILE* f) {
    char line[1000];
    int i, j, part;
    int capacity = maxBooks;

    lib = (Book*)malloc(capacity * sizeof(Book));
    if (lib == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    bookCount = 0;

    while (fgets(line, 1000, f) != NULL) {
        if (bookCount >= capacity) {
            capacity *= 2;
            Book* temp = (Book*)realloc(lib, capacity * sizeof(Book));
            if (temp == NULL) {
                printf("Ошибка расширения памяти!\n");
                break;
            }
            lib = temp;
        }


        for (i = 0; line[i]; i++) {
            if (line[i] == '\n') {
                line[i] = '\0';
                break;
            }
        }

        if (line[0] == '\0') continue;


        lib[bookCount].authors = (char*)malloc(500 * sizeof(char));
        lib[bookCount].name = (char*)malloc(200 * sizeof(char));
        lib[bookCount].publisher = (char*)malloc(200 * sizeof(char));

        if (lib[bookCount].authors == NULL ||
            lib[bookCount].name == NULL ||
            lib[bookCount].publisher == NULL) {
            printf("Ошибка выделения памяти для книги!\n");
            break;
        }


        part = 0;
        i = 0;
        j = 0;

        lib[bookCount].authors[0] = '\0';
        lib[bookCount].name[0] = '\0';
        lib[bookCount].publisher[0] = '\0';
        lib[bookCount].year = 0;

        while (line[i]) {
            if (line[i] == ';') {
                if (part == 0) lib[bookCount].authors[j] = '\0';
                if (part == 1) lib[bookCount].name[j] = '\0';
                if (part == 2) lib[bookCount].publisher[j] = '\0';
                part++;
                j = 0;
                i++;
                continue;
            }

            if (part == 0) {
                lib[bookCount].authors[j] = line[i];
                j++;
            }
            else if (part == 1) {
                lib[bookCount].name[j] = line[i];
                j++;
            }
            else if (part == 2) {
                lib[bookCount].publisher[j] = line[i];
                j++;
            }
            else if (part == 3) {
                if (line[i] >= '0' && line[i] <= '9') {
                    lib[bookCount].year = lib[bookCount].year * 10 + (line[i] - '0');
                }
            }
            i++;
        }

        if (part == 1) lib[bookCount].name[j] = '\0';
        if (part == 2) lib[bookCount].publisher[j] = '\0';

        bookCount++;
    }

    fclose(f);
    printf("Загружено книг: %d\n", bookCount);
}

void search() {
    char author[100];
    int i, found;

    while (1) {
        printf("\nАвтор (exit - выход): ");
        fgets(author, 100, stdin);


        for (i = 0; author[i]; i++) {
            if (author[i] == '\n') {
                author[i] = '\0';
                break;
            }
        }

        if (author[0] == 'e' && author[1] == 'x' &&
            author[2] == 'i' && author[3] == 't' && author[4] == '\0') {
            break;
        }

        if (author[0] == '\0') continue;

        found = 0;
        for (i = 0; i < bookCount; i++) {
            char* a = lib[i].authors;
            char* b = author;
            int match = 0;

            while (*a) {
                char* pa = a;
                char* pb = b;

                while (*pa && *pb && *pa == *pb) {
                    pa++;
                    pb++;
                }

                if (*pb == '\0') {
                    match = 1;
                    break;
                }
                a++;
            }

            if (match) {
                if (found == 0) {
                    printf("\nНайдено:\n");
                }
                printf("  %s - %s %d\n", lib[i].authors, lib[i].name, lib[i].year);
                found++;
            }
        }

        if (found == 0) {
            printf("Ничего нет\n");
        }
        else {
            printf("Всего: %d\n", found);
        }
    }
}