#include <stdio.h>
#include <locale.h>
#define N 10

int barcode(int barcode[])
{
	int i, c;
	printf("Enter barcode from 8063 to 8072: \n");
	do
	{
		scanf_s("%d", &c);
	} while (c < 1 || c > 15);
	for (i = 0; i < N; i++)
	{
		barcode[i] == c;
		return i;
	}
}
int information(char product[][8], int c[], int p[], float s[], int b)
{
	int i;
	printf("Information: \n");
	for (i = 0; i < 8; i++)
		printf("%c", product[b][i]);
	printf(" \n");
	printf("Price: %d \n", p[b]);
	printf("Discount: %0.0f \n", s[b]);
}
void check(char product[][8], int p[], float s[], int num[], float price)
{
	int i, j;
	printf("----------------------WELCOME----------------------------\n");
	for (i = 0; i < N; i++)
	{
		if (num[i] != 0)
		{
			printf("Name: ");
			for (j = 0; j < 10; j++)
			{
				printf("%c", product[i][j]);
			}
			printf(" \n");
			printf("Cost 1 th.: %d rub. \n", p[i]);
			printf("Numbers of products %d \n", num[i]);
			printf("Discount: %0.0f \n", s[i]);
			printf("Discount price: %.2f  \n", (p[i] + (p[i] * s[i]) / 100.0) * num[i]);
		}
	}
	printf("--------------------------------------------------------\n");
	printf("Total: %.2f \n", price);
}
float sum(int p[], float s[], int b)
{
	int i;
	float sum = 0.0;
	for (i = 0; i < N; i++)
	{
		sum = (p[b] * s[b]) / 100.0 + p[b];
	}
	return sum;
}
void main()
{
	int c[N] = { 8063, 8064, 8065, 8066, 8067, 8068, 8069, 8070, 8071, 8072 };
	char product[N][8] = { "pen","pencil", "copybook", "paper", "notebook", "folder", "crayons","marker", "box", "stickers"};
	int p[N] = { 45, 12, 64, 120, 75, 97, 58, 145, 63, 34 };
	float s[N] = { 5, 2, 10, 20, 10, 15, 10, 20, 10, 5 };
	int number;
	int b;
	float price = 0;
	int barcode[] = { 0 };
	printf("1 - scan a product \n");
	printf("2 - print a check \n");
	scanf_s("%d", &number);
	switch (number)
	{
	case 1:
	{
		b = barcode[c];
		barcode[b] = barcode[b] + 1;
		information(product, c, p, s, b);
		price += sum(p, s, b);
		break;
	}
	case 2:
	{
		check(product, p, s, barcode, price);
		break;
	}
	}
}