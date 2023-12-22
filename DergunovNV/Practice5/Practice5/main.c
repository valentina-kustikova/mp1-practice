#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5
#define MAX_LEN 255

char* barcodes[N] = { "1212", "0101" , "2323" , "2424" , "5454" };
char* names[N] = { "Tea", "Milk", "Bread", "Eggs", "Apples" };
float price[N] = { 150.f, 100.f, 105.f, 100.f, 120.f };
float discout[N] = { 0.15f, 0.20f, 0.0f, 0.25f, 0.10f };

int check(int *barcode,int *amount) {
    int i = 0;
    for (i; i < N; i++) {
        if (strcmp(barcode, barcodes[i]) == 0) {
            printf("NAME:%s\nPRICE:%.2f rubles\nDISCOUNT:%.2f\n", names[i], price[i], discout[i]);
            amount[i]++;
            return i;
        }
    }
    if (strcmp(barcode, "result") != 0) printf("Wrong!\n");
    return -1;
}
void finalcheck(int* amount) {
    float check = 0;
    printf("===Total check===\n");
    for (int i = 0; i < N; i++) {
        if (amount[i] != 0) {
            printf(("%s, price(with discount) - %.2f\n%d(count).\n"), names[i], (price[i] * (1.f - (discout[i] / 100.f))), amount[i]);
        }
        check += (price[i] * (1.f - (discout[i] / 100.f))) * amount[i];
    }
    printf("Total cost - %.2f", check);
}

int main() {
    int count[N] = { 0 };
    char barcode[MAX_LEN] = " ";
    int i = 0;
    int amount[N] = { 0 };
    printf("===CASH===\n");
    do {
        printf("Enter a barcode or write (result) if you want to sum it up: \n");
        scanf("%s", barcode);
        i = check(barcode,amount);
    } while (strcmp(barcode, "result") != 0);
    finalcheck(amount);
    return 0;
}

