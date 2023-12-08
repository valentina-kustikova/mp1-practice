#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define n 13


// using data
char codes[n][5];
char* names[n] = { "Banana","Crisps","Chicken","Garlic",
    "Garlic Bread","Vine","Snickers","Coconuts","Milk",
    "Cheese","Ferrero Rocher","Kinder","Rice(500g)" };
double prices[n] = { 12,67,320,5,34,3238,56,16,245,143,1199,62,136 };
double discounts[n];
int check[n];



void make_codes();
// создаёт штрих-коды

void make_discounts();
// создаёт скидки

void print_product(int i);
// выводит информацию о продукте

void ask_and_add(int i);
// спрашивает пользователя
// о желании добавиь продукт в чек

void check_code(char* code);
// проверяет штрих-код
// на существование в data

void print_fmsg(int snd, int s);
// выводит последнее сообщение

void fill_check();
// заполняет чек




int main() {
    int i;
    system("chcp 1251");

    make_codes();
    // содаёт штрих-коды
    
    make_discounts();
    // создаёт скидки

    
    // сообщение о начале работы программы
    printf("-------------------\n");
    printf("Введите код продукта\n");
    


    // цикл работы программы
    while (1) {
        char code[5];
        char ans[10];
        
        i = 0;

        // вводится штрих-код
        scanf("%s", &code); 
        
        // проверяется штрих-код
        check_code(&code);      
        
        printf("Будем ещё добавлять товары? да/нет\n");
        
        scanf("%10s", &ans);
        if (strcmp(ans, "нет") == 0) {
            printf("\n\t\tВаш чек:\n\n");                           
            fill_check();
            return 0;
        }
        
        printf("Введите код очередного товара\n");    
        
    }

    return 0;
}


void make_codes() {
    int i = 0;
    for (i = 0; i < n; i++) {
        sprintf(codes[i], "%04d", i + 1);
        // преобразовывает число i+1 в строку
        // с форматом %04d (строку длиной в 4 символа)
        // если число меньше 4 символов,
        // то функция дополняет число нулями спереди
        // до длины в 4 символа

        // функция возвращает не только строку,
        // но и символ \0 (конец строки)
        // поэтому матрица с 5 столбцами,а не 4
    }
}


void make_discounts() {
    int i;
    srand((unsigned int)time(0)); // создание скидок
    for (i = 0; i < n;i++) {
        discounts[i] = ((1 + (rand() % 50)) * 0.01);
    }
}

void print_product(int i) {
    printf("%s - %.0lf руб/шт - %.0lf%% скидка \n",
        names[i], prices[i], discounts[i] * 100);
}


void ask_and_add(int i) {
    char ans[10];
    printf("Добавить в чек? да/нет\n");
    scanf("%10s", &ans);
    char* ptr = strstr(ans, "да");
    if (ptr != NULL) {
        int skoka;
        printf("Сколько добавить?\n");
        scanf("%d", &skoka);
        check[i] += skoka;
        printf("Добавлено %d штук\n", skoka);
    }
}

void check_code(char* code) {
    int i = 0;

    for (; i < n;i++) {
        if (strcmp(codes[i], code) == 0) {
            print_product(i);
            ask_and_add(i);
            return;
        }
    }

    if ((i == n) && strcmp(codes[n - 1], code) != 0) {
        printf("Под таким кодом товар отсутствует\n");
    }

}



void print_fmsg(double snd, double s) {
    printf("\nВсего к оплате: %.0lf руб\n", snd);
    printf("С учетом скидки (%.2lf%%): %.0lf руб\n",
        (1.0 - (s * 1.0 / snd)) * 100, s);
    printf("\tПриходите к нам ещё ! <3 \n");
    printf("\n\n-------------------");
}

void fill_check() {
    int snd = 0; // summa no discount
    int s = 0; // summa with discount
    int i = 0;
    for (;i < n; i++) {
        if (check[i] != 0) {

            printf("%s - %.0lf руб/шт - %d штук - %.0lf общая стоимость \n",
                names[i], prices[i], check[i],
                prices[i] * check[i] * (1.0 - discounts[i]));

            snd += prices[i] * check[i];
            s += prices[i] * check[i] * (1.0 - discounts[i]);

        }
       
    }
    print_fmsg(snd, s); // выводит последнее сообщение
}