#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "library.h"


#define MAIN_FRAME "\
|-----------------------------|\n\
|      Личная библиотека      |\n\
|-----------------------------|\n\n"

#define OPERATIONS "\
1. Показать список книг\n\
2. Найти книги по автору\n\
0. Выход\n\n"

void printFrame();
int inputOperation();
void printError(STATUS status);
STATUS programCycle(BOOK* books, int countBooks);
STATUS printListBooks(BOOK* books, int countBooks);
STATUS searchBooksInterface(BOOK* books, int countBooks);
void inputAuthor(char author[], int maxLen);

#endif
