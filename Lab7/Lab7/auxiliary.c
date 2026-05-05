#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "auxiliary.h"


void inputProduct(Product* p) {
    p->name = (char*)malloc(100);
    p->unit = (char*)malloc(50);
    p->date = (char*)malloc(20);

    printf("Название: ");
    scanf_s("%s", p->name);
    printf("Единица измерения: ");
    scanf_s("%s", p->unit); 
    printf("Цена: ");
    scanf_s("%f", &p->price);
    printf("Количество: ");
    scanf_s("%d", &p->quantity);
    printf("Дата (ДД.ММ.ГГГГ): ");
    scanf_s("%s", p->date);
}

void printProduct(Product p) {
    printf("%-20s %-10s %8.2f %8d %-12s\n", p.name, p.unit, p.price, p.quantity, p.date);
}

