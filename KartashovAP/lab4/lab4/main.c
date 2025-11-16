#include <stdio.h>
#include <locale.h>
#define K 5

int main() {
    setlocale(LC_ALL, "Russian");

    int basket, copybasket;
    int i, j, flag;
    float summskidka = 0.0;
    int summ = 0;
    int barcode[4];

    int shtrixtov[K][4] = { {1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {4,4,4,4}, {5,5,5,5} };
    char nazvanie[K][7] = { "Cheese", "Cake", "Curd", "Meat", "Tea" };
    int kol[K] = { 0 };
    int tsena[K] = { 1000, 500, 2000, 700, 250 };
    int skidka[K] = { 10, 5, 15, 7, 2 };

    do {
        printf("Введите штрихкод товара (1111-5555) или 0 для завершения: ");
        scanf_s("%d", &basket);

        if (basket == 0) {
            break;
        }
        copybasket = basket;
        for (i = 3; i >= 0; i--) {
            barcode[i] = copybasket % 10;
            copybasket = copybasket / 10;
        }


        flag = 0;
        for (i = 0; i < K; i++) {
            flag = 1;
            for (j = 0; j < 4; j++) {
                if (barcode[j] != shtrixtov[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                kol[i] += 1;
                printf("Товар добавлен: %s (Цена: %d, Скидка: %d%%)\n", nazvanie[i], tsena[i], skidka[i]);
                break;
            }
        }

        if (flag == 0) {
            printf("Товар с штрих-кодом %d не найден!\n", basket);
        }

    } while (1);

    printf("ВАШ ЧЕК\n");
    for (i = 0; i < K; i++) {
        if (kol[i] != 0) {
            int total = kol[i] * tsena[i];
            printf("%s - %d руб. x %d шт. = %d руб.\n", nazvanie[i], tsena[i], kol[i], total);
            summ += total;
            summskidka = summskidka + (total * (skidka[i] / 100.0));
        }
    }

    printf("\nИтоги:\n");
    printf("Общая сумма: %d руб.\n", summ);
    printf("Скидка: %.2f руб.\n", summskidka);
    printf("К оплате: %.2f руб.\n", summ - summskidka);

    return 0;
}