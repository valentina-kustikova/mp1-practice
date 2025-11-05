#include <stdlib.h>
#define N 10000
#include <stdio.h>
#include <locale.h>

void recorde(int volume, int barcodearr[]) {
	int a;
	for (int i = 0; i < volume; i++) {
		printf("Введите ШК\n");
		scanf_s("%d", &a);
		barcodearr[a]++;
	}
}

//void fill(char name[N][15], float cost[], float discont[], int size) {
//	int barcode = 0;
//	for (int i = 0; i < size;i++) {
//		printf("ШТРИХКОД: ");
//		scanf_s("%d", &barcode);
//		printf("НАИМЕНОВАНИЕ: ");
//		scanf_s("%14s", &(name[barcode]), 15);
//		printf("ЦЕНА: ");
//		scanf_s("%f", &(cost[barcode]));
//		printf("СКИДКА: ");
//		scanf_s("%f", &(discont[barcode]));
//	}
//}
//
//void printExample() {
//	printf("\nВведите базу данных в следующем формаете\n<ШТРИХКОД>\n<НАИМЕНОВАНИЕ>\n<ЦЕНА>\n<СКИДКА ОТ 1 ДО 50>");
//	printf("\n\nПРИМЕР:\n");
//	printf("ШТРИХКОД ТОВАРА: 1234\nНАЗВАНИЕ ТОВАРА: БАНАНЫ\nЦЕНА ТОВАРА БЕЗ СКИДКИ: 100\n30\n\n");
//}

void print(int barcodearr[], char name[N][15], float cost[], float discont[]) {
	int i = 0;
	float r = 0;
	float all = 0;
	for (;i < N - 1; i++) {
		if (barcodearr[i] > 0) {
			printf("\n\nШТРИХКОД ТОВАРА:\n %d", i);
			printf("\nНАЗВАНИЕ ТОВАРА:\n %s", name[i]);
			printf("\nЦЕНА ТОВАРА БЕЗ СКИДКИ:\n %.1f", cost[i]);
			printf("\nКОЛИЧЕСТВО ТОВАРОВ:\n %d", barcodearr[i]);
			r = barcodearr[i] * cost[i];
			printf("\nЦЕНА ЗА ВСЕ ТОВАРЫ БЕЗ СКИДКИ:\n %.1f", r);
			r = barcodearr[i] * cost[i] * (1 - (discont[i]) / 100);
			all += r;
			printf("\nЦЕНА ЗА ВСЕ ТОВАРЫ СО СКИДКОЙ:\n %.1f\n", r);
		}
	}
	printf("Общая сумма = %.1f", all);
	}
int main() {
	int n, barcode, volume;
	barcode = 0;
	char name[N][10]; float cost[N]; float discont[N]; int size; int barcodearr[N] = { 0 };

	setlocale(LC_ALL, "Rus");
	//printf("Введите какое количество товаров вы желаете добавить в БАЗУ ДАННЫХ (от 1 до 9999): ");
	//scanf_s("%d", &n);
	//printExample();
	//fill(name, cost, discont, n);
	printf("Введите ШК вашего товара или -1 для выхода: ");
	do
	{
		scanf_s("%d", &volume);
		recorde(volume, barcodearr);
	} while (n != -1);
	print(barcodearr, name, cost, discont);
	return 0;
}