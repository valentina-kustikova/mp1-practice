#ifndef AUXX_H
#define AUXX_H

#include <stdio.h>
#include "library.h"

int cntBooks(FILE* file);
void readFile(BookData* array, int cnt, FILE* file);
void printResult(BookData* result, int k);

#endif

