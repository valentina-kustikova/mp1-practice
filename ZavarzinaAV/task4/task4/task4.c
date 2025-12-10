#include <stdio.h>
#include <locale.h>
#include <string.h>
#define N 10 


void scan_products(char ba[N][5], char product[N][20], int price[N], int sale[N], int count[N]) {
	
	char b[20];

	do {
		printf("Введите штрих код товара: \n");
		scanf_s("%s", b, (unsigned)sizeof(b));
		
		if (strcmp(b, "0") == 0) break;

		for (int i = 0; i < N; i++) {
			if (strcmp(b, ba[i])== 0){
				count[i]++;

				printf("штрих-код: %s\n", b);
				printf("название товара: %s\n", product[i]);
				printf("цена: %d\n", price[i]);
				printf("скидка: %d\n", sale[i]);
			}
		}
	} while (1);

}

int main() {

	int sum = 0;
	int sum_sale = 0;
	int sum_with_sale = 0;

	char ba[N][5] = { "1234", "8012", "3456", "6789", "1001", "6082", "1013", "1786", "9331", "2236" };
	char product[N][20] = {"яблоки (кг)", "арбуз", "апельсины(кг)", "дыня", "бананы(кг)", "кабачки(кг)", "перцы(кг)", "огурцы(кг)", "помидоры(кг)", "баклажаны(кг)"};
	int price[N] = { 200, 500, 100, 600, 150, 170, 220, 130, 300, 450 };
	int sale[N] = { 7, 10, 5, 15, 7, 12, 5, 25, 75, 50 };
	int count[N] = { 0 }; //количество раз отсканированного товара 

	setlocale(LC_ALL, "");

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