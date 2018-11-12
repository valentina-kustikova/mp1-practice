#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define ITEMS 5   // количество товаров в базе
#define RITEMS 100  // макс. количество записей в чеке
#define NAME_SYM_MAX 4

char codes[ITEMS][4] = { '0001', '1234', '4385', '7998', '6914' };
char names[ITEMS][NAME_SYM_MAX] = { 'ХЛЕБ', 'МЛКО', 'ЧАЙ ', 'САХР', 'КОФЕ' };
int  price[ITEMS]    = { 5, 10, 50, 30, 50 };
int  sales[ITEMS]    = { 0 };
int  recp[RITEMS];
int  recs = 0;

void scan();
int  find_by_code(char code[4]);
void print_info(int id);
void add(char code[4]);
void compose();
int  sum();

void main()
{
    setlocale(LC_ALL, "Russian");
    scan();
}

void scan()
{
    char i, code[4], id;
    printf("Введите код товара: ");
    for (i = 0; i < 4; i++) {
        scanf("%c", code[i]);
    }
    id = find_by_code(code);
    if (id == -1) {
        printf("Товар не найден\n");
    }
    else {
        print_info(id);
    }
}

int find_by_code(char code[4])
{
    int i;
    for (i = 0; i < ITEMS; i++) {
        if (codes[i] == code) break;
    }
    if (i == ITEMS) {
        return -1;
    }
    else {
        return i;
    }
}

void print_info(int id)
{
    int i;
    printf("Наименование товара: ");
    for (i = 0; i < NAME_SYM_MAX; i++) {
        printf("%c", names[id][i]);
    }
}

void add(char code[4])
{
    int id = find_by_code(code);
    if (code == -1) {
        printf("Неверный код.\n");
    }
    else {
        recp[recs] = id;
        recs++;
    }
}

void compose()
{
    if (recs == 0) {
        printf("Чек пустой.\n");
    }
    else {
        int i;
        for (i = 0; i < recs; i++) {
            print_info(recp[i]);
            printf("\n");
        }
    }
}

int sum()
{
    int S = 0, i;
    for (i = 0; i < recs; i++) {
        S += price[recp[i]] * (1 - sales[recp[i]] / 100);
    }
    return S;
}
