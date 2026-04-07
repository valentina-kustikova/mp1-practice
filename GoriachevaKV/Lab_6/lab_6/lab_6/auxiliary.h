#ifndef __AUXILIARY_H_
#define __AUXILIARY_H_
#include "library.h"
int books_r(int* lines, char* filename);
void put_books_into_array(int* lines, char* filename, BOOK** library);
void print_books(int found_cnt, BOOK* found_books, char* needed_author);
#endif