#include <stdio.h>
#include <locale.h>
#define N 10

int checkshtixcode(int sh[])
{
	int d;	
	do
	{
		printf("Введите штрих-код от 1715 до 1724: ");
		scanf("%d", &d);
	} while (d < 1715 || d > 1724);
	for (int i = 0; i < N; i++)
		if (d == sh[i])
			return i;
}

void producte_information(char prod[][18], float price[], float skidka[], int sht[], int c)
{
	printf("Информация о товаре:\n");
	for (int i = 0; i < 18; i++)
		printf("%c", (prod[c][i]));
	printf("\nШтрих-код товара: %d\n", sht[c]);
    printf("Стоимость за 1 шт.: %0.0f руб.\n", price[c]);
	printf("Скидка на товар: %0.0f \n", skidka[c]);
}

float summ(float price[], float skidka[], int c)
{
	float sum = price[c] - price[c] * skidka[c] / 100;
	return sum;
}

void printcheck(char tovar[][18], float price[], float skidka[], int colvo_tovar[], float price1)
{
	printf("--------------------------------------------------------\n");
	for (int i = 0; i < N; i++)
	{
		if (colvo_tovar[i] != 0)
		{
			printf("--------------------------------------------------------\n");
			printf("Наименование: ");
			for (int j = 0; j < 18; j++)
			{
				printf("%c", tovar[i][j]);
			}
			printf(" \nСтоимость за 1 шт.: %0.0f руб. \n", price[i]);
			printf("Количесво: %d шт.\n", colvo_tovar[i]);
			printf("Скидка: %0.0f \n", skidka[i]);
			printf("Цена со скидкой: %.2f руб. \n", ((price[i] - (price[i] * skidka[i]) / 100.0) * colvo_tovar[i]));
		}
	}
	printf("--------------------------------------------------------\n");
	printf("Итоговая сумма к оплате: %.2f руб. \n", price1);
}


void main()
{
	setlocale(LC_ALL, "Rus");
	int shtrix[N] = { 1715, 1716, 1717, 1718, 1719, 1720, 1721, 1722, 1723, 1724 };
	char tovar[N][18] = { "Coca-Cola 2л", "Lays Краб", "Хлеб", "Молоко", "AlpenGold", "Сок Добрый 1л", "Булка с сыром", "Макароны","Сахар 1кг", "Чай Greenfield" };
	float price[N] = { 121.0, 99.99, 31.50, 68.49, 73.99, 55.99, 16.49, 45.0, 49.0, 150.0 };
	float skidka[N] = { 5.0, 50.0, 5.0, 10.0, 50.0, 30.0, 5.0, 25.0, 15.0, 20.0 };
	int colvo_tovar[150] = { 0 };
	float price1 = 0;
	int n, x;
	while (1)
	{
		printf("Введите 0, чтобы сканировать товар\n");
		printf("Введите 1, чтобы распечатать чек\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
		{
			x = checkshtixcode(shtrix);
			producte_information(tovar, price, skidka, shtrix, x);
			colvo_tovar[x]++;
			price1 += summ(price, skidka, x);
			break;
		}
		case 1:
		{
			printcheck(tovar, price, skidka, colvo_tovar, price1);
			break;
		}
		}
	}
}
