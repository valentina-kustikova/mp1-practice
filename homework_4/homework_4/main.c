#include <stdio.h>
#define N 5

int main() {
	int i, j, product, temp, match, total_price = 0;
	float total_sale = 0.0;
	int enter_barcode[4];
	int barcode[N][4] = { {1,2,3,4},{5,6,7,8},{9,0,1,2},{3,4,5,6},{7,8,9,0} };
	char name[N][10] = { "product 1", "product 2", "product 3", "product 4", "product 5" };
	int price[N] = { 100, 130, 15, 1000, 250 };
	int sale[N] = { 10, 20, 1, 25, 50 };
	int count[N] = { 0 };

	do {
		printf("Enter the barcode of the product, if you want to complete the buying, enter 0\n\n");
		scanf_s("%d", &product);

		if (product == 0) break;

		temp = product;

		for (i = 3; i >= 0; i--) {
			enter_barcode[i] = temp % 10;
			temp = temp / 10;
		}

		if (temp != 0) {
			printf("product not found\n");

		}

		else {
			match = 0;
			for (i = 0; i < N; i++) {
				match = 1;
				for (j = 0; j < 4; j++) {
					if (enter_barcode[j] != barcode[i][j]) {
						match = 0;
						break;
					}
				}

				if (match == 1) {
					count[i] += 1;
					printf("%s - %d rub. - %d%%\n\n", name[i], price[i], sale[i]);
					break;
				}
			}
			if (match == 0) {
				printf("product not found\n");
			}
		}
	} while (1);

	printf("Receipt:\n");
	for (i = 0; i < N; i++) {
		if (count[i] != 0) {
			printf("Name - %s, price - %d rub. * %d = %d rub.\n",
				name[i], price[i], count[i], count[i] * price[i]);
			total_price += count[i] * price[i];

			printf("Sale - %d%%\n", sale[i]);

			printf("Total: %f rub.\n", count[i] * price[i] - (count[i] * (price[i] * (sale[i] / 100.0))));
			total_sale += (count[i] * (price[i] * (sale[i] / 100.0)));
		}
	}
	printf("Total amount - %d, total sale - %f\n total amount to be paid - %f\n", total_price, total_sale, total_price - total_sale);
	return 0;
}