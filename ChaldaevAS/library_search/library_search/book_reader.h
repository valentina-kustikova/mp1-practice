#ifndef BOOK_READER_H
#define BOOK_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 256
#define MAX_BOOKS 1000

typedef struct {
    char authors[MAX_STR_LEN];
    char title[MAX_STR_LEN];
    char publisher[MAX_STR_LEN];
    int year;
} Book;

int read_books_from_file(const char* filename, Book books[], int max_books);

void trim_string(char* str);

#endif