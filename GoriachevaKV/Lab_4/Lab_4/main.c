#include <stdio.h>
#define PRODUCTS_COUNT 5
#define BARCODE_LENGTH 5
#define MAX_PRODUCT_NAME_LENGTH 20

//products info
char barcodes[PRODUCTS_COUNT][BARCODE_LENGTH] = {
"1111",
"0123",
"1234",
"5678",
"9012"
};

char product_names[PRODUCTS_COUNT][MAX_PRODUCT_NAME_LENGTH] = {
"Pizza",
"Cucumber",
"Potato",
"Chocolate",
"Tea"
};

int cost[PRODUCTS_COUNT] = { 100, 20, 50, 150, 300 };

int discounts[PRODUCTS_COUNT] = { 5, 1, 10, 25, 50 }; //in percentages

//functions
int check_the_barcode(char barcode[]) {
	for (int i = 0; i < PRODUCTS_COUNT; i++) {
		if (strcmp(barcode, barcodes[i]) == 0) {
			return i;
		}
	}
	if (strcmp(barcode, "END") != 0) {
		printf("ERROR: Barcode is not found.\n\n");
	}
	return -1;
}

void calculations(int total_products_count[], int summ_products_cost[], int* total_without_discount, int* total) {
	for (int i = 0; i < PRODUCTS_COUNT; i++) {
		if (total_products_count[i]) {
			summ_products_cost[i] += cost[i] * total_products_count[i];
			*total_without_discount += summ_products_cost[i];
			*total += (int)(summ_products_cost[i] * ((100 - discounts[i]) / 100.0));
		}
	}
}

void info_print(int* idx) {
	int cost_with_discount = (int)(cost[*idx] * ((100 - discounts[*idx]) / 100.0));
	printf("INFORMATION\n");
	printf("--------------------------------\n");
	printf("Name: %s\n", product_names[*idx]);
	printf("Cost: %d\n", cost_with_discount);
	printf("Discount: %d%%\n", discounts[*idx]);
	printf("Cost (without discount): %d\n\n", cost[*idx]);
}

void check_print(int total_products_count[], int summ_products_cost[], int* total_without_discount, int* total) {
	printf("--------------------------------------------------\n");
	printf("|                     CHECK                      |\n");
	printf("|------------------------------------------------|\n");
	printf("| %-20s | %10s | %10s |\n", "NAME", "COUNT", "COST");
	printf("|------------------------------------------------|\n");
	for (int i = 0; i < PRODUCTS_COUNT; i++) {
		if (total_products_count[i]) {
			printf("| %-20s | %10d | %10d |\n", product_names[i], total_products_count[i], summ_products_cost[i]);
		}
	}
	printf("|------------------------------------------------|\n");
	printf("| TOTAL without discount: %-23d|\n", *total_without_discount);
	printf("| TOTAL: %-40d|\n", *total);
	printf("--------------------------------------------------\n\n");
}

//main code
int main() {
	int idx = -1, barcode_check = 0, total_without_discount = 0, total = 0, check_printing = 0;
	int total_products_count[PRODUCTS_COUNT] = { 0 };
	int summ_products_cost[PRODUCTS_COUNT] = { 0 };
	char barcode[BARCODE_LENGTH];

	do {
		printf("Input a barcode or END (to end the purchase): ");
		scanf_s("%s", barcode, (unsigned)sizeof(barcode));
		idx = check_the_barcode(barcode);
		if (idx != -1) {
			check_printing = 1;
			total_products_count[idx]++;
			info_print(&idx);
		}
	} while (strcmp(barcode, "END") != 0);

	if (check_printing) {
		calculations(total_products_count, summ_products_cost, &total_without_discount, &total);
		check_print(total_products_count, summ_products_cost, &total_without_discount, &total);
	}
	else {
		printf("Check is empty. Nothing to print.\n\n");
	}

	return 0;
}