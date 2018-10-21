﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	int a, b, f = 0, i = 0, digit, player;                                                          // i - число попыток
	char z;
	srand((unsigned int)time(0));

	printf("\n               \"Guess the number\"\n");
	printf("\nThis game have a two modes.\n1. You VS PC.\n2. PC VS You.");

	do {                                                                                            // Проверка на ввод выбора
		printf("\nIf you want to play in first mode, enter \"1\". If you want to play in secoud mode, enter \"2\".\nYour choise is ");
		scanf("%d", &a);
	} while ((a != 1) && (a != 2));

	if (a == 1)
	{
		digit = rand() * 1000 / RAND_MAX + 1;
		printf("Well, PC came up with the number.\n");
		do
		{
			do                                                                                      // Проверка на ввод числа пользователем 
			{                        
				printf("Enter the number: ");
				scanf("%d", &player);
			} while ((player < 0) || (player > 1000));

			i++;                                                                                   

			if (player > digit)
			{
				printf("Less.\n");
				continue;
			}
			if (player < digit)
			{
				printf("More.\n");
				continue;
			}
		} while (player != digit);
		printf("Congratulations! You win! Number of attempts - %d.\n", i);
		return;
	}

	printf("Come up with the number, please. Don't say it anyone! :)\n");

	a = 0;
	b = 1001;

	do
	{
		digit = rand() * (b - a) / RAND_MAX + a;                                                     // Рандомное число в диапазоне [a,b)
		
		printf("Okey, PC thinks that it is %d\n", digit);
		printf("Enter \">\", \"<\" or \"=\": ");
		scanf("%c", &z);
		z = getchar();                                                                               // Функция, чтобы удалить перевод строки в переменной z (Нашла единственное решение этой проблемы)
		
		switch (z)
		{
		case '>':
			a = digit + 1;
			break;
		case '<':
			b = digit;
			break;
		case '=':
			f = 1;
			break;
		default:
			printf("Error. Invalid character. Try again.\n");
			break;
		}

	} while (f == 0);

	printf("Congratulations! PC guessed the your number!\n");
}