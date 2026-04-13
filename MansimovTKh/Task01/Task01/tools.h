
#ifndef _AUX_H
#define _AUX_H

#include "libarg.h"

void read_library(const char* filename, book_info** books, int* lines);
void print_found_books(book_info* found_books, int found);

#endif
