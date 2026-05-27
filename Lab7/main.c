#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "auxiliary.h"

int main(int argc, char** argv) {
    Product products[100];
    int count = 0;
    int choice;

    if (argc < 2) {
        printf("ERROR: No file specified!\n");
        printf("Usage: %s <filename>\n", argv[0]);
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
        printf("Loaded %d products from %s\n", count, argv[1]);
    }
    else {
        printf("File %s not found. Warehouse is empty.\n", argv[1]);
    }

    do {
        printf("\n=== WAREHOUSE MENU ===\n");
        printf("1. Show all products\n");
        printf("2. Find missing products (quantity = 0)\n");
        printf("3. Save to file\n");
        printf("4. Load from file\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (count == 0) {
                printf("Warehouse is empty. Load data from file first.\n");
            }
            else {
                printf("\n%-20s %-10s %8s %8s %-12s\n",
                    "Name", "Unit", "Price", "Quantity", "Date");
                for (int i = 0; i < count; i++) {
                    printProduct(products[i]);
                }
            }
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("Warehouse is empty. Load data from file first.\n");
            }
            else {
                Product* missingProducts[100];
                int resultCount = 0;

                SearchMissingProducts(products, count, missingProducts, &resultCount);

                if (resultCount == 0) {
                    printf("All products are in stock.\n");
                }
                else {
                    printf("\n=== MISSING PRODUCTS ===\n");
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
                printf("Saved to %s\n", argv[1]);
            }
            else {
                printf("ERROR: Cannot save to %s\n", argv[1]);
            }
        }
        else if (choice == 4) {
            for (int i = 0; i < count; i++) {
                free(products[i].name);
                free(products[i].unit);
                free(products[i].date);
            }

            printf("Enter filename: ");
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
                printf("Loaded from %s\n", filename);
            }
            else {
                printf("ERROR: Cannot load from %s\n", filename);
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