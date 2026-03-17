#ifndef AUX_H
#define AUX_H

#include "libfi.h"

void get_library(const char* filename, book_info** books, int* lines);
void print_books(book_info* books, int lines);
void printer(book_info* found_books, int found_count);

#endif
