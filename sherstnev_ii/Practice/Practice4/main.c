#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 5

char* Names[N] = { "Хлеб", "Молоко", "Сыр", "Сметана", "Кефир"};
char Codes[N][5] = {"0234", "1235", "1236", "1237", "1238"};
int Prices[N] = { 0 };
int Discounts[N] = { 0 };
int Count[N] = { 0 };

void Scan() {
	char Code[5];
	int i = 0, flag = -1;
	printf("Введите штрих-код товара: #");
	fflush(stdin);
	fgets(Code, 5, stdin);
	for (i; i < N; i++) {
		if (Codes[i] == Code) flag = i;
	}
	if (flag != -1) {
		fputs(Names[flag], stdout);
		printf(" %d р со скидкой %d % \n", Prices[flag], Discounts[flag]);
	}
	else {
		printf("Такого товара не существует\n");
	}
}

void AddToCheck() {
	char Code[5];
	int i, flag = 0;
	printf("\nВведите штрих-код товара, который вы хотите добавить: #");
	fflush(stdin);
	fgets(Code, 5, stdin);
	for (i = 0; i < N; i++) {
		if (Codes[i] == Code) flag = i;
	}
	if (flag != 0) {
		printf("\nКакое количество товара вы хотите добавить? (Введите 0, если не хотите добавлять) \n");
		scanf("%d", &Count[flag - 1]);
		if(Count[flag - 1] != 0)
			printf("\nТовар успешно добавлен\n");
	}
	else {
		printf("\nТакого товара не существует\n");
	}
}

void Print() {
	int i, TotalPrice = 0, TotalDiscount = 0, flag = 0;
	for (i = 0; i < N; i++) {
		if (Count[i] > 0) flag = 1;
	}
	if (flag > 0) {
		printf("\n=====Чек=====\n");
		for (i = 0; i < N; i++) {
			if (Count[i] != 0) {
				TotalPrice += Prices[i] * Count[i];
				TotalDiscount += Prices[i] * Count[i] * Discounts[i] / 100;
				fputs(Names[i], stdout);
				printf("   %d   %d   %d \n", Prices[i], Count[i], Prices[i] * Count[i]);
			}
		}
		printf("Общая стоимость: %d р \n", TotalPrice);
		printf("Суммарная скидка: %d р \n", TotalDiscount);
		printf("Итоговая стоимость: %d р \n \n", TotalPrice - TotalDiscount);
	}
	else {
		printf("Корзина пуста, вывести чек невозможно\n");
	}
}

void main() {
	int i, j = 0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	for (i = 0; i < N; i++) {
		Prices[i] = 50 + rand() % 3000;
		Discounts[i] = 1 + rand() % 50;
		Count[i] = 0;
	}
	do {
		printf("Введите 1, чтобы отсканировать товар\n"); 
		printf("Введите 2, чтобы добавить товар в корзину\n");
		printf("Введите 3, чтобы напечатать чек\n");
		printf("Введите 0, чтобы выйти\n");
		scanf("%d", &j);
		if (j == 1)
			Scan();
		else if (j == 2)
			AddToCheck();
		else if (j == 3)
			Print();
	} while (j != 0);
}