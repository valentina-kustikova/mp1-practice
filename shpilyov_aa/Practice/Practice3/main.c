#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int n, chislo, a = 0, i = 1, x = 1, y = 1000;
	char z = '=';
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("Выберите режим 1 или 2: ");
	scanf("%d", &n);
	if (n == 1)
	{
		chislo = x + rand() % y;
		printf("Компьютер загадал число от 1 до 1000, попробуйте отгадать: ");
		while (1)
		{
			scanf("%d", &a);
			if (a > chislo)
			{
				printf("Загаданное число меньше\n");
				i++;
			}
			else if (a < chislo)
			{
				printf("Загаданное число больше\n");
				i++;
			}
			else
			{
				printf("Вы угадали! Кол-во попыток: %d", i);
				break;
			}
			
		}
	}
	else if (n == 2)
	{
		chislo = rand() * (y - x) / RAND_MAX + x;
		printf("Компьютер пробует угадать: %d\n", chislo);
		while (1)
		{
			scanf("%c", &z);
			if (z == '<')
			{
				y = chislo;
				chislo = rand() * (y - x) / RAND_MAX + x;
				printf("%d \n", chislo);
				i++;
			}
			else if (z == '>')
			{
				x = chislo;
				chislo = rand() * (y - x) / RAND_MAX + x;
				printf("%d \n", chislo);
				i++;
			}
			else if (z == '=')
			{
				printf("Компьютер угадал. Кол-во попыток: %d\n", i);
				break;
			}
		}
	}
	else
	{
		printf("Неверный режим!");
		return;
	}
}