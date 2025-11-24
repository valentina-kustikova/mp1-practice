#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 4


void user_input(char *user_choise);
void scan_item(char new_barcode[], char barcode_list[][4], char name_list[][20], int price_list[], int discounts[], int price_with_discounts[], int cnt_list[]);;
void print_check(char name_list[][20], int price_with_discounts[], int cnt_list[]);

int main() {
    srand((unsigned int)time(0));
    setlocale(LC_ALL, "rus");

    int is_true = 1, i, flag = 0, itog_summ = 0;
    char user_choise;
    char new_barcode[5] = "";

    char name_list[N][20] = { "Мандаринки", "Бананчики", "Яблочки", "Апельсинки" };
    char barcode_list[N][4] = { "1234", "1111", "1212", "0980"};
    int price_list[N] = { 350, 139, 100, 239 };
    int cnt_list[N] = { 0, 0, 0, 0 };
    int discounts[N] = { 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 };
    int price_with_discounts[4] = { 
        price_list[0] - (int)(price_list[0] * discounts[0] / (float)100),
        price_list[1] - (int)(price_list[1] * discounts[1] / (float)100),
        price_list[2] - (int)(price_list[2] * discounts[2] / (float)100),
        price_list[3] - (int)(price_list[3] * discounts[3] / (float)100)
        };

   do {
       system("cls");
       printf("  ЭЛЕКТРОННАЯ КАССА\n");
       printf("----------------------\n");
       printf("1) Сканировать товар\n");
       printf("2) Сформировать чек\n");

       user_input(&user_choise);

       if (user_choise == '1') {
           scan_item(new_barcode, barcode_list, name_list, price_list, discounts, price_with_discounts, cnt_list);
       }

       else if (user_choise == '2') {
           print_check(name_list, price_with_discounts, cnt_list);
       }
    } while (is_true);
    return 0;
}

void user_input(char* user_choice) {
    int c;
    int extra_chars = 0;

    while (1) {
        printf("\nКоманда: ");
        scanf_s(" %c", user_choice, 1) != 1;
        
        extra_chars = 0;
        while ((c = getchar()) != '\n') {
            extra_chars++;
        }

        if ((*user_choice == '1' || *user_choice == '2') && extra_chars == 0) {
            break;
        }
        else {
            if (extra_chars > 0) {
                printf("Неверно! Введите только один символ (1 или 2), а не несколько. ");
            }
            else {
                printf("Неверно! Допустимы только команды 1 или 2. ");
            }
        }
    }
}


void scan_item(char new_barcode[], char barcode_list[][4], char name_list[][20], int price_list[], int discounts[], int price_with_discounts[], int cnt_list[]) {
    int flag = 0, i;
    char user_choise;
    
    system("cls");
    printf("Введите штрих-код товара: ");
    scanf_s("%4s", new_barcode, sizeof(new_barcode));

    for (i = 0; i < N; i++) {
        if (strncmp(new_barcode, barcode_list[i], 4) == 0) {
            flag = 1;
            printf("\n    Товар   |  Цена(руб)  |  Скидка | Цена со скидкой\n");
            printf("-------------------------------------------------------\n");
            printf(" %-16s %-12d %-12d %d", name_list[i], price_list[i], discounts[i], price_with_discounts[i]);

            printf("\n\nДобавить этот товар в чек?\n");
            printf("1) Да          2) Нет\n");

            user_input(&user_choise);

            if (user_choise == '1') {
                cnt_list[i]++;
            }
            else {
                continue;
            }
        }
    }
    if (flag == 0) {
        printf("Такого товара нет в базе данных! \n");
        system("pause");
    }
}
void print_check(char name_list[][20], int price_with_discounts[], int cnt_list[]) {
    int flag, i, itog_summ = 0;
    char user_choise;

    system("cls");
    printf("                ЧЕК\n");
    printf("--------------------------------------\n");
    flag = 0;
    for (i = 0; i < N; i++) {
        if (cnt_list[i] != 0) {
            flag = 1;
            printf("\n    Товар   | Кол-во | Общая сумма \n");
            printf("--------------------------------------\n");
            printf(" %-15s %-8d %d\n", name_list[i], cnt_list[i], price_with_discounts[i] * cnt_list[i]);
        }
    }
    printf("\n--------------------------------------");

    if (flag == 1) {
        printf("\n\nЖелаете оплатить товар? \n");
        printf("1) Да          2) Нет\n");

        user_input(&user_choise);

        if (user_choise == '1') {
            system("cls");
            for (i = 0; i < N; i++) {
                if (cnt_list[i] != 0) {
                    itog_summ += price_with_discounts[i] * cnt_list[i];
                }
            }
            printf("Сумма к оплате: %d\n", itog_summ);
            system("pause");
            return 1;
        }
        else {
            return 0;
            system("pause");
        }
    }
    else {
        system("cls");
        printf("Вы не добавили товар в чек!\n");
        system("pause");
        return 0;
    }
}