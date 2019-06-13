#include <stdio.h>
#include <locale.h>
#define N 1000

int sum = 0, final_summ = 0, final_discont = 0, number = 0;
int discont [N], price [N];
char name [N] [100];
int added_code [N], count [N];

void information(int code) {
    printf("\n***\n Информация о товаре");
    printf("Номер: %d\n Цена: %d\n Скидка: %d\n***\n",code, price[code], discont[code]);
}

void adding(int code) {
    int i,search;
    
    added_code[number] = code;

    while (1) {
        if (added_code[i] == code) {
            search = i;
            break;
        }
        i++;
    }

    if (search = number) {
        count[number] = 1;
        number++;
    }
    else {
        added_code[number] = 0;
        count[search]++;
    }

}

void printing() {

}

void main() {
    int code=0, input=0;
    setlocale(LC_ALL, "Russian");
    
    printf("Сеанс запущен, сканируйте код\n");
    
    while (input != 4) {
    
        do {
            scanf("%d", &code);
        } while ((code < 1) || (code > 9999));

        input = 0;

        while (input != 3) {

            printf("Чтобы вывести описание товара нажмите 1\n");
            printf("Чтобы добавить товар в чек нажмите 2\n");
            printf("Чтобы сканировать следующий товар нажмите 3\n");
            printf("Чтобы напечатать чек нажмите 4\n");

            do {
                scanf("%d", &input);
            } while ((input < 1) || (input>4));

            if (input == 1) information(code);
            if (input == 2) adding(code);
            if (input == 4) printing(code);

        }

    }

}