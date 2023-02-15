#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL_N 12

char* names[TOTAL_N] = { "Milk 1L", "Bread", "Butter", "Chokolate", "Cheese", "Ice-cream", "Chicken 800g", "Beef 1kg", "Crisps", "Juice 1L", "Sugar 1kg", "Salt 1kg" };
int prices[TOTAL_N] = { 86, 45, 110, 114, 120, 65, 220, 300, 82, 99, 50, 45 };
int discounts[TOTAL_N] = { 5, 3, 20, 25, 0, 5, 10, 5, 5, 5, 0, 5 };
char barcodes[TOTAL_N][5] = { "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100" };


int check_exists_bar(char curr[]) {
	int i, result = -1, n = TOTAL_N;
	for (i = 0; i < n; i++) {
		if (strcmp(curr, barcodes[i]) == 0) {
			result = i;
			break;
		}
	}
	return result;
}

void print_cheque(int count[], double curr_price_whoutDisc, double t_curr_price) {
	int i, n = TOTAL_N;
	double economy = curr_price_whoutDisc - t_curr_price, perc_economy = (economy / curr_price_whoutDisc) * 100;
	printf("------------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------------\n\n");
	for (i = 0; i < n; i++) {
		if (count[i] > 0) {
			double price_disc = prices[i] * (1 - (double)discounts[i] / 100.0);
			double total_pr = price_disc * count[i];
			printf("Product: %s   ||   Price with discount: %.2lf   ||   Count: %d   ||   Total price is  %.2lf\n\n", names[i], price_disc, count[i], total_pr);
		}
	}
	printf("------------------------------------------------------------------------------\n");
	printf("\nTotal cost without discount:  %.2lf ,  BUT in general you have saved %.2lf rubles (i.e. %.2lf percent)\n", curr_price_whoutDisc, economy, perc_economy);
	printf("To be paid:  %.2lf  reubles\n", t_curr_price);
}

// calculates the count of each product and the total price
void product_processing(int id, int count[], double* cost_without, double* total_cost) {
	double price_disc = prices[id] * (1 - (double)discounts[id] / 100.0);
	count[id]++;
	*(cost_without) += prices[id];
	*(total_cost) += price_disc;
}

void print_prod_info(int bar) {
	double price_disc = prices[bar] * (1 - (double)discounts[bar] / 100.0);
	printf("Product:  %s  ||  Price per piece:  %d rubles  ||   Discount:  %d%%  ||   price with discount:   %.2lf rubles\n\n", names[bar], prices[bar], discounts[bar], price_disc);
}

int get_and_check_barcode() {
	char curr_bar[5], clean, count_of_ch = 0, ind_prod = -1;
	int i, n = TOTAL_N, len;
	printf("Enter barcode or 'C'\n");
	gets(curr_bar);
	len = strlen(curr_bar);

	// User wants to get cheque
	if (strcmp(curr_bar, "C") == 0) {
		return -2;
	}

	// check the barcode by 3 parameters:

	for (i = 0; i < len; i++) { // check for invalid characters
		if (!((curr_bar[i] == '0') || (curr_bar[i] == '1'))) {
			printf("The barcodes in our supermarket consist only of '0' and '1'\n\n");
			return -1;
		}
	}

	ind_prod = check_exists_bar(curr_bar); // -1 if such a barcode doesn't exist
	if (ind_prod == -1) {
		printf("We haven't a product with such barcode!!! Try again\n\n");
		return -1;
	}

	return ind_prod;
}

int main() {
	int count[12] = { 0 }, res_id;
	double curr_price_whoutDisc = 0, t_curr_price = 0;
	printf("Welcome to our supermarket!\nThere is a self-service ticket office\nEnter a barcode of each product, or enter 'C' and 2 'ENTER' to get cheque)\n\n");

	while (1) {
		res_id = get_and_check_barcode(); // returns: -1, if sth goes wrong; index of product, if It's OK prod; -2, if CHECK

		if (res_id != -1 && res_id != -2) {
			print_prod_info(res_id);
			product_processing(res_id, count, &curr_price_whoutDisc, &t_curr_price);
		}
		if (res_id == -2) {
			print_cheque(count, curr_price_whoutDisc, t_curr_price);
			break;
		}

	}

	return 0;
}