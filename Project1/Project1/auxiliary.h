#ifndef AUXILIARY_H
#define AUXILIARY_H
#include "liblary.h"
int numberBooks(const char* filename);
void readFile(int count, struct Book* array, const char* filename);
void printResults(struct Book* search, int k);
#endif
