#include <stdio.h>
#include <stdlib.h>
#include "shop.h"
#include "auxiliary.h"
#include <locale.h>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RUS");
    char* filename;
    int count, foundCount;
    Shop* array;
    Shop* search;

    if (argc < 2) {
        printf("Err");
        return 1;
    }
    filename = argv[1];

    count = countShops(filename);

    array = (Shop*)malloc(count * sizeof(Shop));

    readFile(count, array, filename);

    search24hGroceries(array, count, &search, &foundCount);
    printResults(search, foundCount);

    free(array);
    free(search);
   
    return 0;
}