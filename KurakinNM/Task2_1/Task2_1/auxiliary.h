#ifndef _AUXILIARY_
#define _AUXILIARY_

#include "library.h"
#include <stdlib.h>
#include <string.h>

int read(char* fileName, BOOK** books);
void output(BOOK* lib, int numOfBooks);

#endif