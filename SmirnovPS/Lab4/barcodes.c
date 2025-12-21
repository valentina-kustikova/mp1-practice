#include <stdio.h>
#include <string.h>

#define N 10
#define NAME_LEN 20

void listProducts(int barcodes[][4], char names[][NAME_LEN], int prices[], int discounts[]);
int findProduct(int barcode[4], int barcodes[][4], int count);
int equalBarcodes(int barcode1[4], int barcode2[4]);
void copyBarcode(int barcode1[4], int barcode2[4]);
void inputBarcode(int barcode[4]);
int scanProduct(int productBarcodes[][4], int productsCount, int barcode[4], char productNames[][NAME_LEN]);
void showProductInfo(int index, char names[][NAME_LEN], int prices[], int discounts[]);
void addToCheck(int index, int barcode[4], int checkBarcodes[][4], int checkAmount[], int* checkCount, char names[][NAME_LEN]); 
void printCheck(int checkBarcodes[][4], int checkAmount[], int checkCount, int productBarcodes[][4], char names[][NAME_LEN], 
    int prices[], int discounts[], int* totalCost, int* totalDiscount, int* finalCost); 
void calculateFinalCost(int totalCost, int totalDiscount, int finalCost);

int main() {
    // База товаров
    int productBarcodes[N][4];
    char productNames[N][NAME_LEN];
    int productPrices[N];
    int productDiscounts[N];
    int productsCount = 4;

    // Чек
    int checkBarcodes[N][4];
    int checkAmount[N] = { 0 };
    int checkCount = 0;

    int totalCost = 0, totalDiscount = 0, finalCost = 0;

    int i = -1;
    int barcode[4];

    listProducts(productBarcodes, productNames, productPrices, productDiscounts);

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

// База данных
void listProducts(int barcodes[][4], char names[][NAME_LEN], int prices[], int discounts[]) {
    barcodes[0][0] = 1; barcodes[0][1] = 2; barcodes[0][2] = 2; barcodes[0][3] = 2;
    strcpy_s(names[0], NAME_LEN, "Milk");
    prices[0] = 50;
    discounts[0] = 10;


    barcodes[1][0] = 2; barcodes[1][1] = 3; barcodes[1][2] = 3; barcodes[1][3] = 3;
    strcpy_s(names[1], NAME_LEN, "Banana");
    prices[1] = 25;
    discounts[1] = 20;


    barcodes[2][0] = 3; barcodes[2][1] = 4; barcodes[2][2] = 4; barcodes[2][3] = 4;
    strcpy_s(names[2], NAME_LEN, "Juice");
    prices[2] = 90;
    discounts[2] = 15;


    barcodes[3][0] = 4; barcodes[3][1] = 5; barcodes[3][2] = 5; barcodes[3][3] = 5;
    strcpy_s(names[3], NAME_LEN, "Chicken");
    prices[3] = 140;
    discounts[3] = 30;

}


int findProduct(int barcode[4], int barcodes[][4], int count) {
    int i;
    for (i = 0; i < count; i++) {
        if (equalBarcodes(barcodes[i], barcode) == 1) {
            return i;
        }
    }
    return -1;
}


int equalBarcodes(int barcode1[4], int barcode2[4]) {
    int i;
    for (i = 0; i < 4; i++) {
        if (barcode1[i] != barcode2[i]) {
            return 0;
        }
    }
    return 1;
}

void inputBarcode(int barcode[4]) {
    printf("Enter barcode: 4 digits\n");
    int i;
    for (i = 0; i < 4; i++) 
        scanf_s("%1d", &barcode[i]);
}


void copyBarcode(int barcode1[4], int barcode2[4]) {
    int i;
    for (i = 0; i < 4; i++) 
        barcode1[i] = barcode2[i];
}


int scanProduct(int productBarcodes[][4], int productsCount, int barcode[4], char productNames[][NAME_LEN]) {
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


void addToCheck(int index, int barcode[4], int checkBarcodes[][4], int checkAmount[], int* checkCount, char names[][NAME_LEN]) {
    int j;
    if (index == -1) {
        printf("Scan product first\n");
        return;
    }

    for (j = 0; j < *checkCount; j++) {
        if (equalBarcodes(checkBarcodes[j], barcode)) {
            checkAmount[j]++;
            printf("Added to check: %s\n", names[index]);
            return;
        }
    }

    if (*checkCount < N) {
        for (j = 0; j < 4; j++)
            checkBarcodes[*checkCount][j] = barcode[j];

        checkAmount[*checkCount] = 1;
        (*checkCount)++;

        printf("Added to check: %s\n", names[index]);
    }
    else {
        printf("Check is full\n");
    }
}


void printCheck(int checkBarcodes[][4], int checkAmount[], int checkCount,
    int productBarcodes[][4], char names[][NAME_LEN], int prices[], int discounts[],
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
