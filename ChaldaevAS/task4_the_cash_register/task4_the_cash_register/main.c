#include <stdio.h>
#include <string.h>
#define PRODUCT_COUNT 10
#define BAR_CODE_LEN 5
#define NAME_MAX_LEN 50


char barcodes[PRODUCT_COUNT][BAR_CODE_LEN] = {
	"1234",
	"1345",
	"1380",
	"2414",
	"4155",
	"5647",
	"6000",
	"6151",
	"7505",
	"7999",
};

char names[PRODUCT_COUNT][NAME_MAX_LEN] = {
	"Milk",
	"Bread",
	"Eggs",
	"Chicken Breast",
	"Rice",
	"Pasta",
	"Cheese",
	"Butter",
	"Yogurt",
	"Apples"
};

int cost[PRODUCT_COUNT] = {
	2000,
	55,
	130,
	450,
	110,
	85,
	700,
	150,
	30,
	100
};


int discount[PRODUCT_COUNT] = {
	20,
	30,
	45,
	30,
	10,
	10,
	10,
	10,
	50,
	70
};

int input_barcode(int product_check_count[PRODUCT_COUNT]) {
	char input_code[BAR_CODE_LEN];
	int c;
	int i;
	int is_found;

	printf("Write new barcode or 'STOP' to complete the purchase: ");
	scanf_s("%4s", input_code, (unsigned)sizeof(input_code));
	while ((c = getchar()) != '\n' && c != EOF);

	if (strcmp(input_code, "STOP") == 0) {
		return 1;
	}

	is_found = 0;

	for (i = 0; i < PRODUCT_COUNT; i++) {
		if (strcmp(input_code, barcodes[i]) == 0) {
			product_check_count[i]++;
			is_found = 1;
			break;
		}
	}
	if (!is_found) {
		printf("ERROR: Barcode not found.\n");
	}
	return 0;
}

void display_the_check(int product_check_count[PRODUCT_COUNT]) {
	int final_price = 0, i;
	int total_discount = 0;

	printf("\n======================================================\n");
	printf("%-20s | %5s | %5s | %15s\n", "PRODUCT", "PRICE", "COUNT", "CORRENT PRICE");
	printf("--------------------------------------------------------\n");


	for (i = 0; i < PRODUCT_COUNT; i++) {
		int price_for_product = 0;

		if (product_check_count[i] == 0) {
			continue;
		}
		
		price_for_product = (cost[i] * product_check_count[i] * (100 - discount[i])) / 100;
		total_discount += cost[i] * product_check_count[i] - price_for_product;
		final_price += price_for_product;

		printf("%-20s | %5d | %5d | %15d\n", names[i], cost[i], product_check_count[i], price_for_product);
	}
	printf("\n-----------------------------------------------------\n");
	printf("TOTAL DISCOUNT: %d\n\n", total_discount);
	printf("TOTAL PRICE: %d", final_price);
	printf("\n=====================================================\n");
}

int main() {
	int product_check_count[PRODUCT_COUNT] = { 0 };
	int is_finish = 0;
	while (!is_finish) {
		if (input_barcode(product_check_count) == 1) {
			is_finish = 1;
		};
	}
	display_the_check(product_check_count);
	return 0;
}