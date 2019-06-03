#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

 void name(char a[4][9], int n, char str[])//функция получает на вход массив с элементами слов, штрих-код по которому формируется слоава и массив в который записывается слово
{
	int i, j, q, w;
	w = 0;
	for (i = 0; i < 4; i++)
	{
		q = n % 10;
		n /= 10;
		for (j = 0; j < 9; j++)
			if (j == q)
			{
				str[w]=a[i][j];
				w++;
			}
	}
}

void main()
{
	char str[100] = {0};
	float discounts[9999] = {0};//массив скидок
	int check[9999] = {0};//массив для чека
	char names[4][9] = //массив с символами для состовления названий
	{{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o'}, 
        {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'}, 
	{'z', 'x', 'c', 'v', 'b', 'n', 'm', '1', '2'},
        {'3', '4', '5', '6', '7', '8', '9', '0', '!'}};
	int prices[9999];//массив со скидками
	int i, pick, user_choose, q;
	float s;
	srand((unsigned int) time(0));
	s = 0;
	setlocale(LC_ALL, "Russian");
	for(i = 1; i < 9999; i++)
	{
		prices[i] = rand()%1000;
	}
	for(i = 1; i < 9999; i++)
	{
		discounts[i] = rand() %50 * 0.01f;
	}
	user_choose = -1;
	do {
		printf("\nМеню функций\n");
		printf(" 1 - сканировать товар\n 2 - вывод описания отсканированного товара\n");
		printf(" 3 - добавить данные о товаре в чек\n 4 - сформировать чек\n 5 - расчитать итоговую сумму\n");
		scanf("%d", &pick);
		switch (pick)
		{
		case 1: 
			do{ printf("Введите штрих-код\n");
				scanf("%d",&user_choose);
				q = 0;
				if ((user_choose > 10000) || (user_choose < 1))
				{
					printf("\nТовара с таким штрих-кодом нет");
					printf("\nВведите новый штрих код");
					q++;
				}
			} while(q != 0);
			break;
		case 2:
			
			if (user_choose == -1)
			{
				printf("\nВы не отсканировали товар\n");
				return;
			}
			name(names, user_choose, str);
			printf ("\nТовар  %s\nскидка на него %.2f\n", str, discounts[user_choose], prices[user_choose], discounts[user_choose] * prices[user_choose]);
			printf ("имеет цену без скидки %d\nсо скидкой %.2f", prices[user_choose], (1 - discounts[user_choose]) * prices[user_choose]);
			break;
		case 3:
			check[user_choose]++;
			printf("\nТовар успешно добавлен в чек\n");
			break;
		case 4:
			for (i = 1; i < 9999; i++)
			{
				if (check[i]!=0)
				{
					name(names, i, str);
					q++;
					printf("%d. %s -- %.0f -- %d -- %.0f\n", q, str, (1 - discounts[i]) * prices[i], check[i], check[i]*(1-discounts[i]) * prices[i]);
				}
			}
			q = 0;
			break;
		case 5:
			for (i = 1; i < 9999; i++)
			{
					s += prices[i] * check[i] * (1 - discounts[i]);
			}
			printf("Общая цена %.0f\n", s);
			break;
		}
	} while(pick != 6);
}
