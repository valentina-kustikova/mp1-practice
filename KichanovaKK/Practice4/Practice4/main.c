#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define n 8
#define MAX_LEN 255

char* names[n] = { "eggs","Kinder","Lemonade","Mars","Sandwich","Snickers","Chips","Doshirak"};
double prices[n] = { 120.0, 100.0, 140.0, 60.0, 200.0, 60.0, 100.0, 70.0};
char* codes[n] = { "1234", "5580", "8932", "1108", "7051", "9602", "4306", "3947" };
double discount[n] = { 35.0, 5.0, 10.0, 50.0, 0.0, 15.0, 0.0, 5.0 };
int check[n];

int idx(char* barcode);
void entercodes();
void printcheck();
void total();

int main()
{
    entercodes();
    printcheck();
    total();
    return 0;
}

int idx(char* barcode) {
    int i;
    for (i = 0; i < n; i++)
    {
        if (strcmp(barcode, codes[i]) == 0)
            return i;
    }
    return -1;
}

void entercodes()
{
    int con;
    do
    {
        int id;
        char barcode[MAX_LEN];
        printf("Input the barcode: \n");
        scanf("%s", barcode);
        id = idx(barcode);
        if (id < 0)
        {
            printf("Incorrect barcode\n");
            continue;
        }
        printf("Continue?\n");
        scanf("%d", &con);
        check[id]++;
    } while (con == 1);
}

void printcheck()
{
    int j;
    for (j = 0; j < n; j++)
    {
        if (check[j] != 0)
        {
            printf("Name: %s. Price: %.2lf. Discount: %.2lf. Amount: %d. Total price: %.2f\n",
                names[j], prices[j], discount[j], check[j], prices[j] * ((100.0 - discount[j]) * 0.01) * check[j]);

        }
    }
}

void total()
{
    double todiscount = 0, toprice = 0;
    int l;
    for (l = 0; l < n; l++)
    {
        if (check[l] != 0)
        {
            todiscount += prices[l] * (discount[l] * 0.01) * check[l];
            toprice += prices[l] * ((100.0 - discount[l]) * 0.01) * check[l];
        }
    }
    printf("Total discount: %lf. Total price: %lf", todiscount, toprice);
}
