#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#define N 10000

int number = 0;
int discont[N], price[N];
int added_code[N] = { 0 }, count[N] = { 0 };
int tcode[4];
double sum = 0, final_discont = 0;

//Служебные функции

void data_generation() {
    int i;

    srand((unsigned) time(0));
    for (i = 1; i < N; i++) {
        price[i] = rand() % 1000;
        discont[i] = rand() % 50 + 1;
    }
}

void code_translation(int code) {
    int i, temp = code;

    for (i = 3; i >= 0; i--) {
        tcode[i] = temp % 10;
        temp /= 10;
    }
}

void name_printer(kind,country,color,type) {
    setlocale(LC_ALL, "Russian");

    switch (color) {
    case 0: printf("Красный\n"); break;
    case 1: printf("Оранжевый\n"); break;
    case 2: printf("Жёлтый\n"); break;
    case 3: printf("Зелёный\n"); break;
    case 4: printf("Синий\n"); break;
    case 5: printf("Голубой\n"); break;
    case 6: printf("Фиолетовый\n"); break;
    case 7: printf("Чёрный\n"); break;
    case 8: printf("Розовый\n"); break;
    case 9: printf("Коричневый\n"); break;
    }
    switch (country) {
    case 0: printf("Российский\n"); break;
    case 1: printf("Немецкий\n"); break;
    case 2: printf("Итальянский\n"); break;
    case 3: printf("Американский\n"); break;
    case 4: printf("Японский\n"); break;
    case 5: printf("Китайский\n"); break;
    case 6: printf("Индийский\n"); break;
    case 7: printf("Бразильский\n"); break;
    case 8: printf("Польский\n"); break;
    case 9: printf("Вьетнамский\n"); break;
    }
    switch (kind) {
    case 0: printf("стол\n"); break;
    case 1: printf("стул\n"); break;
    case 2: printf("стул\n"); break;
    case 3: printf("шкаф\n"); break;
    case 4: printf("шкаф\n"); break;
    case 5: printf("диван\n"); break;
    case 6: printf("диван\n"); break;
    case 7: printf("ящик\n"); break;
    case 8: printf("ящик\n"); break;
    case 9: printf("стол\n"); break;
    }
    switch (kind) {
    case 0: printf("из берёзы   "); break;
    case 1: printf("из берёзы   "); break;
    case 2: printf("из осины    "); break;
    case 3: printf("из осины    "); break;
    case 4: printf("из липы     "); break;
    case 5: printf("из липы     "); break;
    case 6: printf("из ясеня    "); break;
    case 7: printf("из ясеня    "); break;
    case 8: printf("из ели      "); break;
    case 9: printf("из ели      "); break;
    }
}

//Оперативные функции

void information(int code) {
    printf("***\n Информация о товаре :\n");
    name_printer(tcode[0], tcode[1], tcode[2], tcode[3]);
    printf("\n\nКод:    %d%d%d%d\n", tcode[0], tcode[1], tcode[2], tcode[3]);
    printf("Цена:   %d\nСкидка: %d\n***\n\n", price[code], discont[code]);
}

void adding(int code) {
    int i=0;

    added_code[number] = code;

    while (added_code[i] != code) {
        i++;
    }
    
    count[i]++;
    if ((i == number) || (number < 1)) number++;

    sum = (sum + price[code]);
    final_discont = (final_discont + (((double) discont[code]) / 100) * price[code]);
}

void printing() {
    int i;
    system("cls");
    printf("Мебельный магазин Золушка\n");
    printf("Кассир: Пупкин В.Г.\n");
    printf("\nТовар         Код   цена  количество  сумма\n\n");

    for (i = 0; i < number; i++) {
        code_translation(added_code[i]);
        name_printer(tcode[0], tcode[1], tcode[2], tcode[3]);
        printf("  %d%d%d%d  ", tcode[0], tcode[1], tcode[2], tcode[3]);
        printf("%4d  %10d  %5d\n\n", price[added_code[i]], count[i], price[added_code[i]]* count[i]);
    }

    printf("\nИтог     %lf\n", sum);
    printf("Скидка   %lf\n", final_discont);
    printf("К оплате %lf\n", sum-final_discont);
}

void main() {
    int code = 0, input = 0;
    setlocale(LC_ALL, "Russian");
    data_generation();

    printf("Сеанс запущен, сканируйте код\n");

    while (input != 4) {

        do {
            scanf("%d", &code);
        } while ((code < 1) || (code > 9999));

        system("cls");

        input = 0;

        while (input != 3) {

            printf("Чтобы вывести описание товара нажмите 1\n");
            printf("Чтобы добавить товар в чек нажмите 2\n");
            printf("Чтобы сканировать следующий товар нажмите 3\n");
            printf("Чтобы напечатать чек нажмите 4\n");

            do {
                scanf("%d", &input);
            } while ((input < 1) || (input>4));

            if (input == 1) {
                system("cls");
                code_translation(code);
                information(code);
            }
            if (input == 2)  {
                adding(code);
                system("cls");
            }
            if (input == 4) {
                printing(code);
                break;
            }

        }

    }

}