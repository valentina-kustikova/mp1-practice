#ifndef _AUXILIARY_
#define _AUXILIARY_

#include "library.h"
#include <stdlib.h>

void bariers(char* str, int* start, int* numOfSims);
int read(char* fileName, BOOK** books);
void output(BOOK* lib, int numOfBooks);

#endif