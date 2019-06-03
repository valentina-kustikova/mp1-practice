#include <stdio.h> 
#define N 10 

int shtrih(int sh1[])
{
	int i, flag = 0, sh, sht2, sht;
	printf("Enter shtrih-cod: \n ");
	scanf("%d", &sht);
	for (i = 0; i < N; i++)
	{
		if (sh1[i] == sht)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return i;

	return -1;

}
void product(char name[][6], int price[], float sale[], int a)
{
	int i;
	printf("Your product: ");
	for (i = 0; i < 6; i++)
		printf("%c", name[a][i]);
	printf("\n\nCost: %d \n", price[a]);
	printf("\nSale: %0.0f%% \n", sale[a]);
}
float sum(int price[], float sale[], int a)
{
	int i;
	double sum = 0.0;
	for (i = 0; i < N; i++)
		sum = (1 - sale[a] / 100.0) * price[a];
	return sum;

}
void output_check(char name[][6], int price[], float sale[], int count[], float total)
{
	int i, j;
	printf(" OOO Prosto Kassa\n");
	printf("----------------------------------\n");
	printf("----------------------------------\n");
	printf(" Name Cost Count Sale Discount Price \n");
	for (j = 0; j < N; j++)
	{
		if (count[j] != 0)
		{
			for (i = 0; i < 6; i++)
				printf("%c", name[j][i]);
			printf("  ");
			printf("%d    ", price[j]);
			printf("%d it.  ", count[j]);
			printf("%0.0f   ", sale[j]);
			printf("%.2f \n", (1 - sale[j] / 100.0) * price[j]);
		}
	}
	printf("\n----------------------------------\n");
	printf("TOTAL: %.2f \n", total);
}
void Menu()
{
	printf("--------MENU------— \n");
	printf("1. display product information or add one more product\n");
	printf("2. show check \n");
}
void main()
{
	int a;
	int fill_shtrih[100] = { 0 };
	int sh[N] = { 1111 , 2222 , 3333 , 4444 , 5555 , 6666 , 7777 , 8888 , 9999 , 1234 };
	char name[N][6] = { "bread" , "meat" , "fish", "egg" , "milk", "potato", "butter",
		"apple", "salt", "cheese" };
	int price[N] = { 20, 34, 54, 12, 65, 52, 76, 46, 19, 95 };
	float sale[N] = { 5, 15, 5, 20, 10, 35, 20, 40, 10, 25 };
	float total = 0;
	int menu;
	do
	{
		Menu();
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
		{
			a = shtrih(sh);
			if (a == -1)
			{
				printf("Your product does not found, try again \n");
				break;
			}
			fill_shtrih[a] = fill_shtrih[a] + 1;
			product(name, price, sale, a);
			total += sum(price, sale, a);
			break;
		case 2:
			output_check(name, price, sale, fill_shtrih, total);
			break;
		}
		}
	} while (1);
}