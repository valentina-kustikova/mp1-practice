#include "library.h"


Book* SearchByAuthor(int* found, int countBooks, Book* books, char* string) {
    printf("\n");
    int index = 0;


    for (int j = 0; j < countBooks; j++) {
        if (books[j].author && strstr(books[j].author, string) != NULL) (*found)++;
    }


    if (*found == 0) {
        printf("No books found by author '%s'\n", string);
        return NULL;
    }
    printf("Books searched %d by author '%s'\n", *found, string);


    Book* books_of_struct = malloc( (*found) * sizeof(Book));
    if (!books_of_struct) {
        printf("Memory allocation failed! Number 2\n");
        return NULL;
    }
    printf("Location massive of books by %s = %p\n\n", string, books_of_struct);


    for (int i = 0; i < *found; i++) {
        books_of_struct[i].author = NULL;
        books_of_struct[i].name = NULL;
        books_of_struct[i].publisher = NULL;
        books_of_struct[i].year = 0;
    }


    for (int i = 0; i < countBooks; i++) {
        if (books[i].author && strstr(books[i].author, string) != NULL) {


            if (books[i].author) {
                books_of_struct[index].author = malloc(strlen(books[i].author) + 1);
                strcpy_s(books_of_struct[index].author, strlen(books[i].author) + 1, books[i].author);
            }


            if (books[i].name) {
                books_of_struct[index].name = malloc(strlen(books[i].name) + 1);
                strcpy_s(books_of_struct[index].name, strlen(books[i].name) + 1, books[i].name);
            }


            if (books[i].publisher) {
                books_of_struct[index].publisher = malloc(strlen(books[i].publisher) + 1);
                strcpy_s(books_of_struct[index].publisher, strlen(books[i].publisher) + 1, books[i].publisher);
            }


            books_of_struct[index].year = books[i].year;
            index++;
        }
    }

    return books_of_struct;
}