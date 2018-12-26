#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pch.h"
void main()
{
	int a, b, i, c;
	scanf("%d %d" &b, &c);
	srand(time(NULL));
	printf("Угадай число\n");
	printf("Компьютер загадал число от 1 до 1000\n");
	a = rand() % 1000 + 1;
	for (i == 1; i <= 1001; i++)
	{
		printf("Введите число\n");
		if (a < b)
			printf("Загаданное число больше");
		else
			if (a > b)
				printf("Загаданное число меньше");

			else
				if (a == b)
				{
					printf("угадали");

					break;
				}
		c = c + 1;
	}
	printf("Кол-во шагов");
	printf(c);
	return;


	}
	

}