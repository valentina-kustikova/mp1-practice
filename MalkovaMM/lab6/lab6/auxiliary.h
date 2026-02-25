#ifndef AUXILIARY_H
#define AUXILIARY_H
#include "library.h"

Book createbook(const char* line);
int countbooks(const char* fname);
Book* createbooks(const char* fname, int count);
void freeb(Book* books, int count);
void prbook(const Book* book);


#endif 



