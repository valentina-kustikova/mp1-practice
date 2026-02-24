#ifndef AUXILI_H
#define AUXLI_H
#include "library.h"
int numberBooks(const char* filename);
void readFile(int count, struct Book* array, const char* filename);
void printResults(struct Book* search, int k);
#endif
