#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

void searchByAuthor(Book* books, int totalCount, char* author,
    Book** authorBooks, int* resultCount) {

    int foundCount = 0;
    for (int i = 0; i < totalCount; i++) {  
        if (strstr(books[i].authors, author) != NULL) {
            foundCount++;
        }
    }

    *authorBooks = (Book*)malloc(foundCount * sizeof(Book));

   
    int index = 0;
    for (int i = 0; i < totalCount; i++) {
        if (strstr(books[i].authors, author) != NULL) {
            (*authorBooks)[index] = books[i];
            index++;
        }
    }

    *resultCount = foundCount;
}
