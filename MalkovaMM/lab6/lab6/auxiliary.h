#ifndef AUXILIARY_H
#define AUXILIARY_H
#include "library.h"

#define MAX_LEN 1000

Book createbook(const char* line);
int countbooks(const char* fname);
Book* createbooks(const char* fname, int count);
void prbook(const Book* book);

#endif 



