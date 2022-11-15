#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define ALL_PRODUCT 10

double discount_price(double price, int discount) {
	return price - (price * discount) / 100;
}

int main(void) {
	int code[ALL_PRODUCT] = { 1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009 };
	char product[ALL_PRODUCT][40] = {
		"notebook 96 sheets",
		"notebook 48 sheets",
		"ballpoint pen blue",
		"a set of colored pencils",
		"stapler",
		"a4 paper",
		"paper files",
		"folder for papers",
		"datebook",
		"office calculator"
	};
	double price[ALL_PRODUCT] = { 70, 45, 11, 210, 175, 299, 101, 30, 250, 599 };
	int num = 0, discount[ALL_PRODUCT] = { 5, 2, 0, 10, 30, 40, 3, 0, 50, 15 };
	double sum = 0;



	for (int i = 0; i < ALL_PRODUCT; i++) {
		printf("code: %d, product:%s ", code[i], product[i]);
		printf("\n");
	}


	char str[5] = "";
	int buff[50], num_buff = 0;

	while (strcmp(str, "exit")) {
		printf("Enter the product code or exit to exit: ");
		scanf_s("%s", str, 5);
		if (strspn(str, "0123456789")) {
			num = atoi(str);
			for (int i = 0; i < ALL_PRODUCT; i++)
				if (code[i] == num) {
					buff[num_buff] = code[i];
					num_buff++;
					printf(": %d, %d\n", code[i], num_buff);

				}
		}
	}
	for (int i = 0; i < num_buff; i++)
		for (int j = 0; j < ALL_PRODUCT; j++) {
			if (code[j] == buff[i]) {
				printf("%s, ", product[j]);
				printf("\tprice - %0.2f,\t discount - %d%%,\t discount price - %0.2f\n", price[j], discount[j], discount_price(price[j], discount[j]));
				sum += discount_price(price[j], discount[j]);
			}
		}

	printf("sum - %.2f", sum);
	return 0;
}