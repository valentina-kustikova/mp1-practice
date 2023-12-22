#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define N 6
#define MAX_LEN 254

char* baza[N] = { "1111", "1201","1301", "1401", "2402","1503" };
char* names[N] = { "Хлеб", "Вода","Молоко", "Пельмени", "Макароны", "Шоколад" };
double price[N] = { 30.0, 40.0, 70.0, 150.0, 95.0, 80.0 };
double sale[N];

void make_sale(int n);
void tovar_info(int i, int k);
int chek_shtrih(int n, char *shtrih);
void chek(int *kt, double *sum, double *r_skidka);

int main() {
	int i;
	char shtih[MAX_LEN];
	double r_skidka, sum;
	int kt[N] = { 0, 0, 0, 0, 0, 0 };
	setlocale(LC_ALL, "Rus");
	printf("Введите штрихкод товара, для завешения покупки введите 'res'\n");
	make_sale(N);
	do {
		scanf("%s", &shtih);
		i = chek_shtrih(N, &shtih[0]);
		if (i == -1) {
			printf("Неверный штрихкод\n");
			continue;
		}
		if(i!=-2){
			tovar_info(i, 0);
			kt[i]++;	
		}
	} while (strcmp(shtih, "res")!=0);
	printf("\n");
	printf("\nВаш чек\n");
	chek(&kt[0], &sum, &r_skidka);
	printf("\nЦена без скидки составляет %.2lf\n", sum);
	printf("Скидка составляет %.2lf\n", r_skidka);
	printf("К оплате: %.2lf\n", sum - r_skidka);
	return 0;
}
void make_sale(int n) {
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++) {
		sale[i] = (1+rand() %50)*0.01;
	}
}
void tovar_info(int i, int k) {
	printf("Наименование товара %s\n", names[i]);
	printf("Цена %.2lf\n", price[i]);
	printf("Скидка %.0lf%%\n", sale[i]*100);
	if (k != 0) {
		printf("Количество: %d\n", k);
	}
}

int chek_shtrih(int n, char *shtrih) {
	int i;
	if (strcmp(shtrih, "res") == 0) {
		printf("Завершение покупки\n");
		return -2;
	}
	for (i=0; i < n; i++) {
		if (strcmp(shtrih, baza[i])==0) {
			return i;
		}
	}
	return -1;
}

void chek(int* kt, double* sum, double* r_skidka) {
	int i = 0;
	*sum = 0.0;
	*r_skidka = 0.0;
	for (i = 0; i < N; i++) {
		*sum += (double)(kt[i] * price[i]);
		*r_skidka += price[i] * sale[i] * kt[i];
		if (kt[i] != 0) {
			tovar_info(i, kt[i]);
		}
	}
}