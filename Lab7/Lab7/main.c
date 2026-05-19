#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "auxiliary.h"

int main(int argc, char** argv) {
    Product products[100];
    int count = 0;
    int choice;

    if (argc < 2) {
        printf("Ошибка: не указан файл для загрузки!\n");
        printf("Использование: %s <имя_файла>\n", argv[0]);
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
        printf("Загружено %d товаров из %s\n", count, argv[1]);
    }
    else {
        printf("Файл %s не найден. Склад пуст.\n", argv[1]);
    }

    do {
        printf("\n1. Показать все товары\n");
        printf("2. Найти отсутствующие товары\n");
        printf("3. Сохранить в файл\n");
        printf("4. Загрузить из файла\n");
        printf("0. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count == 0) {
                printf("Склад пуст. Загрузите данные из файла.\n");
            }
            else {
                printf("\n%-20s %-10s %8s %8s %-12s\n",
                    "Название", "Ед.изм", "Цена", "Кол-во", "Дата");
                for (int i = 0; i < count; i++) {
                    printProduct(products[i]);
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("Склад пуст. Загрузите данные из файла.\n");
            }
            else {
                Product* missingProducts[100];
                int resultCount = 0;

                SearchMissingProducts(products, count, missingProducts, &resultCount);

                if (resultCount == 0) {
                    printf("Все товары есть в наличии\n");
                }
                else {
                    printf("\n=== Отсутствующие товары ===\n");
                    for (int i = 0; i < resultCount; i++) {
                        printf("- %s\n", missingProducts[i]->name);
                    }
                }
            }
        }
        else if (choice == 3) {
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
                printf("Сохранено в %s\n", argv[1]);
            }
            else {
                printf("Ошибка сохранения в %s\n", argv[1]);
            }
        }
        else if (choice == 4) {
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
                printf("Загружено из %s\n", filename);
            }
            else {
                printf("Ошибка загрузки из %s\n", filename);
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