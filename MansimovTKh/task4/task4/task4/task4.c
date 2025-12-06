#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 4
void user_input(char* userChoice);

int main() {
    srand((unsigned int)time(0));
    setlocale(LC_ALL, "rus");
    char userChoice;
    int is_true = 1, i, flag = 0;
    char barcode[5] = "";
    char goods[N][20] = { "Маркер", "Карандаш", "Ручка", "Ластик" };
    char data_barcode[N][4] = { "1337", "1488", "1309", "0512" };
    int data_price[N] = { 119, 29, 69, 25 };
    int check[N] = { 0, 0, 0, 0 };
    int discounts[N] = { 1 + rand() % 50, 1 + rand() % 50, 1 + rand() % 50, 1 + rand() % 50 };
    int data_discounts_price[N] = {
        data_price[0] - (int)(data_price[0] * discounts[0] / (float)100),
        data_price[1] - (int)(data_price[1] * discounts[1] / (float)100),
        data_price[2] - (int)(data_price[2] * discounts[2] / (float)100),
        data_price[3] - (int)(data_price[3] * discounts[3] / (float)100)
    };
    int summa = 0, final_summa = 0, disc_sum = 0;
    int value_disc[N] = {
        (int)(data_price[0] * discounts[0] / (float)100),
        (int)(data_price[1] * discounts[1] / (float)100),
        (int)(data_price[2] * discounts[2] / (float)100),
        (int)(data_price[3] * discounts[3] / (float)100)
    };
    do {
        printf("Электронная касса \n"); printf("----------------------\n\n");
        printf("1) СКАН\n2) Сформировать чек\n");
        /*printf("Команда: ");scanf_s("%d", &userChoice);

        while (userChoice != 1 && userChoice != 4) {
            printf("Нормально пиши: "); scanf_s("%d", &userChoice);
        }*/
        user_input(&userChoice);
        if (userChoice == '1') {
            printf("Введите штрих-код товара: "); scanf_s("%4s", barcode, sizeof(barcode));

            for (i = 0; i < N; i++) {
                if (strncmp(barcode, data_barcode[i], 4) == 0) {
                    flag = 1;

                    printf("\n    Товар   |  Цена(руб)  |  Скидка %% | Цена со скидкой\n");
                    printf("-------------------------------------------------------\n");
                    printf(" %-16s %-12d %-12d %d", goods[i], data_price[i], discounts[i], data_discounts_price[i]);

                    printf("\n\n1) Добавить товар в чек\n2) Назад\n");
                    /*printf("Команда: "); scanf_s("%d", &userChoice);
                    while (userChoice != 2 && userChoice != 0) {
                        printf("Нормально пиши: "); scanf_s("%d", &userChoice);
                    }*/
                    user_input(&userChoice);

                    if (userChoice == '1') check[i]++;
                    else continue;

                }
            }
            if (flag == 0) {
                printf("Ошибка! Введенный штрих-код не существует\n\n");
            }
        }

        else if (userChoice == '2') {
            flag = 0;
            printf("----------------------ЧЕК---------------------\n");
            printf("\n    Товар   | Кол-во |Цена за 1 ед.| Общая сумма \n");

            for (i = 0; i < N; i++) {
                if (check[i] != 0) {
                    flag = 1;
                    summa += (check[i] * data_price[i]);
                    disc_sum += (check[i] * value_disc[i]);
                    final_summa += (data_discounts_price[i] * check[i]);
                    printf("------------------------------------------------\n");
                    printf(" %-15s %-8d %d            %d\n", goods[i], check[i], data_price[i], data_discounts_price[i] * check[i]);

                }
            }
            printf("Общая цена: %d\nСумма скидок: %d\nИтоговая сумма: %d\n", summa, disc_sum, final_summa);
            printf("------------------------------------------------\n\n\n");

            if (flag == 1) {
                printf("1) Расчитать итоговую сумму\n2)Продолжить\n");
                /*printf("Команда: "), scanf_s("%d", &userChoice);
                while (userChoice != 0 && userChoice != 5) {
                    printf("Нормально пиши: "); scanf_s("%d", &userChoice);
                }*/
                user_input(&userChoice);
                if (userChoice == '1') {
                    printf("Сумма к оплате: %d\n", final_summa);
                    return 1;
                }
                else {
                    continue;
                }
            }
            else {
                printf("Добавьте хоть 1 товар в чек!!!\n\n");
                continue;
            }

        }
        /*if (flag == 1) {
            printf("5) Расчитать итоговую сумму\n0)Продолжить\n");
            printf("Команда: "), scanf_s("%d", &userChoice);
            while (userChoice != 0 && userChoice != 5) {
                printf("Нормально пиши: "); scanf_s("%d", &userChoice);
            }
            if (userChoice == 5) {
                printf("Сумма к оплате: %d\n", final_summa);
                return 1;
            }
            else {
                continue;
            }
        }
        else {
            printf("Добавьте хоть 1 товар в чек!!!\n\n");
            continue;
        }*/



    } while (is_true);
    return 0;
}

//void print(int b[], int n) {
//    int i;
//    for (i = 0; i < n; i++) {
//        printf("%d ", b[i]);
//    }
//}

void user_input(char* userChoice) {
    int ch, extra_ch;

    while (1) {
        printf("\n Команда: "); scanf_s(" %c", userChoice, 1) != 1;

        extra_ch = 0;
        while ((ch = getchar()) != '\n') {
            extra_ch++;
        }

        if ((*userChoice == '1' || *userChoice == '2') && extra_ch == 0) {
            break;
        }
        else {
            printf("Нормально пиши: ");
        }
    }
}
