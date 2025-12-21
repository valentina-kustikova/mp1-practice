#include <stdio.h>
#include <string.h>
#include <locale.h>
#define K 5


char shtrixtov[K][5] = { "1111", "2222", "3333", "4444", "5555" };
char nazvanie[K][7] = { "Cheese", "Cake", "Curd", "Meat", "Tea" };
int kol[K] = { 0 };
int tsena[K] = { 1000, 500, 2000, 700, 250 };
int skidka[K] = { 10, 5, 15, 7, 2 };

int scan_and_process_product();
int find_product_index(const char* barcode);
void show_product_info(int index);
int add_product();
void print_chek();
void clear_input_buffer();

int main() {
    setlocale(LC_ALL, "Russian");

    printf("=== КАССОВЫЙ АПАРАТ ===\n");
    while (1) {
        if (!scan_and_process_product()) {
            break;
        }
    }

    print_chek();

    return 0;
}


int scan_and_process_product() {
    char basket[5];
    int product_index;

    printf("\nВведите штрихкод товара (1111-5555) или 0 для завершения: ");
    scanf_s("%4s", basket, (unsigned)sizeof(basket));
    clear_input_buffer();

    if (strcmp(basket, "0") == 0) {
        return 0;
    }

    product_index = find_product_index(basket);

    if (product_index == -1) {
        printf("Товар с штрих-кодом %s не найден!\n", basket);
        return 1;
    }

    show_product_info(product_index);

    if (add_product()) {
        kol[product_index]++;
        printf("Товар добавлен в корзину.\n");
    }
    else {
        printf("Товар не добавлен.\n");
    }

    return 1;
}

int find_product_index(const char* barcode) {
    for (int i = 0; i < K; i++) {
        if (strcmp(barcode, shtrixtov[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void show_product_info(int index) {
    printf("\n=== НАЙДЕН ТОВАР ===\n");
    printf("Название: %s\n", nazvanie[index]);
    printf("Цена: %d руб.\n", tsena[index]);
    printf("Скидка: %d%%\n", skidka[index]);
    printf("===================\n");
}


int add_product() {
    int choice;

    printf("\nДобавить товар в чек?\n");
    printf("1 - Да, добавить\n");
    printf("0 - Нет, пропустить\n");
    printf("Ваш выбор: ");

    scanf_s("%d", &choice);
    clear_input_buffer();
    if (choice == 1) {
        return 1;
    }
    else {
        return 0;
    }
}


void print_chek() {
    int total_sum = 0;
    float total_discount = 0.0f;

    printf("\n================================\n");
    printf("          ВАШ ЧЕК\n");
    printf("================================\n\n");

    for (int i = 0; i < K; i++) {
        if (kol[i] > 0) {
            int item_total = kol[i] * tsena[i];
            float item_discount = item_total * (skidka[i] / 100.0f);

            printf("%s\n", nazvanie[i]);
            printf("  Цена: %d руб. x %d шт. = %d руб.\n",
                tsena[i], kol[i], item_total);
            printf("  Скидка: %d%% = %.2f руб.\n",
                skidka[i], item_discount);
            printf("  ----------------------------------\n");

            total_sum += item_total;
            total_discount += item_discount;
        }
    }

    printf("\n================================\n");
    printf("ИТОГО:\n");
    printf("================================\n");
    printf("Общая сумма: %d руб.\n", total_sum);
    printf("Сумма скидок: %.2f руб.\n", total_discount);
    printf("К оплате: %.2f руб.\n", total_sum - total_discount);
    printf("================================\n\n");
    printf("Спасибо за покупку!\n");
}

void clear_input_buffer() {
    while (getchar() != '\n');
}