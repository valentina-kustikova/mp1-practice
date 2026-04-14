#ifndef AUXILIARY_H
#define AUXILIARY_H
#include "liblary.h"
int numberBooks(const char* filename);
void readFile(int count, Book* arr, const char* filename);
void printResults(Book* search, int k);
#endif