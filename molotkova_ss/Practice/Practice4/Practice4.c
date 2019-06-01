
﻿#include <stdio.h> 
#define N 5 
int scanning(int dop[], int quantity[], int dlya_dop, int **scan)
{
	char tovar[4];//будущий шттрихкод
	int i;
	do
	{
		printf("Enter barcode\n");
		scanf("%s", &tovar);
		i = 0;
		while (strncmp(tovar, scan[i], 4) != 0)
		{
			i++;
		}
		dop[dlya_dop] = i;
	} 
	while (dop[dlya_dop]>N);
	printf("\nEnter quantity\n");
	scanf("%d", &i);
	return i;//количество товара
}
void description(char names[][10], int prices[], int discounts[], int i)
{
	int j;
	for (j = 0; j < 10; j++)
		printf("%c", names[i][j]);
	printf("price=%d discount=%d\n", prices[i], discounts[i]);
}
void adding(int quantity[], int n, int z)
{
	quantity[n] += z;
}
void check_formation(char names[][10], int prices[], int discounts[], int quantity[])
{
	int a = 0;
	int b = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		if (quantity[i] > 0) 
		{
			description(names, prices, discounts, i);
			printf("Quantity=%d", quantity[i]);
			a = a + quantity[i] * prices[i];
			b = b + prices[i] * 0.01 * (100 - discounts[i]) * quantity[i];
		}
	}
	if (a != 0)
		printf("Sum=%d\n Sum with skidka=%d\n Skidka=%d\n", a, b, (a - b) * 100 / a);
	else
		printf("Check is  empty\n");
}
void main()
{
	char names[N][10] = { "          ", "milk      ", "bread     ", "fish      " , "meat"};
	int prices[N] = { 0, 68, 21, 170, 240 };
	int discounts[N] = { 0, 10, 15, 5, 20};
	int quantity[N] = { 0 };//array for quantity goods
	int dop[10];
	int p,i,q;
	int dlya_dop = 0;	
	q = scan(dop, quantity, dlya_dop);
	
	char **scan = (char**)malloc(5 * sizeof(char*));//штрихкод, 5-их количество
	for (i = 0; i < 5; i++)
	{
		scan[i] = (char*)malloc(sizeof(char) * 4);//4 количество цифр
        scan[i][3] = i % 10 + '0';// для чар
        scan[i][2] = (i / 10) % 10 + '0';
        scan[i][1] = (i / 100) % 10 + '0';
        scan[i][0] = (i / 1000) + '0';
	}
	
	do
	{
		printf("1-Scan\n 2-Description\n 3-Add\n 4-Check form\n 5- Itog check\n");
		scanf("%d", &p);
		switch (p)
		{
		case 1:
			q = scanning(dop, quantity, dlya_dop, scan);
			break;
		case 2:
			description(names, prices, discounts, dop[dlya_dop]);
			break;
		case 3:
			adding(quantity, dop[dlya_dop], q);
			dlya_dop++;
			break;
		case 4:
			check_formation(names, prices, discounts, quantity);
			break;
		case 5:
			check_formation(names, prices, discounts, quantity);
			free(quantity);
			free(dop);
			dlya_dop = 0;
			break;
		}
	} while (p != 5);
}

