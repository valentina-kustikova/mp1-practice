#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define wordlength 10
void main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	int f = 0, mode, code, i, j, a=0;
	char name[N][wordlength] = { "milk" , "bread" , "juice" , "apple" , "butter" , "water" , "salt" , "meet" , "banana" , "chocolate" };
	int cost[N] = { 50, 30, 70, 15, 45, 10, 20, 500, 100, 90 };
	int discount[N];
	int kolvo[N] = { 0 };
	for (j = 0; j < N; j++)
	discount[j] = rand() * (1 - 50) / RAND_MAX + 50;
	do
	{
		printf("¬ыберите режим работы:\n");
		printf("¬ведите 1, чтобы сканировать очередной товар\n");
		printf("¬ведите 2, чтобы вывести описание отсканированного товара\n");
		printf("¬ведите 3, чтобы добавить данные о товаре в чек\n");
		printf("¬ведите 4, чтобы сформировать чек за покупку\n");
		printf("¬ведите 5, чтобы рассчитать итоговую сумму к опалте\n");
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
		{
			printf("¬ведиет штрих-код товара(1-10)\n");
			do
			scanf("%d", &code);
			while ((code < 1) || (code > 10));
			break;
		}
		case 2:
		{
			printf("штрих-код:""%d\n", code);
			for (i = 0; i < wordlength; i++)
				printf("%c", name[code-1][i]);
			printf("цена(руб.):""%d\n", cost[code-1]);
			printf("скидка(проц.):""%d\n", discount[code-1]);
			break;
		}
		case 3:
		{
			printf("товар добавлен в чек!\n");
			kolvo[code - 1]++;
			break;
		}
		case 4:
		{
			for (j = 0; j < N; j++)
			{
				if (kolvo[j] != 0)
				{
					for (i = 0; i < wordlength; i++)
						printf("%c", name[j][i]);
					printf("колличестов:""%d", kolvo[j]);
					printf("цена:""%d", cost[j]);
					printf("обща€ стоимость:""%d", kolvo[j]*cost[j]);
					a +=(cost[j]-(cost[j]*discount[j]/100))*kolvo[j];
				}
			}
			break;
		}
		case 5:
		{
			printf("итогова€ сумма к оплате с учетом скидок:");
			printf("%d", a);
		}
		}
	} while (mode != 5);
}