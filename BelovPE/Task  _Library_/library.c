#pragma once
#include "library.h"
#include <stdlib.h>


void SearchByAuthor(int countBooks, Book* books) {
    char string[MAX_PATH];
    printf("Enter the author to search: ");
    scanf_s("%s", string, (unsigned)sizeof(string));
    printf("\n");


    int found = 0;

    for (int j = 0; j < countBooks; j++) {
        if (books[j].author && strstr(books[j].author, string) != NULL) {
            printf("Author: %s\n", books[j].author);
            printf("Name: %s\n", books[j].name);
            //printf("Publisher: %s\n", books[j].publisher);
            //printf("Year: %d\n", books[j].year);
            printf("\n");
            found++;
        }
    }


    if (!found) printf("No books found by author '%s'\n", string);

    if (found) printf("Books searched %d by author '%s'\n", found, string);

}