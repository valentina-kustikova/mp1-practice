#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funcs.h"


int main() {
    int is_true = 1, i;
    char user_choice;
    char new_barcode[5] = "";
    srand((unsigned int)time(0));
    setlocale(LC_ALL, "rus");

    char name_list[][20] = { "Мандаринки", "Бананчики", "Яблочки", "Апельсинки" };
    char barcode_list[][5] = { "1234", "1111", "1212", "0980" };
    int price_list[] = { 350, 139, 100, 239 };
    int cnt_list[] = { 0, 0, 0, 0 };
    int discounts[] = { 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 };
    int price_with_discounts[4];

    for (i = 0; i < N; i++) {
        price_with_discounts[i] = price_list[i] - (int)(price_list[i] * discounts[i] / 100.0f);
    }

    do {
        system("cls");
        printf("  ЭЛЕКТРОННАЯ КАССА\n");
        printf("----------------------\n");
        printf("1) Сканировать товар\n");
        printf("2) Сформировать чек\n");

        user_input(&user_choice);

        if (user_choice == '1') {
            scan_item(new_barcode, barcode_list, name_list, price_list, discounts, price_with_discounts, cnt_list);
        }
        else if (user_choice == '2') {
            print_check(name_list, price_with_discounts, cnt_list, &is_true);
        }
        else if (user_choice == '0') {
            is_true = 0;
        }

    } while (is_true);

    printf("Программа завершена.\n");
    return 0;
}

