#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 12

char* barcodes[N] = { "0231", "4051", "8950", "2456", "4789", "7890", "1234", "8907", "1236", "7890","2457", "0200" };
char* products[N] = { "Bread", "Milk", "Cheese", "Sausage", "Fish", "Egg", "Lemon", "Water", "Jam", "Onion","Porridge", "Rice" };
double price[N] = { 39.00, 80.00, 300.00, 5000.00, 75.00, 100.0, 2300.00, 25.00, 22229.99, 122131.00 };
double discount[N] = { 20, 40, 5, 15, 5, 5, 10, 30, 10, 20,20,12 };
char* description[N] = { "Wonderful\n","natural\n","yellow, no holes\n","Natural meat (not from dogs), honestly\n","from in the oceans, lakes and rivers, bred on special farms.\n","round, chicken\n","Sour, Russian\n","Liquid\n","Berry\n","Vampires are afraid of it\n","potato\n","made in China\n" };

int  scan(int* amount) {
	int flag = 0;
	char barcode[6] = " ";
	printf("Enter a 4-digit code (or exit if you want to generate a final check):");
	while (strcmp(barcode, "0")) {
		gets(barcode);
		flag = 0;
		if (strcmp(barcode, "0")) {
			for (int i = 0; i < N; i++) {
				if (strcmp(barcodes[i], barcode) == 0) {
					printf("name:%s\nprice:%.2f rubles\ndiccount:%.2fpercent\ndescription :%s\n", products[i], price[i], discount[i], description[i]);
					amount[i] += 1;
					flag = 1;
				}
				if (strcmp(barcode, "exit") == 0) {
					return 0;
				}
			}
				if (flag == 0) { printf("This product code does not exist, please try another one\n");  return 1; }
				printf("barcode:");
		}
	}
}

void finalcheck(int* amount) {
	float check = 0;
	printf("Total check\n");
	for (int i = 0; i < N; i++) {
		if (amount[i] != 0) {
			printf(("%s, price(with discount) - %.2f\n%d(amount).\n"), products[i], (price[i] * (1 - (discount[i] / 100))), amount[i]);
		}
		check += (price[i] * (1 - (discount[i] / 100))) * amount[i];
	}
	printf("Total cost - %.2f", check);
}

int main() {
	int count[N] = { 0 };
	int scan(count);
	if (scan(count) == 0) {
		finalcheck(count);
	}
}
