#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 4

void user_input(char* user_choice);
void scan_item(char new_barcode[], char barcode_list[][5], char name_list[][20],
    int price_list[], int discounts[], int price_with_discounts[], int cnt_list[]);
void print_check(char name_list[][20], int price_with_discounts[], int cnt_list[], int* is_true);

int main() {
    int is_true = 1, i;
    char user_choice;
    char new_barcode[5] = "";
    srand((unsigned int)time(0));
    setlocale(LC_ALL, "rus");

    char name_list[N][20] = { "Мандаринки", "Бананчики", "Яблочки", "Апельсинки" };
    char barcode_list[N][5] = { "1234", "1111", "1212", "0980" };
    int price_list[N] = { 350, 139, 100, 239 };
    int cnt_list[N] = { 0, 0, 0, 0 };
    int discounts[N] = { 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 };
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

void user_input(char* user_choice) {
    int c;

    while (1) {
        printf("\nКоманда: ");
        scanf_s(" %c", user_choice, sizeof(user_choice));

        while ((c = getchar()) != '\n' && c != EOF);

        if (*user_choice == '1' || *user_choice == '2') {
            break;
        }
        else {
            printf("Неверно! Допустимы только команды 1 или 2.\n");
        }
    }
}

void scan_item(char new_barcode[], char barcode_list[][5], char name_list[][20],
    int price_list[], int discounts[], int price_with_discounts[], int cnt_list[]) {
    int flag = 0, i;
    char user_choice;
    int c;

    system("cls");
    printf("Введите штрих-код товара: ");

    scanf_s("%4s", new_barcode, sizeof(new_barcode));

    while ((c = getchar()) != '\n' && c != EOF);

    for (i = 0; i < N; i++) {
        if (strncmp(new_barcode, barcode_list[i], 4) == 0) {
            flag = 1;
            printf("\n    Товар   |  Цена(руб)  |  Скидка | Цена со скидкой\n");
            printf("-------------------------------------------------------\n");
            printf(" %-16s %-12d %-12d %d\n", name_list[i], price_list[i], discounts[i], price_with_discounts[i]);

            printf("\n\nДобавить этот товар в чек?\n");
            printf("1) Да          2) Нет\n");

            user_input(&user_choice);

            if (user_choice == '1') {
                cnt_list[i]++;
                printf("Товар добавлен в чек!\n");
                system("pause");
            }
            break;
        }
    }

    if (flag == 0) {
        printf("Такого товара нет в базе данных!\n");
        system("pause");
    }
}

void print_check(char name_list[][20], int price_with_discounts[], int cnt_list[], int* is_true) {
    int flag, i, itog_summ = 0;
    char user_choice;
    
    flag = 0;
    for (i = 0; i < N; i++) {
        if (cnt_list[i] != 0) {
            flag = 1;
            break;
        }
    }

    system("cls");
    if (flag != 0) { 
        printf("                ЧЕК\n");
        printf("--------------------------------------\n");
        printf("    Товар   | Кол-во | Общая сумма \n");
        printf("--------------------------------------\n");
        for (i = 0; i < N; i++) {
            if (cnt_list[i] != 0) {
                printf(" %-15s %-8d %d\n", name_list[i], cnt_list[i], price_with_discounts[i] * cnt_list[i]);
                itog_summ += price_with_discounts[i] * cnt_list[i];
            }
        }
        printf("--------------------------------------\n");
    }
    else {
        printf("Вы не добавили товар в чек!\n");
        system("pause");
        return;
    }

    printf("Итого: %d руб.\n\n", itog_summ);
    printf("Желаете оплатить товар?\n");
    printf("1) Да          2) Нет\n");

    user_input(&user_choice);

    if (user_choice == '1') {
        system("cls");
        printf("Сумма к оплате: %d руб.\n", itog_summ);
        printf("Оплата прошла успешно!\n");
        *is_true = 0;
    }
    else {
        printf("Оплата отменена.\n");
    }
    system("pause");
}