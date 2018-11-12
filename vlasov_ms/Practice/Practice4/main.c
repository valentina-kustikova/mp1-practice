#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define ITEMS_IN_DB 5      // количество товаров в базе
#define REC_ITEMS_MAX 100  // макс. количество записей в чеке
#define NAME_SYM_MAX 4     // макс. количество символов в наименовании
#define CODE_SYM_MAX 4     // макс. количество символов в коде

char codes[ITEMS_IN_DB][4] = { '0001', '1234', '4385', '7998', '6914' };
char names[ITEMS_IN_DB][NAME_SYM_MAX] = { 'ХЛЕБ', 'МЛКО', 'ЧАЙ ', 'САХР', 'КОФЕ' };
int  price[ITEMS_IN_DB]    = { 5, 10, 50, 30, 50 };
int  sales[ITEMS_IN_DB]    = { 0 };
int  recp[REC_ITEMS_MAX];
int  recs = 0;

void scan();
int  find_by_code(char code[]);
void print_info(int id);
void add(char code[]);
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

int find_by_code(char code[])
{
    int i;
    for (i = 0; i < ITEMS_IN_DB; i++) {
        if (codes[i] == code) break;
    }
    if (i == ITEMS_IN_DB) {
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

void add(char code[])
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
