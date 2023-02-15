#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char codes[10][4] = { "1234","2345","3456","4567","5678","6789","7891","8912","9123","9999" };
char names[10][7] = { "salt   ","sugar  ","bread  ", "milk   ","eggs   ","tea    ","cheese ","meat   ","honey  ","oil    " };
int cost[10] = { 50, 60, 40, 80, 80, 50, 200, 300, 150, 75 };
double sale[10] = { 0.1, 0.2, 0.05, 0.05, 0.1, 0.2, 0.04, 0.04, 0.1, 0.2};

void f_init(double* cost_sale, double* sale_r);
void f_main_work(char* pr, int* k_pr, double* sale_r, double* cost_sale);
void scan_pr(char* a);
int ind_pr(char* b);
void info_pr(int ind, double* a, double* b);
void f_cheque(int* k_pr, double* cost_sale);
void f_total(double a, double b, double c, int* k, double* arrA, double* arrB);

int main() {
	char pr[4];
	int i, flag = 0;
	int ind;
	int counter;
	int k_pr[10] = { 0 };
	double total_not_sale = 0, total_sale = 0, total_with_sale = 0;
	double  cost_sale[10] = { 0 };	
	double sale_r[10] = { 0 };

	f_init(cost_sale, sale_r);	
	f_main_work(pr, k_pr, sale_r, cost_sale);	
	f_cheque(k_pr, cost_sale);
	f_total(total_not_sale, total_sale, total_with_sale, k_pr, sale_r, cost_sale);
	
	return 0;
}














void f_init(double* cost_sale, double* sale_r) {
	int i;
	for (i = 0; i < 10; i++) {
		cost_sale[i] = cost[i] * (1 - sale[i]);
	}
	for (i = 0; i < 10; i++) {
		sale_r[i] = cost[i] * sale[i];
	}
}


void f_main_work(char* pr, int* k_pr, double* sale_r, double* cost_sale) {
	int flag = 1, ind;
	char counter;
	char tmp;

	while (flag == 1) {
		printf("Scan the product \n");
		scan_pr(pr);
		ind = ind_pr(pr);
		if (ind == -1) 
			continue;
		k_pr[ind] += 1;
		info_pr(ind, sale_r, cost_sale);

		printf("Do you have any more products?  y/n \n");

		scanf("%c", &tmp);
		if (tmp == '\n') {
				scanf("%c", &counter);
		}
		else {
			counter = tmp;
		}

		while ((counter != 'n') && (counter != 'y')) {
				printf("You need to enter y(yes) or n(no). Try again:\n");
				scanf("%c", &tmp);
				if (tmp == '\n') {
					scanf("%c", &counter);
				}
				else {
					counter = tmp;
				}
		}
		
		
		if (counter == 'n')
			flag = 0;
		if (counter == 'y')
			continue;
	}
}


void scan_pr(char* a) {
	int i;
	char tmp;
	scanf("%c", &tmp);
	if (tmp == '\n') {
		for (i = 0; i < 4; i++) {
			scanf("%c", &a[i]);
		}
	}
	else {
		a[0] = tmp;
		for (i = 1; i < 4; i++) {
			scanf("%c", &a[i]);
		}
	}
}


int ind_pr(char* b) {
	int i, j, flag = 1;
	for (i = 0; i < 10; i++) {
		flag = 1;
		for (j = 0; j < 4; j++) {
			if (codes[i][j] != b[j]) {
				flag = 0;
			}

		}
		if (flag == 1)
			return i;
	}
	printf("Incorrect data. Try again:\n");
	return -1;
}

void info_pr(int ind,double* a, double* b) {
	int i;
	for (i = 0; i <= 6; i++)
		printf("%c"  , names[ind][i]);
	printf("cost = %d ", cost[ind]);
	printf("sale = %g ", a[ind]);
	printf("total %g \n", b[ind]);
}

void f_cheque(int* k_pr, double* cost_sale) {
	int i, j;
	double total_cost[10] = { 0 };
	printf("\n");
	printf("Your cheque: \n");
	for (i = 0; i < 10; i++) {
		total_cost[i] = k_pr[i] * cost_sale[i];
	}

	for (i = 0; i < 10; i++) {
		if (k_pr[i] != 0) {
			for (j = 0; j <= 6; j++)
				printf("%c", names[i][j]);
			printf("cost %g ", cost_sale[i]);
			printf("quantity = %d ", k_pr[i]);
			printf("total cost = %g \n", total_cost[i]);
		}
	}
}

void f_total(double a, double b, double c, int* k, double* arrA, double* arrB) {
	int i, a1, b1, c1;
	for (i = 0; i < 10; i++) {
		a += k[i] * cost[i];
		b += k[i] * arrA[i];
		c += k[i] * arrB[i];
	}
	a1 = (int)a;
	b1 = (int)b;
	c1 = (int)c;
	printf("Cost without discount = %d \nThe amount of discounts = %d\nCost including discounts = %d\n", a1, b1, c1);
}