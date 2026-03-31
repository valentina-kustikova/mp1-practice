#include <stdio.h>
#include <string.h>
#include "library.h"


void searchByAuthor(Book* books, int count, char* author) {
    for (int i = 0; i < count; i++) {

        if (strstr(books[i].authors, author) != NULL) {
            printf("Авторы: %s\n", books[i].authors);
            printf("Название: %s\n", books[i].title);
            printf("Издательство: %s\n", books[i].publisher);
            printf("Год: %d\n", books[i].year);
            printf("-------------------\n");
        }
    }
}