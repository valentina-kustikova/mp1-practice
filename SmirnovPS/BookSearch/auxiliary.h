#ifndef AUXILIARY_H
#define AUXILIARY_H
#include "library.h"
int book_amount(const char* file_name);
void read_file(int count, Book* library, char* file_name);
void print_books(Book* found_books, int k);
#endif


