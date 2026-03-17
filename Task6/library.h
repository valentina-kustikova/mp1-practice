#ifndef LIBRARY_H
#define LIBRARY_H


typedef struct {
    char* authors;
    char* title;
    char* publisher;
    int year;
} Book;


void searchByAuthor(Book* books, int count, char* author);

#endif