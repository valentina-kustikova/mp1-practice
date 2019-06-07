#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char NAME[5][4] = { {'m', 'e', 'a', 't'}, {'m', 'i', 'l', 'k'}, {'s', 'a', 'l', 't'}, {'f', 'i', 's', 'h'}, {'e', 'g', 'g', 's'} };
int BARCODE[6] = { 0, 1254, 7789, 4790, 1515, 1313 };
int NAMEP = 0;
float PRICE[5] = { 150.0f, 75.0f, 40.0f, 250.0f, 60.0f };
int PRICEP = 0;
float SALE = 0;
float FULLPRICE = 0;
struct PProduct 
{
	char Name[4];
	float Price;
	int Quantity;
	float FullPrice;
	int BarCode;
};
typedef struct PProduct Product;
Product P[5] = {0};

void in(int bc)
{
	int i;
	srand((unsigned int)time(0));
	if (bc > 9999 || bc < 1)
	{
		//printf("Vvedeni nepravilnyi danyi");
		return;
	}
	for (i = 0; i < NAMEP; i++)
		if (bc == P[i].BarCode)
		{
			P[i].Quantity++;
			P[i].FullPrice = P[i].FullPrice + P[i].Price - P[i].Price * ((rand() * (49) / RAND_MAX + 1) / 100.0f);
			FULLPRICE += P[i].FullPrice;
			SALE += P[i].Price * ((rand() * (49) / RAND_MAX + 1) / 100.0f);
			return;
		}
	Product p;
	for (i = 0; i < 4; i++) p.Name[i] = NAME[NAMEP][i];
	NAMEP++;
	p.Price = PRICE[PRICEP];
	PRICEP++;
	p.Quantity = 0;
	p.FullPrice = p.Price - p.Price * ((rand() * (49) / RAND_MAX + 1) / 100.0f);
	FULLPRICE += p.FullPrice;
	SALE += p.Price * ((rand() * (49) / RAND_MAX + 1) / 100.0f);
	p.BarCode = BARCODE[bc];
	P[NAMEP - 1] = p;
	return;
}

void out(int bc) 
{
	int i, n;
	for (i = 0; i < NAMEP; i++) if (P[i].BarCode == bc) break;
	for (n = 0; n < 4; n++) printf("%c", P[i].Name[n]);
	printf(" - %.2f - %d - %.2f\n", P[i].Price, P[i].Quantity, P[i].FullPrice);
}


void main()
{
	int i = 0;
	for (i; i < 6; i++) in(i);
	i = 1;
	while(i != 0)
	{
		printf("Enter Barcode Product Code\n");
		printf("If you want to exit, enter 0\n");
		scanf("%d", &i);
		in(i);
		out(i);
	}
	printf("\n");
	printf("Full Sale - %.2f\n", SALE);
	printf("Full Price - %.2f", FULLPRICE);
}

