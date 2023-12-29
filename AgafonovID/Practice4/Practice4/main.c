#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N 10
#define MAX_LEN 255

char* barcodes[N] = { "9968", "5880", "1943", "9901", "5733", "7826", "4861", "2469", "5990", "1284" };
char* product[N] = { "Хлеб", "Молоко", "Яйца", "Сыр",  "Сахар", "Курица", "Макароны", "Масло", "Яблоки", "Чай" };
float price[N] = { 30.f, 60.f, 90.f, 200.f, 90.f, 300.f, 60.f, 100.f, 70.f, 120.f };
float discounts[N] = { 0.f, 5.f, 12.f, 15.f, 10.f, 8.f, 30.f, 23.f, 45.f, 35.f };

char* receipt_products[N];
float prices[N];
int quantity_products[N];
float amount[N];

int attempts = 1, i = 0;

int barcode_verification(char* code);

void scan_product();

void add_receipt(int id);

void generate_receipt(int id, int quantity, float cost);

void print_receipt();


int main() {
    setlocale(LC_ALL, "Rus");
    scan_product();
    return 0;
}

int barcode_verification(char* code) {
    int i;
    for (i = 0; i < N; i++) {
        if (strcmp(barcodes[i], code) == 0) {
            return i;
        }
    }
    return -1;
}

void scan_product() {
    char code[MAX_LEN];
    int i, id, incorrect = 1;
    while (incorrect) {
        printf("Введите штрихкод: \n");
        scanf("%s", code);
        id = barcode_verification(code);
        if (id != -1) {
            incorrect = 0;
        }
    }
    printf("Товар: %s, цена: %.0f, скидка: %.0f%%\n", product[id], price[id], discounts[id]);
    add_receipt(id);
}

void add_receipt(int id) {
    int quantity, add;
    float cost;
    printf("Добавить товар?(1 - да, 0 - нет)\n");
    scanf("%d", &add);
    while (add > 1 || add < 0) {
        printf("Неверный ответ\n");
        scanf("%d", &add);
    }
    if (add == 1) {
        printf("Количество товара: \n");
        scanf("%d", &quantity);
        cost = (price[id] - (price[id] * (discounts[id] / 100))) * quantity;
        generate_receipt(id, quantity, cost);
    }
    else if (add == 0) {
        scan_product();
    }
}

void generate_receipt(int id, int quantity, float cost) {
    int end, flag = 0;
    printf("Товар: %s, цена за 1 шт: %.2f, количество: %d, сумма: %.2f\n", product[id], price[id], quantity, cost);
    for (int j = 0; j < i; j++) {
        if (strcmp(product[id], receipt_products[j]) == 0) {
            quantity_products[j] += quantity;
            amount[j] += cost;
            flag = 1;
            attempts--;
            break;
        }
    }
    if (flag == 0) {
        receipt_products[i] = product[id];
        prices[i] = price[id];
        quantity_products[i] = quantity;
        amount[i] = cost;
    }
    printf("Продолжить покупку?(1 - да, 0 - нет)\n");
    scanf("%d", &end);
    while (end > 1 || end < 0) {
        printf("Неверный ответ\n");
        scanf("%d", &end);
    }
    if (end == 1) {
        i++;
        attempts++;
        scan_product();
    }
    else if (end == 0) {
        print_receipt();
    }
}

void print_receipt() {
    float sum = 0;
    printf("\t Ваш чек за покупку:\n");
    for (i = 0; i < attempts; i++) {
        printf("Товар: %s, стоимость за 1 шт: %.2f, количество: %d, сумма: %.2f\n", receipt_products[i], prices[i], quantity_products[i], amount[i]);
        sum += amount[i];
    }
    printf("Итоговая сумма: %.2f", sum);
}