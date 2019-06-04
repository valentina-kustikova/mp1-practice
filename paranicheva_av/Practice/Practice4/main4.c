#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 20
void Scan_product(int *ind, int *kolvo,  int *i, char **scan, int *k)
{
	int j;
	char shtr[4];
	printf("Enter the item code\n");
	scanf("%s", &shtr);
	j = 0;
	while (strncmp(scan[j], shtr, 4) != 0)
	{
		j++;
	}
	*ind = j - 1;
	printf("Enter the quantity of products\n");
	scanf("%d", k);
}
void Product_description(char **scan, char **prod, int price[], int discount[], int *ind )
{
	int h = *ind + 1;
	printf("%s name - %s  ", scan[h], prod[*ind]);
	printf("unit price = %d   discount = %d\n", price[*ind], discount[*ind]);
}
void Add_item_to_check(int *check, int *ind, int *sch, int *i, int kolvo[], int *k)
{

	kolvo[*i] = *k;
	check[*sch] = *ind;
}
 int Form_a_check(char **prod, int price[], int kolvo[], int *check, int sch, int *kprice )
{
	int j;
	for(j = 0; j < sch; j++)
	{
		printf("name - %s   unit price = %d    quantity = %d    ", prod[check[j]], price[check[j]], kolvo[j]);
		kprice[j] = price[check[j]] * kolvo[j];
		printf("price = %d\n", kprice[j]);
	}
}
 void Calculate_the_total(int kprice[], int price[], int discount[], int kolvo[], int *check, int sch)
{
	int sumprice = 0, allprice = 0, alldiscount = 0, j;
	printf("%d", sch);
	for (j = 0; j < sch; j++)
	{
		allprice += kprice[j];
		sumprice += (price[check[j]] * kolvo[j] * (100 - discount[check[j]])) / 100;
	}
	alldiscount = allprice - sumprice;
	printf ("\nFull price of products is %d  \nAmount of all discounts is %d", allprice, alldiscount);
	printf ("\nThe total price is %d\n\n",sumprice);
}
void main()
{
	int choice, ind = 0, i = 0, sch = 0, k;
	char *prod[] = {"ice cream", "milk", "bread", "chocolate", "yogurt", "butter", "eggs"};
	char **scan = (char**)malloc(10000 * sizeof(char*));
	int price[] = {50, 60, 30, 100, 30, 70, 60};
	int discount[] = {10, 5, 7, 15, 10, 5, 5};
	int *kolvo;
	int *check;
	int *kprice;

	for (i = 0; i < 10000; i++)
	{
    scan[i] = (char*)malloc(sizeof(char) * 4);
    scan[i][3] = i % 10 + '0';
    scan[i][2] = (i / 10) % 10 + '0';
    scan[i][1] = (i / 100) % 10 + '0';
    scan[i][0] = (i / 1000) + '0';
	}

	kolvo = (int*)malloc(max * sizeof(int));
	check = (int*)malloc(max * sizeof(int));
	kprice = (int*)malloc(max * sizeof(int));
	i = 0;
	do
	{
		printf (" 1. Scan product \n 2. Product description \n 3. Add item to check \n 4. Form a check \n ");
		printf ("5. Calculate the total\n");
		scanf ("%d", &choice);
		switch (choice)
			{
			case 1: 
				Scan_product(&ind, kolvo, &i, scan, &k);
				break;
			case 2: 
				Product_description(scan, prod, price, discount, &ind );
				break;
			case 3: 
				Add_item_to_check(check, &ind, &sch, &i, kolvo, &k);
				i++;
				sch++;
				break;
			case 4: 
				Form_a_check(prod, price, kolvo, check, sch, kprice);
				break;
			case 5: 
				Calculate_the_total(kprice, price, discount, kolvo, check, sch);
				break;
			}
	}
	while (choice != 5);
	free(kprice);
	free(check);
	free(kolvo);
}
