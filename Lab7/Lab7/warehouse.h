#ifndef WAREHOUSE_H
#define WAREHOUSE_H

typedef struct Product {
    char* name;
    char* unit;
    float price;
    int quantity;
    char* date;
} Product;


void SearchMissingProducts(Product* products, int totalCount, Product** missingProducts, int* resultCount);

#endif