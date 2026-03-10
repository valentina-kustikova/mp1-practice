#ifndef AUXLI_H
#define AUXLI_H
#include "library.h"

//доп. функции (кол-во книг, чтение заполнение, вывод рез)
int countingBooks(const char* filename);
void readFile(int count_book, Book* masbook, const char* filename);
void printRes(Book* search, int kol_res);

#endif

