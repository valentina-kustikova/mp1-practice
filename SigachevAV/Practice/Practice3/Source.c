#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main ()
{
	int a,b,c,d, b2;
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
		b = (rand() % 1000)+1; 
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
		printf("Загадайте число \n");
		b = 500;
		f = '.';
		do
		{
			printf("Как ваше число относиться к числу %d \n Введите знак отношения (>, <, =) \n", b);
			scanf("%*c%c", &f);
			switch (f)
			{
			case '>':
				{
					b--;
					c++;
					break;
				}
			case '<':
				{
					b++;
					c++;
					break;
				}
			default:
				{
					printf("Неверный ввод \n");
					break;
				}
			}
		}while(f != '=');
		printf("Ваше число %d \n Колличество ходов %d \n", b, c++);
		return;
	}
}