#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#define N 10

void recorde(char barcode[][10], char name[][10], float cost[], float discont[]) {
	strcpy_s(barcode[0], 10, "0000");
	strcpy_s(name[0], 10, "banan");
	cost[0] = 100;
	discont[0] = 0;

	strcpy_s(barcode[1], 10, "0001");
	strcpy_s(name[1], 10, "salt");
	cost[1] = 200;
	discont[1] = 10;

	strcpy_s(barcode[2], 10, "0002");
	strcpy_s(name[2], 10, "sugar");
	cost[2] = 400;
	discont[2] = 20;

	strcpy_s(barcode[3], 10, "0003");
	strcpy_s(name[3], 10, "apple");
	cost[3] = 300;
	discont[3] = 30;
}
void buy(char barcode[][10], int total[]) {
	char nbar[N];
	strcpy_s(nbar, 10, "1111");
	do {
		int j = 0;
		printf("\nСканируйте баркода товара. Если желаете закончить покупку, напишите <pay>\n");
		scanf_s("%9s", &nbar, 10);
		for (;j != N; j++) {
			if (strcmp(barcode[j], nbar) == 0) {
				total[j]++;
			}
		}
	} while (strcmp(nbar, "pay") != 0);
}
void Receipt(char barcode[][10], char name[][10], float cost[], float discont[], int total[]) {
	int j = 0;
	float r = 0;
	float alld = 0;
	float all = 0;
	printf("\nВот ваш чек:");
	for (; j < N; j++) {
		if (total[j] != 0) {
			printf("\nНазвание товара - %s", barcode[j]);
			printf("\nСтоимость товара за единицу - %.1f", cost[j]);
			printf("\nКоличество единиц товара - %d", total[j]);
			r = total[j] * cost[j];
			all += r;
			printf("\nОбщая стоимость за данный товар без скидки - %.1f", r);
			r = (1 - discont[j]/100) * r;
			alld += r;
			printf("\nОбщая стоимость за данный товар со скидкой - %.1f\n", r);
		}
	}
	printf("\n\nОбщая стоимость всех товаров без скидки - %.1f", all);
	printf("\nОбщая стоимость всех товаров со скидкой - %.1f\n", alld);
}
int main() {
	setlocale(LC_ALL, "Rus");
	char barcode[N][10];
	char name[N][10];
	float cost[N];
	float discont[N];
	int total[N] = { 0 };
	recorde(barcode, name, cost, discont);
	buy(barcode, total);
	Receipt(barcode, name, cost, discont, total);
	return 0;
}
