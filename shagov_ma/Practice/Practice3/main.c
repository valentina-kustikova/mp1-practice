#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main()
{
	int number,user_number,i,p;
	char zhak;
	long int a, b;//отрезок от а до b
	a = 0;
	b = 1000;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	printf("Укажите режим работы\n1 - отгадать самому;\n2 - загадать компьютеру;\n3 - выйти из программы\n");
	do{
		scanf("%d", &i);
		if (i == 1)
		{
			p = 0;
			number = rand()%1000;
			user_number = -1;
			while(user_number != number)
			{
				printf("\n");
				scanf("%d", &user_number);
				if (number > user_number)
				{
					printf("\nЗагаданное число больше");
				}
				if (number < user_number)
				{
					printf("\Загаданное число меньше");
				}
				if (number == user_number)
				{
					printf("\nУгадали за %d попыток \n", p);
				}
			}
			p++;
		}
		
		if (i == 2)
		{
			p = 0;
			do{
				number = a + rand()%(b - a + 1);
				printf("\n%d",number);
				printf("\n Оцените число\n> если число болшьше,\n< если число меньше,\n= если число равно загаданному\n");
				scanf("%*c%c", &zhak);
				if (zhak == '>')
				{
					a = number + 1;
				}
				if (zhak == '<')
				{
					b = number - 1;
				}
				if (zhak == '=')
				{
					printf("Число угадано за %d попыток", p);
				}
				p++;
			}while (zhak != '=');
		}
	}while (i != 3);
}