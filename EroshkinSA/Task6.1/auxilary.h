#ifndef __AUX_H
#define __AUX_H
#include "library.h"

extern book* reader(const char* source, int* n);
static void parse(char* s, book* b);
extern void print_book(book b);
static int count(FILE* f);

#endif