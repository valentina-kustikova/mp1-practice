#include <stdio.h>
#include <stdlib.h>
#include "shop.h"
#include "auxiliary.h"
#include <locale.h>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RUS");
    char* filename;
    ShopLib shops;      
    ShopLib result;     

    if (argc < 2) {
        printf("Err");
        return 1;
    }

    filename = argv[1];

    shops.count = countShops(filename);
    if (shops.count <= 0) {
        printf("err\n");
        return 1;
    }


    shops.arr = (Shop*)malloc(shops.count * sizeof(Shop));
    if (shops.arr == NULL) {
        printf("err\n");
        return 1;
    }
    readFile(shops.count, shops.arr, filename);

    poisk24(&shops, &result);


    printResults(&result);

    free(shops.arr);

    free(result.arr);
    

    return 0;
}

