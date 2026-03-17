#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "library.h"


Book* readBooks(char* filename, int* count);
void freeBooks(Book* books, int count);

#endif