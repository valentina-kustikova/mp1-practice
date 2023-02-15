#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

char* barcodes[N] = { "1010","2020","3030","4040","5050","6060","7070","8080","9090","1111" };
char* products[N] = { "Asus","Lenovo","InVidia","Apple","Blackberry","Hp","Acer","Honor","Infinix","Digma" };
int price_for_one_item[N] = { 100,110,120,130,140,150,160,170,180,190 };
float discount[N] = { 0.04,0.04,0.06,0.07,0.08,0.09,0.1,0.11,0.12,0.13 };

void Scan(int* arr)
{
	int i;
	int flag;
	float price_with_discount;
	char a[5];
	printf("====================\n");
	printf("WELCOME TO MY KASSA!\nLets start scanning your barcodes\nEnter 0 to print check.\n");
	do {
		printf("Enter your barcode\n");
		gets(a);
		flag = 0;
		for (i = 0; i < N; i++)
		{
			if (strcmp(barcodes[i], a) == 0)
			{
				arr[i]++;
				price_with_discount = price_for_one_item[i] - (discount[i] * price_for_one_item[i]);
				printf("Beep!!! \n %s Price: %.2d rubles Discount: %.2f Final Price is %.2f rubles\n", products[i], price_for_one_item[i], discount[i] * 100, price_with_discount);
				flag = 1;
			}
		}
		if ((flag == 0) && (strcmp(a, "0") != 0))
		{
			printf("It looks like you entered the barcode wrong\nThere should be 4 digits");
		}

	} while (strcmp(a, "0"));
}
void Print_check(int* array)
{
	int i, Price_Without_Discount = 0;

	float Summa_discounts = 0, Totally_summa = 0, PriceDDisk;
	for (i = 0; i < N; i++)
	{
		if (array[i] > 0)
		{
			Price_Without_Discount = price_for_one_item[i] * array[i] + Price_Without_Discount;
			PriceDDisk = (price_for_one_item[i] - price_for_one_item[i] * discount[i]) * array[i];
			Totally_summa = Totally_summa + PriceDDisk;
			Summa_discounts = Summa_discounts + (price_for_one_item[i] * discount[i]) * array[i];
			printf("%10s: Price: %d, Count Products: %d, Price with discount: %.2f\n", products[i], price_for_one_item[i], array[i], PriceDDisk);
		}
	}
	printf("\n \n");
	printf("====================================================================");
	printf("\t\nPrice: %d Rubles, Discounts: %.2f Rubles, Amount Payable: %.2f\n", Price_Without_Discount, Summa_discounts, Totally_summa);
	printf("====================================================================");
	printf("\n \n");
}
int main()
{
	int Basket[N] = { 0 };
	Scan(Basket);
	Print_check(Basket);
	return 0;
}