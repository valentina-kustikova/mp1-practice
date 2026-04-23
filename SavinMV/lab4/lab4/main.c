#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_product 5
#define CODE_len 5
#define NAME_len 20

char barcodes[MAX_product][CODE_len] = {"1001", "1002", "3451", "5678", "9999"};
char names[MAX_product][NAME_len] = {"moloko", "limonad", "xleb", "kefir", "konfeta"};
int prices[MAX_product] = { 100, 40, 50, 70, 120 };
int skidka[MAX_product] = { 10, 20, 5, 15, 30 };
int cnt[MAX_product] = { 0 };
int lastScanId = -1;

int findProdId(char inputCode[CODE_len]);
void scanProduct();
void infor();
void addvCheck();
void printCheck();
void itogPrice();
void showMenu();


int main() {
    int choice;
    setlocale(LC_ALL, "Rus");

    do {
        showMenu();
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            scanProduct(); break;
        case 2:
            infor(); break;
        case 3:
            addvCheck(); break;
        case 4:
            printCheck(); break;
        case 5:
            itogPrice(); break;
        default:
            if (choice != 5) {
                printf("Ошибка: введите число от 1 до 5.\n");
            }
        }
    } while (choice != 5);

    return 0;
}
int findProdId(char inputCode[CODE_len]) {
    for (int i = 0; i < MAX_product; i++) {
        if (strcmp(barcodes[i], inputCode) == 0) {
            return i;
        }
    }
    return -1;
}
void scanProduct() {
    char inputCode[CODE_len];
    printf("Введите штрих-код (4 цифры): ");
    scanf("%4s", inputCode);

    int index = findProdId(inputCode);
    if (index == -1) {
        printf("Товар не найден.\n");
        lastScanId = -1;
    }
    else {
        printf("Отсканирован товар: %s\n", names[index]);
        lastScanId = index;
    }
}
void infor() {
    if (lastScanId == -1) {
        printf("Нет отсканированного товара. Сначала выполните операцию 1.\n");
        return;
    }

    printf("\nОписание товара:\n");
    printf("Штрих-код: %s\n", barcodes[lastScanId]);
    printf("Наименование: %s\n", names[lastScanId]);
    printf("Стоимость за единицу: %d руб.\n", prices[lastScanId]);
    printf("Скидка: %d%%\n", skidka[lastScanId]);
}
void addvCheck() {
    if (lastScanId == -1) {
        printf("Нет отсканированного товара. Сначала выполните операцию 1.\n");
        return;
    }

    cnt[lastScanId]++;
    printf("Товар \"%s\" добавлен в чек.\n", names[lastScanId]);
}
void printCheck() {
    int itogbezskidki = 0;
    int itogsoskidkoy = 0;

    printf("\nЧЕК:\n");
    for (int i = 0; i < MAX_product; i++) {
        if (cnt[i] > 0) {
            int priceprod = cnt[i] * prices[i];
            int skidkatov = priceprod * skidka[i] / 100;
            int finalPrice = priceprod - skidkatov;

            printf("Наименование: %s\n", names[i]);
            printf("  Цена за шт: %d, Кол-во: %d\n", prices[i], cnt[i]);
            printf("  Итого (со скидкой): %d руб.\n\n", finalPrice);

            itogbezskidki += priceprod;
            itogsoskidkoy += finalPrice;
        }
    }

    if (itogsoskidkoy == 0) {
        printf("Чек пуст.\n");
    }
    else {
        printf("Общая стоимость: %d руб.\n", itogbezskidki);
        printf("Суммарная скидка: %d руб.\n", itogbezskidki - itogsoskidkoy);
        printf("ИТОГО К ОПЛАТЕ: %d руб.\n", itogsoskidkoy);
    }
}
void itogPrice() {
    int itog = 0;
    for (int i = 0; i < MAX_product; i++) {
        if (cnt[i] > 0) {
            int priceprod = cnt[i] * prices[i];
            int skidkatov = priceprod * skidka[i] / 100;
            itog += (priceprod - skidkatov);
        }
    }
    printf("\nИтоговая сумма к оплате: %d руб.\n\n", itog);
}
void showMenu() {
    printf("\nКасса:\n");
    printf("1 — Сканировать очередной товар\n");
    printf("2 — Вывести описание отсканированного товара\n");
    printf("3 — Добавить данные о товаре в чек\n");
    printf("4 — Сформировать чек за покупку\n");
    printf("5 — Рассчитать итоговую сумму к оплате\n");
    printf("Ваш выбор (1-5): ");
}