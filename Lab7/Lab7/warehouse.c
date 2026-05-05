#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "warehouse.h"

void SearchMissingProducts(Product* products, int totalCount) {
    int found = 0;
    printf("\n=== Отсутствующие товары ===\n");
    for (int i = 0; i < totalCount; i++) {
        if (products[i].quantity == 0) {
            printf("- %s\n", products[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("Все товары есть в наличии\n");
    }
}