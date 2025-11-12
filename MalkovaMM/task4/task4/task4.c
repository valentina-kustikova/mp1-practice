#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

int korzina[10] = { 0 };

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

void check(int korzina[], char* name[], int skidki[], int count[])
{
	int sumk = 0;
	int sumsk = 0;
	int i;
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
	if (sumk == 0) {
		printf("чек пуст");
	}
	else {
		printf("общая стоимость: %d руб \n", sumk);
		printf("суммарная скидка: %d руб \n", sumsk);
		printf("итоговая сумма к оплате: %d руб", sumk - sumsk);
	}
}

void scan(char* qr[])
{
	int ch = -1;
	int sc = -1;
	int i = 0;
	char qrnow[5] = "9999";
	do {
		do
		{
			printf("Если хотите отсканировать товар - 0, если хотите получить чек - 1: ");
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
			printf("Добавить товар? Да - 0: ");
			scanf_s("%d", &sc);
			if (sc==0)
				korzina[i]++;
		}
	} while (ch != 1);
}

void menu(char* qr[], char* name[], int count[]) {
	int i = 0;
	printf("В наличии: \n");
	for (i = 0; i < 10; i++)
	{
		printf("Qr: %s \n", qr[i]);
		printf("Наименование: %s \n", name[i]);
		printf("Цена: %d руб \n \n", count[i]);
	}
}


int main()
{
	char* name[10];
	char* qr[10];
	int count[10];
	int skidki[10];
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	wehave(name, qr, count, skidki);
	menu(qr, name, count);
	scan(qr);
	check(korzina, name, skidki, count);
	return 0;
}