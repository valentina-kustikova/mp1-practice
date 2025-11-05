#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define LINE 512
#define ENTRY_SIZE 1000

struct product {
	char barcode[4];
	char name[LINE];
	int price;
	int discount;
};

struct entry {
	struct product product;
	int amount, cost;
};

struct check {
	struct entry* entries;
	int count;
	int cost, discount;
	int total;
};

struct product products[] = {
	{.barcode = "0000", .name = "Apple", .price = 20, .discount = 5},
	{.barcode = "0001", .name = "Banana", .price = 50, .discount = 2}
};
int products_amount = sizeof(products) / sizeof(struct product);

int main() {
	char query[LINE];
	bool has_scanned = false;
	bool has_check = false;
	struct product scanned;
	struct entry entry_list[ENTRY_SIZE];
	struct check check;
	int entry_amount = 0;
	while (true) {
		int i;
		printf("> ");
		scanf(" %511[^ ] ", query);
		for (i = 0; query[i]; i++)
			query[i] = tolower(query[i]);
		if (!strncmp(query, "SCAN", 4)) {
			char barcode[4];
			scanf(" %4s", barcode);
			for (i = 0; i < products_amount; i++) {
				if (!strncmp(barcode, products[i].barcode, 4)) {
					scanned = products[i];
					has_scanned = true;
					printf("Product %4s scanned.\n", scanned.barcode);
				}
			}
			if (!has_scanned)
				printf("Product with this barcode was not found.\n");
		}
		else if (!strncmp(query, "VIEW", 4)) {
			if (!has_scanned) {
				printf("Scan a new product.\n");
			}
			else {
				printf("Barcode: %4s\nName: %511s\nPrice per item: %d\nDiscount %d\%\n",
					scanned.barcode, scanned.name, scanned.price, scanned.discount);
			}
		}
		else if (!strncmp(query, "ADD", 3)) {
			if (!has_scanned) {
				printf("Scan a new product.\n");
			}
			else {
				bool found = false;
				for (i = 0; i < entry_amount; i++)
					if (!strncmp(scanned.barcode, entry_list[i].product.barcode, 4)) {
						entry_list[i].amount += 1;
						entry_list[i].cost += scanned.price;
						found = true;
						break;
					}

				if (!found) {
					if (entry_amount < ENTRY_SIZE) {
						entry_list[entry_amount++] = (struct entry){
							.product = scanned,
							.amount = 1,
							.cost = scanned.price
						};
					}
					else {
						printf("Too many entries! (1000)\n");
					}
				}
			}
		}
		else if (!strncmp(query, "CHECK", 5)) {
			check = (struct check){
				.entries = entry_list,
				.count = entry_amount,
				.cost = 0,
				.discount = 0,
			};
			for (i = 0; i < entry_amount; i++) {
				struct product p = entry_list[i].product;
				check.cost += entry_list[i].cost;
				check.discount += p.price * p.discount / 100;
			}
			has_check = true;
			printf("Check formed, to view it use the command TOTAL.\n");
		}
		else if (!strncmp(query, "TOTAL", 5)) {
			if (!has_check)
			for (i = 0; i < entry_amount; i++) {
				struct entry entry = entry_list[i];
				struct product p = entry.product;
				printf("%4s - %511s - %d - %d\n",
					p.barcode, p.name, entry.amount, entry.cost);
			}
			printf("-----------------\n");
			printf("COST: %d\nDISCOUNT: %d\nTOTAL: %d\n",
				check.cost, check.discount, check.cost - check.discount);
		}
	}
	return 0;
}