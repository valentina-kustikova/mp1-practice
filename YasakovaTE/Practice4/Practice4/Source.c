#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#define N 10

char* barcodes[N] = { "0101", "0202", "0303", "1212", "1414", "2323", "4545", "5236", "5632", "7845" };
char* products[N] = { "Milk", "Bread", "Butter", "Cheese", "Sugar", "Juice", "Chicken", "Jam", "Beer", "Pie" };
int cost[10] = { 20, 10, 15, 80, 90, 150, 100, 40, 60, 70 };
float discount[10] = { 0.05, 0.03, 0.04, 0.15, 0.19, 0.10, 0.18, 0.03, 0.04, 0.09 };

void scan(int* a) {
	char b[N];
	int count[10] = { 0 };
	int out=1;
	int get = 1;
	printf("Enter codes: \n");
	while (out==1) {
		gets(b);
		for (int i = 0; i < N; i++) {
			if (strcmp(barcodes[i], b) == 0)
			{
				printf("%s,   price: %.2d rubles,   diccount: %.2f percent\n", products[i], cost[i], discount[i]);
				a[i] += 1;
				printf("If there are no more products in the basket, then enter - 0, if there is - 1:  \n");
				scanf(" %d", &get);
				if (get == 0)
					out = 0;
				else printf("Enter codes: \n");
				break;
			}
		}
	}
}

void bill(int* a) {
	float totalCost = 0;
	printf("List of products:\n");
	for (int i = 0; i < N; i++) {
		if (a[i] == 0)
			continue;
		printf("%s, cost per unit: %d, count: %d,  price including discount: %.2f\n", products[i], cost[i], a[i], (cost[i] - discount[i] * cost[i]) * a[i]);
		totalCost += (cost[i] - discount[i] * cost[i]) * a[i];
	}
	printf("Total amount - %.2f", totalCost);
}

int main() {
	int counts[N] = { 0 };
	scan(counts);
	bill(counts);
	return 0;
}

