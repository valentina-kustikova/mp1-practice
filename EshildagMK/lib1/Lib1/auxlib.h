#include "libfi.h"
#ifndef AUX_H
#define AUX_H

#define BUFFER 1024
#define NAME_max 128



void get_library(const char* filename, book_info** books, int* lines);
void print_books(book_info* books, int lines);

#endif
