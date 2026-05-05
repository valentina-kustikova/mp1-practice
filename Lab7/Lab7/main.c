#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "auxiliary.h"

int main(int argc, char** argv) {
    Product products[100];
    int count = 0;
    int choice;

    if (argc < 2) {
        return 1;  
    }

    
    FILE* f = fopen(argv[1], "r");
    if (f) {
        fscanf(f, "%d\n", &count);
        for (int i = 0; i < count; i++) {
            products[i].name = (char*)malloc(100);
            products[i].unit = (char*)malloc(50);
            products[i].date = (char*)malloc(20);

            fscanf(f, "%s\n", products[i].name);
            fscanf(f, "%s\n", products[i].unit);
            fscanf(f, "%f\n", &products[i].price);
            fscanf(f, "%d\n", &products[i].quantity);
            fscanf(f, "%s\n", products[i].date);
        }
        fclose(f);
    }

    
    do {
        printf("\n1. Добавить товар\n");
        printf("2. Показать все\n");
        printf("3. Найти отсутствующие\n");
        printf("4. Сохранить в файл\n");
        printf("5. Загрузить из файла\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        if (choice == 1) {
            inputProduct(&products[count]);
            count++;
        }
        else if (choice == 2) {
            printf("\n%-20s %-10s %8s %8s %-12s\n",
                "Название", "Ед.изм", "Цена", "Кол-во", "Дата");
            for (int i = 0; i < count; i++) {
                printProduct(products[i]);
            }
        }
        else if (choice == 3) {
            SearchMissingProducts(products, count);
        }
        else if (choice == 4) {
            FILE* f = fopen(argv[1], "w");
            if (f) {
                fprintf(f, "%d\n", count);
                for (int i = 0; i < count; i++) {
                    fprintf(f, "%s\n%s\n%f\n%d\n%s\n",
                        products[i].name,
                        products[i].unit,
                        products[i].price,
                        products[i].quantity,
                        products[i].date);
                }
                fclose(f);
                printf("Сохранено!\n");
            }
        }
        else if (choice == 5) {
            for (int i = 0; i < count; i++) {
                free(products[i].name);
                free(products[i].unit);
                free(products[i].date);
            }

            printf("Введите имя файла: ");
            char filename[100];
            scanf("%s", filename);

            FILE* f = fopen(filename, "r");
            if (f) {
                fscanf(f, "%d\n", &count);
                for (int i = 0; i < count; i++) {
                    products[i].name = (char*)malloc(100);
                    products[i].unit = (char*)malloc(50);
                    products[i].date = (char*)malloc(20);

                    fscanf(f, "%s\n", products[i].name);
                    fscanf(f, "%s\n", products[i].unit);
                    fscanf(f, "%f\n", &products[i].price);
                    fscanf(f, "%d\n", &products[i].quantity);
                    fscanf(f, "%s\n", products[i].date);
                }
                fclose(f);
                printf("Загружено!\n");
            }
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++) {
        free(products[i].name);
        free(products[i].unit);
        free(products[i].date);
    }

    return 0;
}