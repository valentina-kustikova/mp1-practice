#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

char* codes[N] = { "1000", "1001", "1002", "1003", "1004", "1005", "1006", "1007", "1008", "1009" };
int price[N] = { 62, 100, 50, 35, 80, 73, 27, 94, 15, 30 };
float discount[N] = { 0.1, 0.25, 0.15, 0.5, 0.0, 0.5, 0.1, 0.2, 0.0, 0.0 };
char* products[N] = { "Milk", "Lemon", "Tomato", "Potato", "Eggs", "Apples", "Onion", "Cheese", "Bread", "Oil" };

void scan(int* arr)
{
	int i, j;
	float priceWD;
	char a[5];

	printf("Welcome!\nScan your codes.\nEnter 0 to print check.\n");
	do {
		printf("Enter codes\n");
		gets(a);
		j = 0;
		for (i = 0; i < N; i++)
		{
			if (strcmp(codes[i], a) == 0)
			{
				arr[i]++;
				priceWD = price[i] - discount[i] * price[i];
				printf("%s, price: %.2d rubles, discount: %.2f, total cost is %.2f rubles\n", products[i], price[i], discount[i] * 100, priceWD);
				j = 1;
			}
		}
		if ((j == 0) && (strcmp(a, "0") != 0))
		{
			printf("There is no such code. Check it and try again.\n");
		}

	} while (strcmp(a, "0"));
}
void print_check(int* arr)
{
	int i, sum = 0;

	float sumD = 0, total_sum = 0, priceDD;
	for (i = 0; i < N; i++)
	{
		if (arr[i] > 0)
		{
			sum = price[i] * arr[i] + sum;
			priceDD = (price[i] - price[i] * discount[i]) * arr[i];
			total_sum = total_sum + priceDD;
			sumD = sumD + (price[i] * discount[i]) * arr[i];
			printf("%10s, price: %d, count: %d, price with discount: %.2f\n", products[i], price[i], arr[i], priceDD);
		}
	}
	printf("\t\nPrice: %d, Discount: %.2f, Total price: %.2f\n", sum, sumD, total_sum);
}


int main()
{
	int count[N] = { 0 };
	scan(count);
	print_check(count);
	return 0;
}
