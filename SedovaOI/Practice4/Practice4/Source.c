#include<stdio.h>
#define LENGTH (sizeof(price)/sizeof(price[0]))
float price[] = { 25.00, 69.00, 75.00, 80.00, 300.00, 120.00, 30.00, 80.00, 250.00, 400.00 };
const char* products[] = { "Lemon","Milk","Eggs","Apple","Honey","Oil","Bread","Tea","Sausage","Cheese" };
const char* barcodes[] = { "0101","2020","0303","4040","0505","6060","0707","8080","0909","1010" };
float skidka[] = { 4.50, 7.00, 5.00, 6.55, 21.35, 12.50, 5.00, 13.90, 42.10, 51.30 };
const char* infos[] = { "Country of origin: Russia","Country of origin: Russia\nFat content of milk - 3,2%","Country of origin: Russia\nCategory of eggs - C0","Country of origin: Russia\nGreen apples","Country of origin: Russia\nMountain honey", "Country of origin: Russia\nOlive oil","Country of origin: Russia\nRye bread","Country of origin: Russia\nBleak tea","Country of origin: Russia\nCheese smoked sausage","Country of origin: Russia\nCheese with blue mold" };
int count[LENGTH] = { 0 };

void intro() {
	printf("Scan your barcodes below\n");
	printf("Enter \"print\" when you are done\n");
}

void description(int num) {
	printf("%s, price: %.2f, discount: %.2f\n", products[num], price[num], skidka[num]);
	printf("%s\n", infos[num]);
}
void line() {
	for (int i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}
void scan() {
	static int tmp = 0;
	char* entered[6];
	int counts[LENGTH] = { 0 };
	printf("Enter barcode\n");
	gets(entered);
	if (strcmp(entered, "print")) {
			for (int i = 0; i < LENGTH; i++) {
				if (strcmp(barcodes[i], entered) == 0) {
					description(i);
					count[i] += 1;
					tmp = 1;
				}
			}
			if (tmp == 0)
				printf("Couldn't find this barcode, please try again\n");
		scan();
	}
}

void print_check() {
	float cost = 0.0;
	printf("Your check:\n");
	line();
	for (int i = 0; i < LENGTH; i++) {
		if (count[i] != 0) {
			printf("%s, price with discount - %.2f, %d\n", products[i], price[i] - skidka[i], count[i]);
			line();
			cost += (price[i] - skidka[i]) * count[i];
		}
	}
	printf("Price - %.2f\n", cost);
}

int main() {
	intro();
	scan();
	print_check();
	return 0;
}

