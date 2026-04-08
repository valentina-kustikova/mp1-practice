#include <stdio.h>
#include <string.h>

#define MAX_NAME_SIZE 10
#define RECORDS_SIZE 10
#define MAX_BARCODE 4

typedef struct Record {
	char barcode[MAX_BARCODE+1];
	char name[MAX_NAME_SIZE];
	int price;
	int discount;
} Record;

void scan(char barcode[]);
void print_record(Record record);
int find_record(char barcode[], Record records[]);
void print_check(int check[], Record records[]);
void print_amount(int check[], Record records[]);

int check[MAX_BARCODE];

int main()
{
	Record records[RECORDS_SIZE];
	records[0] = (Record){ "1234", "Milk", 100, 10 };
	records[1] = (Record){ "1278", "Beer", 110, 15 };
	records[2] = (Record){ "1534", "Pickles", 130, 5 };
	records[3] = (Record){ "7234", "Yogurt", 75, 7 };
	records[4] = (Record){ "1894", "Pate", 122, 3 };
	records[5] = (Record){ "6734", "Spam", 90, 5 };
	records[6] = (Record){ "8934", "Onion", 30, 3 };
	records[7] = (Record){ "1234", "Potato", 40, 2 };
	records[8] = (Record){ "9274", "Coffee", 300, 20 };
	records[9] = (Record){ "7254", "Milk", 100, 10 };

	char curr_barcode[MAX_BARCODE+1] = "----";
	int running = 1;
	while (running) {
		int command;
		printf("1 - scan barcode\n2 - print current record\n3 - add current record to check\n4 - print check\n5 - print total amount\n0 - exit\nEnter command: ");
		scanf_s("%d", &command);
		switch (command) {
		case 1:
			scan(curr_barcode);
			break;
		case 2:
			if (find_record(curr_barcode, records) != -1) {
				print_record(records[find_record(curr_barcode, records)]);
			}
			break;/*
		case 3:
			if (find_record(curr_barcode, records) != -1) {
				check[curr_barcode]++;
			}
			break;
		case 4:
			print_check(check, records);
			break;
		case 5:
			print_amount(check, records);
			break;
			*/
		case 0:
			running = 0;
			break;
		}
	}
}

void scan(char barcode[]) {
	printf("Enter barcode: ");
	scanf_s("%s", barcode, MAX_BARCODE+1);
	return barcode;
}

void print_record(Record record) {
	printf("%-7s %-11d %-5d %-s\n", record.barcode, record.discount, record.price, record.name);
}

int find_record(char barcode[], Record records[]) {
	int i;
	for (i = 0; i < RECORDS_SIZE; i++) {
		if (strcmp(records[i].barcode, barcode) == 0) return i;
	}
	return -1;
}

void print_check(int check[], Record records[]) {
	int i, total_cost = 0, total_discount = 0;
	printf("Number Barcode Discount(%%) Price Name\n");
	for (i = 0; i < MAX_BARCODE; i++) {
		if (check[i] > 0) {
			Record curr_record = records[find_record(i, records)];
			printf("%-6d ", check[i]);
			print_record(curr_record);
			total_cost += curr_record.price * check[i];
			total_discount += curr_record.price * check[i] * curr_record.discount / 100;
		}
	}
	printf("Total cost: %d\nTotal discount: %d\nTotal amount: %d\n", total_cost, total_discount, total_cost-total_discount);
}

void print_amount(int check[], Record records[]) {
	int i, total_cost = 0, total_discount = 0;
	for (i = 0; i < MAX_BARCODE; i++) {
		if (check[i] > 0) {
			Record curr_record = records[find_record(i, records)];
			total_cost += curr_record.price * check[i];
			total_discount += curr_record.price * check[i] * curr_record.discount / 100;
		}
	}
	printf("Total amount: %d\n", total_cost-total_discount);
}