#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int skidka()
{
	int s;
	srand((unsigned int)time(0));
	s = rand() % (50) + 1;
	return s;
}
void wehave(char *name[], int qr[][4], int count[])
{
	char *name1[] = { "яблоко","банан","виноград","куриное филе","картофель (1кг)", "молоко", "творог", "колбаса", "йогурт", "вода (0.5 литра)" };
	int qr1[10][4] = {{0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 2}, {0, 0, 0, 3}, {0, 0, 0, 4}, {0, 0, 0, 5}, {0, 0, 0, 6}, {0, 0, 0, 7}, {0, 0, 0, 8}, {0, 0, 0, 9}};
	int count1[10] = { 15, 20, 100, 300, 50, 80, 150, 250, 80, 50 };
	int i = 0;
	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		count[i] = count1[i];
		name[i] = name1[i];
		for (int j = 0; j < 4; j++)
		{
			qr[i][j] = qr1[i][j];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char* name[10]; 
	int qr[10][4]; 
	int count[10];
	int i = 0;
	int ch = -1;
	int prnow[4] = {-1, -1, -1, -1};
	int korzina[10] = { 0 };
	wehave(name, qr, count);
	printf("В наличии: \n");
	for (; i < 10; i++)
	{
		printf("Qr: %d %d %d %d \n", qr[i][0], qr[i][1], qr[i][2], qr[i][3]);
		printf("Наименование: %s \n", name[i]);
		printf("Цена: %d руб \n \n", count[i]);
	}

	do
	{
		printf("Отсканируйте первый товар: ");
		for (i = 0; i < 4; i++)
		{
			scanf_s("%d", &prnow[i]);
		}
	} while (prnow[0]!=0 || prnow[1]!=0 || prnow[2]!=0 || prnow[3]<0 || prnow[3]>9);
	korzina[prnow[3]]++;
	do
	{
		printf("Если хотите отсканировать следующий товар - 0, если хотите получить чек - 1: ");
		scanf("%d", &ch);
		if (ch == 0) {
			do
			{
				printf("Отсканируйте товар: ");
				for (i = 0; i < 4; i++)
				{
					scanf_s("%d", &prnow[i]);
				}
			} while (prnow[0] != 0 || prnow[1] != 0 || prnow[2] != 0 || prnow[3] < 0 || prnow[3]>9);
			korzina[prnow[3]]++;
		}
	} while (ch!=1);
	for (i = 0; i < 10; i++)
	{
		printf("%d", korzina[i]);
	}

	return 0;
}
