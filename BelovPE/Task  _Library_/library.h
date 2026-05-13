#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PATH 27


typedef struct {
    char* author;
    char* name;
    char* publisher;
    int year;
} Book;

Book* SearchByAuthor(int* found, int countBooks, Book* books, char* string);