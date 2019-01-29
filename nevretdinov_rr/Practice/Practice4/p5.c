#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 
#include<stdio.h> 

void Name(int o)
{
	if (o == 0)
		printf_s("Молоко\n");
	if (o == 1)
		printf_s("Garage\n");
	if (o == 2)
		printf_s("Яблоки\n");
	if (o == 3)
		printf_s("Разарв\n");
	if (o == 4)
		printf_s("Грудинка по Нижегородски\n");
}
void main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));

	int NW; //номер штрихкода 
	int sh[5] = { 6531, 6532, 6533, 6534, 6535 }; // массив штрихкодов
	int k[5] = { 0 }; // количество выбранных товаров, которое будет в чеке 
	int a[5] = { 70, 60, 180, 100, 200 }; // цена за единицу(упаковку) 
	int s[5] = { 0 }; // тут будут хранится посчитанные цены со скидкой, учитывая количество 
	int sale[5] = { 0 };
	int i;
	int r; 
	int I = 0; // итого 
	int S = 0; // скидка 

	printf("Введите номер штрихкода из существующих:\n 6531\n 6532\n 6533\n 6534\n 6535\n Введите 0, чтобы сформировать чек.\n");
	scanf("%d", &NW);

	for (i = 0; i < 5; i++)
		sale[i] = 1 + rand() % 50;

	while (NW >= 6531 && NW <= 6535)
	{
		
		for (i = 0; i < 5; i++)
		{
			if (NW == sh[i])
			{
				r = i;
			}
		}
				k[r]++;
				Name(r);
				printf("Скидка %d\n", sale[r]);
				s[r] = a[r] * k[r] - (a[r] * sale[r] * k[r] / 100);
				printf("Цена с учетом скидки и кол-ва %d\n", s[r]);
			
			printf("\n");
			scanf("%d", &NW);

			if (NW == 0)
				break;
		}

		for (i = 0; i < 5; i++)
		{
			S = S + (a[i] * k[i] - s[i]);
			I = I + s[i];
		}

		// чек 
		printf("\n\n");
		printf("ВАШ ЧЕК\n");

		for (i = 0; i < 5; i++)
		{
			if (k[i] != 0)
			{
				Name(i);
				printf("цена за единицу %d, шт %d, цена с учетом кол-ва и скидки %d\n", a[i], k[i], s[i]);
			}
		}
		printf("ВАША СКИДКА В РУБ %d\n", S);
		printf("ИТОГО В РУБ: %d\n", I);
		printf("СПАСИБО ЗА ПОКУПКУ!\n");
	}

