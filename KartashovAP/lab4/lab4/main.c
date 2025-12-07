#include <stdio.h>
#include <string.h>
#include <locale.h>
#define K 5

int main() {
    setlocale(LC_ALL, "Russian");

    char basket[5];
    char copybasket[5];
    int i, flag;
    float summskidka = 0.0;
    int summ = 0;
    int pr;


    char shtrixtov[K][5] = { "1111", "2222", "3333", "4444", "5555" };
    char nazvanie[K][7] = { "Cheese", "Cake", "Curd", "Meat", "Tea" };
    int kol[K] = { 0 };
    int tsena[K] = { 1000, 500, 2000, 700, 250 };
    int skidka[K] = { 10, 5, 15, 7, 2 };

    do {
        printf("Введите штрихкод товара (1111-5555) или 0 для завершения: ");
        scanf_s("%4s", basket, (unsigned)sizeof(basket));

        while (getchar() != '\n');

        if (strcmp(basket, "0") == 0) {
            break;
        }

        strcpy_s(copybasket, sizeof(copybasket), basket);

        flag = 0;
        for (i = 0; i < K; i++) {
            if (strcmp(copybasket, shtrixtov[i]) == 0) {
                flag = 1;
                printf("Отсканированный товар: %s (Цена: %d, Скидка: %d%%)\n",
                    nazvanie[i], tsena[i], skidka[i]);
                printf("Добавим товар? Если да введите 11, если нет то введите 00: ");
                scanf_s("%d", &pr);


                while (getchar() != '\n');

                if (pr == 11) {
                    kol[i] += 1;
                    printf("Товар добавлен: %s (Цена: %d, Скидка: %d%%)\n",
                        nazvanie[i], tsena[i], skidka[i]);
                }
                else {
                    printf("Отсканируйте другой товар\n");
                }
                break;
            }
        }

        if (flag == 0) {
            printf("Товар с штрих-кодом %s не найден!\n", basket);
        }

    } while (1);

    printf("\nВАШ ЧЕК\n");
    printf("========================\n");
    for (i = 0; i < K; i++) {
        if (kol[i] != 0) {
            int total = kol[i] * tsena[i];
            printf("%s - %d руб. x %d шт. = %d руб.\n",
                nazvanie[i], tsena[i], kol[i], total);
            summ += total;
            summskidka = summskidka + (total * (skidka[i] / 100.0));
        }
    }

    printf("\nИтог:\n");
    printf("========================\n");
    printf("Общая сумма: %d руб.\n", summ);
    printf("Скидка: %.2f руб.\n", summskidka);
    printf("К оплате: %.2f руб.\n", summ - summskidka);

    return 0;
}