#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shop.h"
#include "auxiliary.h"

int countShops(const char* filename) {
    char buff[2048];
    int count = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка");
        return 1;
    }
    while (fgets(buff, sizeof(buff), file)) {
        count++;
    }
    fclose(file);
    return count;
}

void readFile(int count, Shop* array, const char* filename) {
    char buff[2048];
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Ошибка");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fgets(buff, sizeof(buff), file);
        buff[strcspn(buff, "\n")] = 0;
        strcpy(array[i].name, strtok(buff, ";"));
        strcpy(array[i].address, strtok(NULL, ";"));
        strcpy(array[i].phones, strtok(NULL, ";"));
        strcpy(array[i].special, strtok(NULL, ";"));
        strcpy(array[i].forma, strtok(NULL, ";"));
        strcpy(array[i].reshim, strtok(NULL, ";"));
        
    }
    fclose(file);
}

void printResults(Shop* search, int count) {
    if (count == 0) {
        printf("\nКруглосуточных продуктовых магазинов не найдено\n");
        return;
    }

    if (count == 1) {
        printf("\nНайден %d круглосуточный продуктовый магазин:\n", count);
    }
    else {
        printf("\nНайдено %d круглосуточных продуктовых магазинов:\n", count);
    }
    for (int i = 0; i < count; i++) {
        printf("%s, %s, %s, %s, %s, %s\n",search[i].name,search[i].address,search[i].phones,
            search[i].special, search[i].forma, search[i].reshim);
    }
}