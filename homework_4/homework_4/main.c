#include <stdio.h>
#include <string.h>
#define N 5


const char* barcode[N] = { "1234", "5678", "9012", "3456", "0012" };
const char name[N][10] = { "milk", "bread", "eggs", "water", "melon" };
const int price[N] = { 100, 130, 15, 1000, 250 };
const int sale[N] = { 10, 20, 1, 25, 50 };
int count[N] = { 0 };


int parse_barcode(int product_code, char result[5]);


int find_product_index(const char* scanned);

void show_product_info(int idx);
int confirm_add();
void print_receipt();

int main() {
    int product_code;

    while (1) {
        printf("Enter barcode (or 0 to finish): ");
        scanf_s("%d", &product_code);

        if (product_code == 0) {
            break;
        }

        char product_str[5];
        if (!parse_barcode(product_code, product_str)) {
            printf("Error: barcode must be 1 to 4 digits (no negatives)!\n");
            continue;
        }

        int idx = find_product_index(product_str);
        if (idx == -1) {
            printf("Product not found!\n");
            continue;
        }

        show_product_info(idx);

        if (confirm_add()) {
            count[idx]++;
            printf("Added to receipt.\n");
        }
        else {
            printf("Skipped.\n");
        }
    }

    print_receipt();
    return 0;
}


int parse_barcode(int product_code, char result[5]) {
    if (product_code < 0) return 0;


    char temp[12];
    sprintf_s(temp, sizeof(temp), "%d", product_code);

    int len = strlen(temp);
    if (len > 4) return 0;


    for (int i = 0; i < 4 - len; i++) {
        result[i] = '0';
    }
    strcpy_s(result + (4 - len), 5 - (4 - len), temp);
    result[4] = '\0';

    return 1;
}

int find_product_index(const char* scanned) {
    for (int i = 0; i < N; i++) {
        if (strcmp(scanned, barcode[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void show_product_info(int idx) {
    printf("Found: %s - %d rub. - %d%% \n", name[idx], price[idx], sale[idx]);
}

int confirm_add() {
    char answer;
    printf("Add to receipt? (y/n): ");
    scanf_s(" %c", &answer, 1);
    return (answer == 'y' || answer == 'Y');
}

void print_receipt() {
    int total_price = 0;
    float total_discount = 0.0f;

    printf("\nRECEIPT\n");
    for (int i = 0; i < N; i++) {
        if (count[i] > 0) {
            int item_total = count[i] * price[i];
            float item_discount = item_total * (sale[i] / 100.0f);
            float item_final = item_total - item_discount;

            printf("Name: %s\n", name[i]);
            printf("Price: %d rub. * %d = %d rub.\n", price[i], count[i], item_total);
            printf("Discount: %d%% (%.2f rub.)\n", sale[i], item_discount);
            printf("To pay: %.2f rub.\n", item_final);
            printf("------------------------\n");

            total_price += item_total;
            total_discount += item_discount;
        }
    }

    printf("TOTAL: %d rub.\n", total_price);
    printf("TOTAL DISCOUNT: %.2f rub.\n", total_discount);
    printf("TO PAY: %.2f rub.\n", total_price - total_discount);
}