#include <stdio.h>
#include <locale.h>
#define N 10

int sthcode(int sht[])
{
	int i, c;
	setlocale(LC_ALL, "Rus");
	printf("Введите штрих-код от 10 до 19: \n");
	do
	{
		scanf_s("%d", &c);
	} while (c < 10 || c > 19);
	for (i = 0; i < N; i++)
	{
		sht[i] == c;
		return i;
	}
}
void information(char tovar[][8], int c[], int p[], float s[], int b)
{
	int i;
	setlocale(LC_ALL, "Rus");
	printf("Информация о товаре: \n");
	for (i = 0; i < 8; i++)
		printf("%c", tovar[b][i]);
	printf(" \n");
	printf("Цена: %d \n", p[b]);
	printf("Скидка: %0.0f \n", s[b]);
}
void check(char tovar[][8], int p[], float s[], int colvo[], float price)
{
	int i, j;
	printf("--------------------------------------------------------\n");
	for (i = 0; i < N; i++)
	{
		if (colvo[i] != 0)
		{
			printf("Наименование: ");
			for (j = 0; j < 10; j++)
			{
				printf("%c", tovar[i][j]);
			}
			printf(" \n");
			printf("Стоимость 1 шт.: %d руб. \n", p[i]);
			printf("Количесво: %d \n", colvo[i]);
			printf("Скидка: %0.0f \n", s[i]);
			printf("Цена со скидкой: %.2f  \n", (p[i] + (p[i] * s[i]) / 100.0) * colvo[i]);
		}
	}
	printf("--------------------------------------------------------\n");
	printf("К оплате: %.2f \n", price);
}
float sum(int p[], float s[], int b)
{
	int i;
	float sum = 0.0;
	for (i = 0; i < N; i++)
	{
		sum = (p[b] * s[b]) / 100.0 + p[b];
	}
	return sum;
}
void main()
{
	int c[N] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	char tovar[N][8] = { "Молоко" , "Хлеб" , "Апельсин" , "Яйца" , "Йогурт" , "Конфеты" , "Мясо" , "Сок" , "Печенье" , "Виноград" };
	int p[N] = { 60, 18, 30, 80, 25, 62, 200, 80, 70, 50};
	float s[N] = { 5, 10, 30, 40, 15, 2, 18, 25, 35, 3 };
	int number;
	int b;
	float price = 0;
	int shtrih[] = { 0 };
	setlocale(LC_ALL, "Rus");
	printf("1 - отсканировать товар \n");
	printf("2 - распечатать чек \n");
	scanf_s("%d", &number);
	switch (number)
	{
		case 1:
		{
			b = sthcode(c);
			shtrih[b] = shtrih[b] + 1;
			information(tovar, c, p, s, b);
			price += sum(p, s, b);
			break;
		}
		case 2:
		{
			check(tovar, p, s, shtrih, price);
			break;
		}
	}
}