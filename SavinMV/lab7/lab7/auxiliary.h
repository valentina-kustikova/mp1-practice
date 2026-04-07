#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "shop.h"

int countShops(const char* filename);
void readFile(int count, Shop* array, const char* filename);
void printResults(Shop* search, int count);

#endif
