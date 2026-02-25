#ifndef __AUX_H
#define __AUX_H
#include "library.h"

book* reader(const char* source, int* n);
void parse(char* s, book* b);
void print_book(book b);
int count(FILE* f);
void free_all(book* lib, int n);


#endif