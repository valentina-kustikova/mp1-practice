#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "library.h"

STATUS readLibrary(BOOK** books, int* countBooks);
int getCountBooks(FILE* fp);
void stringToStruct(FILE* fp, BOOK* books, const int count);
void changeField(BOOK* book, const int indexField, const char* str);
STATUS printListBooks(const BOOK* books, const int countBooks);

#endif
