#include <stdio.h>
#include <string.h>

#define N 10
#define NAME_LEN 20

void listProducts(int barcodes[][4], char names[][NAME_LEN], int prices[], int discounts[]);
int findProduct(int barcode[4], int barcodes[][4], int count);
int equalBarcodes(int barcode1[4], int barcode2[4]);
void copyBarcode(int barcode1[4], int barcode2[4]);
void inputBarcode(int barcode[4]);


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

    // Работа с товарами
    int choice;
    do {
        printf("\n1. Scan and add product\n");
        printf("2. Show product info\n");
        printf("3. Add product to check\n");
        printf("4. Print check\n");
        printf("5. Calculate final amount and exit\n");
        printf("Choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: {
            inputBarcode(barcode);

            i = findProduct(barcode, productBarcodes, productsCount);
            if (i != -1) {
                printf("Product successfully scanned: %s\n", productNames[i]);
            }
            else
                printf("Product not found");
            break;
        }
        case 2: {
            if (i != -1) {
                printf("Product: %s\n", productNames[i]);
                printf("Price: %d rubles\n", productPrices[i]);
                printf("Discount: %d%%\n", productDiscounts[i]);
            }
            else
                printf("No scanned products before\n");
            break;
        }
        case 3: {
            if (i != -1) {
                int exists = 0;
                int j = 0;
                for (j; j < checkCount; j++) {
                    if (equalBarcodes(checkBarcodes[j], barcode)) {
                        checkAmount[j]++;
                        exists = 1;
                        printf("Added to check: %s\n", productNames[i]);
                        break;
                    }
                }

                if (exists == 0 && checkCount < N) {
                    int k = 0;
                    for (k; k < 4; k++)
                        checkBarcodes[checkCount][k] = barcode[k];
                    checkAmount[checkCount] = 1;
                    checkCount++;
                    printf("Added to check: %s\n", productNames[i]);
                }
                if (checkCount >= N)
                    printf("Check is full\n");
            }
            break;
        }
        case 4: {
            if (checkCount == 0) {
                printf("No products added yet");
                break;
            }

            printf("<Check>\n");
            printf("Name - Price - Amount - Total\n");

            int i;
            for (i = 0; i < checkCount; i++) {
                int j = findProduct(checkBarcodes[i], productBarcodes, productsCount);
                if (j != -1) {
                    int productTotal = productPrices[j] * checkAmount[i];
                    int productDiscount = productTotal * productDiscounts[j] / 100;
                    int finalPrice = productTotal - productDiscount;

                    printf("%s - %d - %d - %d\n", productNames[j], productPrices[j], checkAmount[i], finalPrice);

                    totalCost += productTotal;
                    totalDiscount += productDiscount;
                }
            }

            finalCost = totalCost - totalDiscount;
            break;
        }
        case 5: {
            if (finalCost != 0) {
                printf("Total cost: %d rubles\n", totalCost);
                printf("Total discount: %d rubles\n", totalDiscount);
                printf("Final amount to pay: %d rubles\n", finalCost);
                printf("Thank you for your purchase!\n");
                return 0;
            }
            else
                printf("Check has not been formed yet");
            break;
        }
        default:
            printf("This option does not exist");
        }
    } while (1);
}

// База данных
void listProducts(int barcodes[][4], char names[][NAME_LEN], int prices[], int discounts[]) {
    // Товар 1: Milk
    barcodes[0][0] = 1; barcodes[0][1] = 2; barcodes[0][2] = 2; barcodes[0][3] = 2;
    strcpy_s(names[0], NAME_LEN, "Milk");
    prices[0] = 50;
    discounts[0] = 10;
    
    // Товар 2: Banana
    barcodes[1][0] = 2; barcodes[1][1] = 3; barcodes[1][2] = 3; barcodes[1][3] = 3;
    strcpy_s(names[1], NAME_LEN, "Banana");
    prices[1] = 25;
    discounts[1] = 20;

    // Товар 3: Juice
    barcodes[2][0] = 3; barcodes[2][1] = 4; barcodes[2][2] = 4; barcodes[2][3] = 4;
    strcpy_s(names[2], NAME_LEN, "Juice");
    prices[2] = 90;
    discounts[2] = 15;

    // Товар 4: Chicken
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