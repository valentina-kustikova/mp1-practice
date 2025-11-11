#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

int skidka()
{
	int s;
	s = rand() % (50) + 1;
	return s;
}
void wehave(char* name[], char* qr[], int count[], int skidki[])
{
	char* name1[] = { "яблоко","банан","виноград","куриное филе","картофель (1кг)", "молоко", "творог", "колбаса", "йогурт", "вода (0.5 литра)" };
	char* qr1[10] = { "0000", "0001","0002","0003","0004","0005","0006","0007","0008","0009" };
	int count1[10] = { 15, 20, 100, 300, 50, 80, 150, 250, 80, 50 };
	int i = 0;
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		skidki[i] = skidka();
		count[i] = count1[i];
		name[i] = name1[i];
		qr[i] = qr1[i];
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	char* name[10];
	char* qr[10];
	int count[10];
	int skidki[10];
	int i = 0;
	int ch = -1;
	char qrnow[5] = "9999";
	int korzina[10] = { 0 };
	int sumk = 0;
	int sumsk = 0;
	wehave(name, qr, count, skidki);
	printf("В наличии: \n");
	for (i=0; i < 10; i++)
	{
		printf("Qr: %s \n", qr[i]);
		printf("Наименование: %s \n", name[i]);
		printf("Цена: %d руб \n \n", count[i]);
	}
	do
	{
		i = 0;
		printf("Отсканируйте первый товар: \n");
		scanf_s("%s", qrnow, (unsigned)sizeof(qrnow));
		for (; i < 10; i++)
		{
			if (strcmp(qrnow, qr[i]) == 0)
				break;
		}
	} while (i == 10);
	korzina[i]++;
	do {
		do
		{
			printf("Если хотите отсканировать следующий товар - 0, если хотите получить чек - 1: ");
			scanf_s("%d", &ch);
		} while (ch != 0 && ch != 1);
		if (ch == 0) {
			do
			{
				i = 0;
				printf("Отсканируйте товар: ");
				scanf_s("%s", qrnow, (unsigned)sizeof(qrnow));
				for (; i < 10; i++)
				{
					if (strcmp(qrnow, qr[i]) == 0)
						break;
				}
			} while (i == 10);
			korzina[i]++;
		}
	} while (ch != 1);
	/*for (i = 0; i < 10; i++) {
	 printf("%d", korzina[i]);
	}*/
	for (i = 0; i < 10; i++) {
		if (korzina[i] > 0) {
			printf("Наименование: %s \n", name[i]);
			printf("Цена за единицу: %d руб \n", count[i]);
			printf("Количество: %d \n", korzina[i]);
			printf("Скидка: %d%% \n", skidki[i]);
			printf("Общая цена: %d руб \n \n", (count[i] * korzina[i] - (count[i] * korzina[i]) * (skidki[i]) / 100));
			sumk += count[i] * korzina[i];
			sumsk += (count[i] * korzina[i]) * (skidki[i]) / 100;
		}
	}
	printf("общая стоимость: %d \n", sumk);
	printf("суммарная скидка: %d \n", sumsk);
	printf("итоговая сумма к оплате: %d", sumk - sumsk);
	return 0;
}