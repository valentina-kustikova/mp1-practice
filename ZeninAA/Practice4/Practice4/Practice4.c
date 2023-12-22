#include <stdio.h>
#include <string.h>

#define N_SYMBOLS 5
#define N_PRODUCTS 12

char* products[N_PRODUCTS] = { "Bread", "Milk", "Cheese", "Butter", "Water", "Buiscuits",
                               "Juice", "Lemonade", "Milk chocolate bar", "Sour cream",
                               "Mars", "Nutella" };

char* barcodes[N_PRODUCTS] = { "0001", "0002", "0003", "0004", "0005", "0006", 
                               "0007", "0008", "0009", "0010", "0011", "0012" };

float prices[N_PRODUCTS] = { 60.f, 95.f, 650.f, 140.f, 35.f, 115.f, 120.f, 106.f, 150.f, 90.f, 65.f, 460.f };

float discounts[N_PRODUCTS] = { 30.f, 0.f, 0.f, 20.f, 0.f, 0.f, 50.f, 0.f, 40.f, 0.f, 0.f, 10.f };

int receipt[N_PRODUCTS] = { 0 };

float totalDiscount = 0, finalAmount = 0;

int scan_product(char* barcode);
void input_barcodes();
void print_receipt();
void print_final_Amount();

void main()
{
    input_barcodes();
    print_receipt();
    print_final_Amount();
}

int scan_product(char* codes)
{
    int i = 0;
    for (; i < N_PRODUCTS; i++)
    {
        if (strcmp(codes, barcodes[i]) == 0) 
            return i;
    }
    return -1;
}

void input_barcodes()
{
    int choice = 0, quant = 0;
    do
    {
        int l;
        char code[N_SYMBOLS];
        printf("Input the barcode, please: \n");
        scanf("%s", code);
        printf("Input quantity: ");
        scanf("%d", &quant); 
        printf("Do you want to exit the shop? (1 - no, 2 - yes)\n");
        scanf("%d", &choice); 
        if ((choice != 1) && (choice != 2)) { 
            do { 
                printf("Error\n"); 
                scanf("%d", &choice);
            } while ((choice != 1) && (choice != 2));
        }
        l = scan_product(code); 
        if (l < 0)
        {
            printf("Product not found\n");
            continue;
        }
        receipt[l]+= quant;  
    } while (choice == 1);
}

void print_receipt()
{
    int i;
    for (i = 0; i < N_PRODUCTS; i++)
    {
        if (receipt[i] != 0)
        {
            printf("\nProduct: %s\n", products[i]);
            printf("Price per unit: %lf. \nDiscount: %lf. \nQuantity: %d. \nTotal amount: %f\n",
                prices[i], discounts[i], receipt[i], prices[i] * ((100 - discounts[i]) / 100) * receipt[i]);
        }
    }
}

void print_final_Amount()
{
    int i;
    for (i = 0; i < N_PRODUCTS; i++)
    {
        if (receipt[i] != 0)
        {
            totalDiscount += prices[i] - (prices[i] * ((100 - discounts[i]) / 100) * receipt[i]);
            finalAmount += prices[i] * receipt[i] * ((100 - discounts[i]) / 100);
            
        }
    }
    printf("\nYour amount to pay: %.2f\n", finalAmount);
    printf("We will be glad to see you again.\n");
}
 




