#include "struct.h"

void search_author(Book* books, int count, const char* author) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].authors, author) != NULL) {
            printf("автор: %s ", books[i].authors);
            printf("название: %s ", books[i].title);
            printf("издание: %s ", books[i].publisher);
            printf("год: %d ", books[i].year);
            found = 1;
        }
    }

    if (found==0) {
        printf("нет книг по заланному автору: %s\n", author);
    }
}