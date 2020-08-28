#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main()
{
	int x = 1, y = 1000, n = 1, a, p = 1, type;
	int i = 0;
	char vvod = '=';
	setlocale(LC_ALL, "Russian");
	printf("Добро пожаловать в игру УГАДАЙ ЧИСЛО\n");
	printf("Выберите режим игры 1 или 2:\n");
	scanf("%d", &type);
	srand((unsigned int)time(0));
	if (type == 1)
	{
		a = x + rand() % y;
		printf("Компьютер загадал число от 1 до 1000, попробуйте его отгадать:\n");
		while (1)
		{
			i++;
			printf("Введите число, которое считается верным\n");
			scanf("%d", &a);
			if (a > n)
			{
				printf("Загаданное число меньше, продолжайте отгадывать дальше\n");
				p++;
			}
			else if (a < n)
			{
				printf("Загаданное число больше, продолжайте отгадывать дальше\n");
				p++;
			}
			else
			{
				printf("Поздравляю, вы угадали загаданное число! Кол-во попыток: %d\n", p);
				break;
			}
		}
		printf("Количество попыток: %d \n", i);
	}
	else if (type == 2)
	{
		n = rand() * (y - x) / RAND_MAX + x;
		printf("Компьютер пробует отгадать ваше число: %d\n", n);
		while (1)
		{
			scanf("%d", &vvod);
			if (vvod == '<')
			{
				y = n;
				n = rand() * (y - x) / RAND_MAX + x;
				printf("%d", n);
				p++;
			}
			else if (vvod == '>')
			{
				x = n;
				n = rand() * (y - x) / RAND_MAX + x;
				printf("%d \n", n);
				p++;
			}
			else if (vvod == '=')
			{
				printf("Компьютер угадал число!!! Кол-во попыток: %d\n", p);
				return;
			}
		}
	}
}