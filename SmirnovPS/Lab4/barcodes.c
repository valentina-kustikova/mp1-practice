#include <stdio.h>
#include <string.h>

#define N 10
#define NAME_LEN 20

int findProduct(char barcode[], char barcodes[][5], int count);
int equalBarcodes(char barcode1[], char barcode2[]);
void copyBarcode(char dest[], char src[]);
void inputBarcode(char barcode[]);
int scanProduct(char productBarcodes[][5], int productsCount, char barcode[], char productNames[][NAME_LEN]);
void showProductInfo(int index, char names[][NAME_LEN], int prices[], int discounts[]);
void addToCheck(int index, char barcode[], char checkBarcodes[][5], int checkAmount[], int* checkCount, char names[][NAME_LEN]);
void printCheck(char checkBarcodes[][5], int checkAmount[], int checkCount,
    char productBarcodes[][5], char names[][NAME_LEN], int prices[], int discounts[],
    int* totalCost, int* totalDiscount, int* finalCost);
void calculateFinalCost(int totalCost, int totalDiscount, int finalCost);

int main() {
    // База товаров
    char productBarcodes[N][5] = {
        "1222",
        "2333",
        "3444",
        "4555"
    };
    char productNames[N][NAME_LEN] = {
        "Milk",
        "Banana",
        "Juice",
        "Chicken"
    };
    int productPrices[N] = { 50, 25, 90, 140 };
    int productDiscounts[N] = { 10, 20, 15, 30 };
    int productsCount = 4;

    // Чек
    char checkBarcodes[N][5];
    int checkAmount[N] = { 0 };
    int checkCount = 0;

    int totalCost = 0, totalDiscount = 0, finalCost = 0;

    int i = -1;
    char barcode[5];

    printf("<CASH REGISTER>");

    int choice;
    do {
        printf("\n1. Scan and add product\n");
        printf("2. Show product info\n");
        printf("3. Add product to check\n");
        printf("4. Print check\n");
        printf("5. Calculate final amount and exit\n");
        printf("Choice: ");
        scanf_s("%d", &choice);

        // i - Последний сканированный индекс

        switch (choice) {
        case 1: {
            i = scanProduct(productBarcodes, productsCount, barcode, productNames);
            break;
        }
        case 2: {
            showProductInfo(i, productNames, productPrices, productDiscounts);
            break;
        }
        case 3: {
            addToCheck(i, barcode, checkBarcodes, checkAmount, &checkCount, productNames);
            break;
        }
        case 4: {
            printCheck(checkBarcodes, checkAmount, checkCount, productBarcodes, productNames,
                productPrices, productDiscounts, &totalCost, &totalDiscount, &finalCost);
            break;
        }
        case 5: {
            calculateFinalCost(totalCost, totalDiscount, finalCost);
            return 0;
        }

        default:
            printf("This option doesn't exist");
        }

    } while (1);
}


int findProduct(char barcode[], char barcodes[][5], int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(barcodes[i], barcode) == 0)
            return i;
    }
    return -1;
}


int equalBarcodes(char barcode1[], char barcode2[]) {
    return strcmp(barcode1, barcode2) == 0;
}


void inputBarcode(char barcode[]) {
    printf("Enter barcode (4 digits): ");
    scanf_s("%4s", barcode, 5);
}


void copyBarcode(char dest[], char src[]) {
    strcpy_s(dest, 5, src);
}


int scanProduct(char productBarcodes[][5], int productsCount, char barcode[], char productNames[][NAME_LEN]) {
    inputBarcode(barcode);
    int index = findProduct(barcode, productBarcodes, productsCount);

    if (index != -1)
        printf("Product successfully scanned: %s\n", productNames[index]);
    else
        printf("Product not found\n");

    return index;
}



void showProductInfo(int index, char names[][NAME_LEN], int prices[], int discounts[]) {
    if (index == -1) {
        printf("Scan product first\n");
        return;
    }

    printf("Product: %s\n", names[index]);
    printf("Price: %d rubles\n", prices[index]);
    printf("Discount: %d%%\n", discounts[index]);
}


void addToCheck(int index, char barcode[], char checkBarcodes[][5], int checkAmount[], int* checkCount, char names[][NAME_LEN]) {
    if (index == -1) {
        printf("Scan product first\n");
        return;
    }

    for (int j = 0; j < *checkCount; j++) {
        if (strcmp(checkBarcodes[j], barcode) == 0) {
            checkAmount[j]++;
            printf("Added to check: %s\n", names[index]);
            return;
        }
    }

    strcpy_s(checkBarcodes[*checkCount], 5, barcode);
    checkAmount[*checkCount] = 1;
    (*checkCount)++;

    printf("Added to check: %s\n", names[index]);
}



void printCheck(char checkBarcodes[][5], int checkAmount[], int checkCount,
    char productBarcodes[][5], char names[][NAME_LEN], int prices[], int discounts[],
    int* totalCost, int* totalDiscount, int* finalCost) {

    if (checkCount == 0) {
        printf("No products added yet\n");
        return;
    }

    printf("<Check>\n");
    printf("Name - Price - Amount - Total\n");

    for (int i = 0; i < checkCount; i++) {
        int j = findProduct(checkBarcodes[i], productBarcodes, N);
        if (j != -1) {
            int productTotal = prices[j] * checkAmount[i];
            int productDiscount = productTotal * discounts[j] / 100;
            int finalPrice = productTotal - productDiscount;

            printf("%s - %d - %d - %d\n", names[j], prices[j], checkAmount[i], finalPrice);

            *totalCost += productTotal;
            *totalDiscount += productDiscount;
        }
    }

    *finalCost = *totalCost - *totalDiscount;
}


void calculateFinalCost(int totalCost, int totalDiscount, int finalCost) {
    if (finalCost == 0) {
        printf("Check has not been formed yet\n");
        return;
    }

    printf("Total cost: %d rubles\n", totalCost);
    printf("Total discount: %d rubles\n", totalDiscount);
    printf("Final amount to pay: %d rubles\n", finalCost);
    printf("Thank you for your purchase!\n");
}
