#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main ()
{
	int a,b,c,d;
	char f;
	c = 0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0)); 
	printf("введите выберете режим игры. \n 1 - игрок отгадывает \n 2 - игрок загадывает \n");
	scanf("%d", &a);
	if ((a!=1) && (a!=2))
	{
		printf("неверный ввод");
		return;
	}
	if (a==1)
	{
		b = rand() % 1001; 
		while (1)
		{
			printf("Введите число \n"); 
			scanf("%d", &d);
			c++;
			if (b == d)
			{
				break;
			}
			if (d > b)
			{
				printf("число больше загадоного \n");
			}
			if (d < b)
			{
				printf("Число меньше загадонного \n");
			}
		}
		printf("Вы отгадали число. \n Колличество попыток = %d", c);
		return;
	}
	if (a==2)
	{
		printf("Загадайте число");
		b = rand() % 1001;
		while (1)
		{
			int b2;
			c++;
			printf("Как ваше число относиться к числу %d \n введите <, >, =. \n", b);
			scanf("%c", &f);
			switch (f)
			{
				case '=':
					break;
				case '>': 
					while (b > b2)
					{
						b2 = rand() % 1001;	
					}
					b = b2;
				case '<': 
					while (b < b2)
					{
						b2 = rand() % 1001;	
					}
					b = b2;
				default: printf("неверный ввод");
			}
		}
		printf("Ваше число %d. \n Колличество попыток = %d",b, c);
		return;
	}
}