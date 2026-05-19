#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "warehouse.h"

void SearchMissingProducts(Product* products, int totalCount, Product** missingProducts, int* resultCount) {
    *resultCount = 0;

    for (int i = 0; i < totalCount; i++) {
        if (products[i].quantity == 0) {
            missingProducts[*resultCount] = &products[i];
            (*resultCount)++;
        }
    }
}