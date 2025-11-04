#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 4


void user_input(int *user_choise);

int main() {
    srand((unsigned int)time(0));
    setlocale(LC_ALL, "rus");

    int is_true = 1, user_choise, i, flag = 0, itog_summ = 0;
    char new_barcode[5] = "";

    char name_list[N][20] = { "Мандаринки", "Бананчики", "Яблочки", "Апельсинки" };
    char barcode_list[N][4] = { "1234", "1111", "1212", "0980"};
    int price_list[N] = { 350, 139, 100, 239 };
    int cnt_list[N] = { 0, 0, 0, 0 };
    int discounts[N] = { 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 , 1 + rand() % 50 };
    int price_with_discounts[4] = { 
        price_list[0] - (int)(price_list[0] * (1 + rand() % 50) / (float)100),
        price_list[1] - (int)(price_list[1] * (1 + rand() % 50) / (float)100),
        price_list[2] - (int)(price_list[2] * (1 + rand() % 50) / (float)100),
        price_list[3] - (int)(price_list[3] * (1 + rand() % 50) / (float)100)
        };

   do {
       system("cls");
       printf("  ЭЛЕКТРОННАЯ КАССА\n");
       printf("----------------------\n");
       printf("1) Сканировать товар\n");
       printf("2) Сформировать чек\n");

       user_input(&user_choise);

       if (user_choise == 1) {
           system("cls");
           printf("Введите штрих-код товара: ");
           scanf_s("%4s", new_barcode, sizeof(new_barcode));
           
           for (i = 0; i < N; i++) {
               if (strncmp(new_barcode, barcode_list[i], 4) == 0) {
                   flag = 1;
                   printf("\n    Товар   |  Цена(руб)  |  Скидка | Цена со скидкой\n");
                   printf("-------------------------------------------------------\n");
                   printf(" %-16s %-12d %-12d %d", name_list[i], price_list[i], discounts[i], price_with_discounts[i]);

                   printf("\n\nДобавть этот товар в чек?\n");
                   printf("1) Да          2) Нет\n");

                   user_input(&user_choise);

                   if (user_choise == 1) {
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

       else if (user_choise == 2) {
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

               if (user_choise == 1) {
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
                   continue;
                   system("pause");
               }
           }
           else {
               system("cls");
               printf("Вы не добавили товар в чек!\n");
               system("pause");
               continue;
           }
           
       }
    } while (is_true);
    return 0;
}

void user_input(int *user_choise) {
    printf("\nКоманда: ");
    scanf_s("%d", user_choise);

    while (*user_choise < 1 || *user_choise > 2) {
        printf("Ты ввёл команду неверно");
        printf("\nКоманда: ");
        scanf_s("%d", user_choise);
    }
}

