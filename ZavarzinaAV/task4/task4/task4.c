#include <stdio.h>
#include <locale.h>
#define N 10 


void scan_products(int ba[N][4], char product[N][20], int price[N], int sale[N], int count[N]) {

	int a[4]; //цифры шк
	int b, c;
	int cnt = 0; //счетчик совпавших чисел

	do {
		printf("Введите штрих код товара: \n");
		scanf_s("%d", &b);
		c = b;
		for (int i = 3; i >= 0; i--) { //b=1234
			a[i] = b % 10;
			b = b / 10;
		} //a={1, 2, 3, 4}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[j] == ba[i][j]) {
					cnt += 1;
				}
			}
			if (cnt == 4) {
				count[i]++;

				printf("штрих-код: %d\n", c);
				printf("название товара: %s\n", product[i]);
				printf("цена: %d\n", price[i]);
				printf("скидка: %d\n", sale[i]);
			}
			cnt = 0;
		}
	} while (c != 0);

}

int main() {

	setlocale(LC_ALL, "");

	int sum = 0;
	int sum_sale = 0;
	int sum_with_sale = 0;

	int ba[N][4] = { {1, 2, 3, 4}, {8, 0, 1, 2}, {3, 4, 5, 6}, {6, 7, 8, 9}, {1, 0, 0, 1}, {6, 0, 8, 2}, {1, 0, 1, 3}, {1, 7, 8, 6}, {9, 3, 3, 1}, {2, 2, 3, 6}}; //база данных шк
	char product[N][20] = {"яблоки (кг)", "арбуз", "апельсины(кг)", "дыня", "бананы(кг)", "кабачки(кг)", "перцы(кг)", "огурцы(кг)", "помидоры(кг)", "баклажаны(кг)"};
	int price[N] = { 200, 500, 100, 600, 150, 170, 220, 130, 300, 450 };
	int sale[N] = { 7, 10, 5, 15, 7, 12, 5, 25, 75, 50 };
	int count[N] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; //количество раз отсканированного товара 

	scan_products(ba, product, price, sale, count);

	printf("-------------------------------------------------------------------------------\n");
	printf("ТОВАР                 ЦЕНА    СКИДКА    ЦЕНА СО СКИДКОЙ    КОЛИЧЕСТВО\n");
	printf("-------------------------------------------------------------------------------\n");

	for (int i = 0; i < N; i++) {
		if (count[i] > 0) {

			int price_with_sale = price[i] * (100 - sale[i]) / 100;

			int total_price = price[i] * count[i]; //цена всех единиц товара без скидки 
			int total_discount = (price[i] * sale[i] / 100) * count[i]; //сумма скидки на все купленные единицы товара
			int total_price_with_sale = price_with_sale * count[i];

			printf(" %-18s %5d %5d%% %10d %20d\n", product[i], price[i], sale[i], price_with_sale, count[i]);

			sum += total_price;
			sum_sale += total_discount;
			sum_with_sale += total_price_with_sale;
		}
	}

	printf("--------------------------------------------------------------------------------\n");
	printf("цена без скидки: %d\n", sum);
	printf("скидка: %d руб\n", sum_sale);
	printf("общая стоимость всех товаров со скидкой: %d\n", sum_with_sale);
	printf("---------------------------------------------------------------------------------\n");

	return 0;
} 