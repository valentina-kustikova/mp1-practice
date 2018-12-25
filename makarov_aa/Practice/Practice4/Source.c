#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define D 5
#define namelength 4
void main()
{
	char name[D][namelength] = { "milk", "eggs", "corn", "fish", "meat" };
	int cena[D] = { 70, 50, 100, 200, 300 };
	int skidka[D] = { 50, 66, 90, 80, 60 };
	int code[D] = { 1, 2, 3, 4, 5 };
	int kolvo[D] = { 0 };
	int summa = 0, fullst = 0, mode, scode, i, j, check, fullskidka;
	setlocale(LC_ALL, "Russian");
	printf("1 - сканирование товара\n");
	printf("2 - вывести описание отсканированного товара\n");
	printf("3 - сформировать чек на покупку\n");
	printf("4 - рассчитать итоговую стоимость покупки\n");
	do
	{
	do
	{
		printf("Введите режим работы программы\n");
		scanf("%d", &mode);
	} while (mode > 4 || mode < 1);
		switch (mode)
		{
			case 1:
			{
				do
				{
				printf("Введите штрих-код для сканирования\n");
				scanf("%d", &scode);
				} while (scode > 5 || scode < 1);
				kolvo[scode - 1]++;
				break;
			}
			case 2:
			{
				do
				{
					printf("Введите штрих-код отсканированного товара\n");
					scanf("%d", &scode);
				} while (scode > 5 || scode < 1);
				if (kolvo[scode - 1] == 0)
					printf("Данный товар не отсканирован\n");
				else
				{
					printf("%d    ", scode);
					for (i = 0; i < namelength; i++)
						printf("%c", name[scode - 1][i]);
					printf("    %d", cena[scode - 1]);
					printf("    %d\n", skidka[scode - 1]);
					break;
				}
			}
			case 3:
			{
				check = 0;
				for (j = 0; j < 5; j++)
					if (kolvo[j] != 0)
					{
						fullst += cena[j] * kolvo[j];
						summa += cena[j] * kolvo[j] * skidka[j] / 100;
						for (i = 0; i < namelength; i++)
							printf("%c", name[j][i]);
						printf("    %d", cena[j]);
						printf("    %d", kolvo[j]);
						printf("    %d", cena[j] * kolvo[j]);
						printf("    %d\n", cena[j] * kolvo[j] * skidka[j] / 100);
						check++;
					}
				if (!check) printf("Нет ни одного отсканированного товара\n");
				break;
			}
			case 4:
			{
				for (j = 0; j < D; j++)
				{
				}
				fullskidka = fullst - summa;
				printf("Общая стоимость - %d\n", fullst);
				printf("Общая скидка - %d\n", fullskidka);
				printf("К оплате - %d\n", summa);
				break;
			}
		}
	} while (mode != 4);
}
