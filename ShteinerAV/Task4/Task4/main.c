#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define KOL_ITEM 3
#define N 5


void scan_item(int new_item, int array, int size);

int main() {
    srand((unsigned int)time(0));
    setlocale(LC_ALL, "rus");

    int userChoice, is_true = 1, i, j, rand_skid_1 = 1 + rand() % 50, rand_skid_2 = 1 + rand() % 50, rand_skid_3 = 1 + rand() % 50, itog_summa = 0;

    int array[KOL_ITEM][N] = {
        {1234, 159, rand_skid_1, 0, 159 - (int)(159 * rand_skid_1 / (float)100)},  // товар 1
        {1111, 500, rand_skid_2, 0, 500 - (int)(500 * rand_skid_2 / (float)100)},  // товар 2
        {1212, 400, rand_skid_3, 0, 400 - (int)(400 * rand_skid_3 / (float)100)}   // товар 3
    };

    do {
        system("cls");
        printf("Электронная касса \n\n");
        printf("1) Сканировать товар\n");
        printf("2) Сформировать чек\n");

        printf("\nКоманда: ");
        scanf_s("%d", &userChoice);
        getchar();

        while (userChoice < 1 || userChoice > 2) {
            printf("Ты ввёл команду неверно!");
            scanf_s("%d", &userChoice);
            getchar();
        }

        if (userChoice == 1) {
            system("cls");
            int barcode, id = -1;

            printf("Введите штрих-код товара на упаковке (4 цифры): ");
            scanf_s("%d", &barcode);

            // Сканирование элементов, проверка на наличие товара
            for (i = 0; i < KOL_ITEM; i++) {
                if (array[i][0] == barcode) {
                    id = i;
                    break;
                }
            }
            //----------------------------------

            // Вывод сканированного товара
            if (id != -1) {
                printf("\n    Товар   |  Цена(руб)  |  Скидка | Цена со скидкой\n");
                printf("-------------------------------------------------------\n");

                if (id == 0) {
                    printf(" Апельсинка       ");
                }
                else if (id == 1) {
                    printf("   Яболчки       ");
                }
                else {
                    printf("  Бананчики      ");
                }

                for (i = 1; i < N; i++) {
                    if (i != 3) {
                        printf("%d          ", array[id][i]);
                    }
                }
                printf("\n-------------------------------------------------------\n");

                printf("\n");
            }
            else {
                printf("Такого товара нет в осартементе!\n ");
                system("pause");
                continue;
            }
            //----------------------------------

            // Добавление в чек
            printf("Добавить этот товар в чек?\n");
            printf("1) Да\n");
            printf("2) Нет\n");

            printf("\nКоманда: ");
            scanf_s("%d", &userChoice);
            getchar();

            while (userChoice < 1 || userChoice > 2) {
                printf("Ты ввёл команду неверно!");
                scanf_s("%d", &userChoice);
                getchar();
            }

            if (userChoice == 1) {
                array[id][3]++;
            }
            else {
                continue;
            }
            //----------------------------------
            system("pause");
        }

        if (userChoice == 2) {
            system("cls");
            printf("-----------------ЧЕК------------------\n\n");
            // Вывод товаров, попавших в чек
            for (i = 0; i < KOL_ITEM; i++) {
                if (array[i][3] > 0) {
                    printf("\n    Товар   | Кол-во | Общая сумма \n");
                    printf("--------------------------------------\n");

                    if (i == 0) {
                        printf(" Апельсинка     %d          %d\n", array[i][3], array[i][3] * array[i][4]);
                    }
                    else if (i == 1) {
                        printf("   Яболчки       %d          %d\n", array[i][3], array[i][3] * array[i][4]);
                    }
                    else {
                        printf("  Бананчики      %d          %d\n", array[i][3], array[i][3] * array[i][4]);
                    }
                }
            }
            printf("\n\n--------------------------------------\n\n");
            //----------------------------------

            printf("Оплатить чек?\n");
            printf("1) Да\n");
            printf("2) Нет\n");

            printf("\nКоманда: ");
            scanf_s("%d", &userChoice);
            getchar();

            while (userChoice < 1 || userChoice > 2) {
                printf("Ты ввёл команду неверно!");
                scanf_s("%d", &userChoice);
                getchar();
            }

            // Вывод суммы чека
            if (userChoice == 1) {
                system("cls");
                for (i = 0; i < KOL_ITEM; i++) {
                    if (array[i][2] > 0) {
                        itog_summa += array[i][3] * array[i][4];
                    }
                }
                printf("\nСумма к оплате: %d\n", itog_summa);
                is_true = 0;
            }
            else {
                continue;
            }
            //----------------------------------

        }

    } while (is_true);
    return 0;
}

