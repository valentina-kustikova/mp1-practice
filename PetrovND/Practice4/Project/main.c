#include <stdio.h>
#include <string.h>
#define N 10

char* barcodes[N] = { "0101", "0202", "0303", "1212", "1414", "2323", "4545", "5236", "5632", "7845" };
char* products[N] = { "Milk", "Bread", "Butter", "Cheese", "Sugar", "Juice", "Chicken", "Jam", "Beer", "Pie" };
float price[N] = { 79.90, 49.00, 120.50, 210.90, 75.00, 99.00, 230.00, 125.50, 69.99, 189.90 };
float discount[N] = { 5.9, 4, 12.5, 15, 5, 8, 19, 11.50, 9.99, 4.90 };

void scan(int* ct) {
	char bc[5] = "";
	int count[10] = { 0 };
	printf("Enter barcodes...\n");
	while (strcmp(bc, "q")) {
		gets(bc);
		if (strcmp(bc, "q")) {
			for (int i = 0; i < N; i++) {
				if (strcmp(barcodes[i], bc) == 0) {
					printf("%s, price: %.2f, diccount: %.2f\n", products[i], price[i], discount[i]);
					ct[i] += 1;
				}
			}
		}
	}
}

void printReceipt(int* ct) {
	float totalCost = 0;
	printf("Your receipt :)\n");
	for (int i = 0; i < N; i++) {
		if (ct[i] == 0)
			continue;
		printf("%s, price including discount - %.2f, %d units.\n", products[i], price[i]-discount[i], ct[i]);
		totalCost += (price[i] - discount[i])*ct[i];
	}
	printf("Total cost - %.2f", totalCost);
}

int main() {
	int counts[N] = { 0 };
	scan(counts);
	printReceipt(counts);
	return 0;
}