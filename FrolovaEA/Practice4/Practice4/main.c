#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define ALL_PRODUCT 10

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
int discount[ALL_PRODUCT] = { 5, 2, 0, 10, 30, 40, 3, 0, 50, 15 };
double sum = 0;

double discount_price(double price, int discount);
void conclusion();
int purchases(int* buff);
double cheque(int* buff, int num_buff);

int main() {

	conclusion();

	int buff[50], num_buff = 0;

	num_buff = purchases(buff);

	sum = cheque(buff, num_buff);

	printf("sum - %.2f", sum);

	return 0;

}

int purchases(int* buff) {
	char str[5] = "";
	int num = 0, number_buff = 0;

	while (strcmp(str, "exit")) {
		printf("Enter the product code or exit to exit: ");
		scanf_s("%s", str, 5);
		if (strspn(str, "0123456789")) {
			num = atoi(str);
			for (int i = 0; i < ALL_PRODUCT; i++)
				if (code[i] == num) {
					buff[number_buff] = code[i];
					number_buff++;
				}
		}
	}
	return number_buff;
}


double discount_price(double price, int discount) {
	return price - (price * discount) / 100;
}

void conclusion() {
	for (int i = 0; i < ALL_PRODUCT; i++) {
		printf("code: %d, product:%s ", code[i], product[i]);
		printf("\n");
	}
}

double cheque(int* buff, int num_buff) {

	for (int i = 0; i < num_buff; i++)
		for (int j = 0; j < ALL_PRODUCT; j++) {
			if (code[j] == buff[i]) {
				printf("%s, ", product[j]);
				printf("\tprice - %0.2f,\t discount - %d%%,\t discount price - %0.2f\n", price[j], discount[j], discount_price(price[j], discount[j]));
				sum += discount_price(price[j], discount[j]);
			}
		}

	return sum;

}