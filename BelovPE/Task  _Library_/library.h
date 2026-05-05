#pragma once
#include <stdio.h>

#define MAX_PATH 260


typedef struct {
    char* author;
    char* name;
    char* publisher;
    int year;
} Book;

void SearchByAuthor(int countBooks, Book* books);