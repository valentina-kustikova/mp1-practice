#ifndef AUXILARY_H
#define AUXILARY_H

#include "library.h"
#include <stdio.h>

int getrange(FILE* file);
void loadbooks(FILE* file, book* books, int n);

#endif