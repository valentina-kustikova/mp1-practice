#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int a;
	setlocale (LC_ALL, "RUS");
	srand((unsigned int)time(0));
	printf ("Выберите режим (введите 1, если загадывает компьтер; введите 2, если загадываете вы ");
	do
	{
		scanf ("%d ", &a);
	} while ((a != 1) && (a != 2));
	if (a == 1)
	{
		int x = 1002;
		int k = 0;
		int n;
		n = rand() % 1001;
		if (n==0)
			n = rand() % 1001;
		printf("Введите число ");
		while (n != x)
		{
			scanf("%d", &x);
			if (n > x)
			{
				printf("Загаданное число больше ");
			}
			if (n < x)
			{
				printf("загаданное число меньше ");
			}
			k++;
		}
		++k;
		printf("Угадали ");
		printf(" Количество попыток - %d ", k);
	}
	if (a==2)
	{
		int n,b;
		char x;
		int k = 0;
		printf ("Введите загаданное число ");
		scanf("%d", &n);
		printf("Начинаем отгадывать: ");
		b = rand() % 1001;
		if (b==0)
			b = rand() % 1001;
		printf("%d", b);
		scanf ("%*c%c", &x);
		while (x != '=')
		{
			if (x == '>')
			{
				b = rand() * (1000 - 1) / RAND_MAX + 1;
			}
			if (x == '<')
			{
				b = rand() * (1000-1) / RAND_MAX + 1; 
			}
			k++;
			printf("%d", b);
			scanf("%*c%c", &x);
		}
		++k;
		printf("Угадали ");
		printf(" Количество попыток - %d ", k);
	}
}