#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
	int r,b,k,d,a;
	/*r-режим игры
	b-загаданное число
	d-предполагаемое число
	k-количество попыток
	*/
	a=1;
	k=1;
	srand((unsigned int)time(0)); 
	printf("Выберите режим игры. \nВведите 1, если вы угадываете число. \nВведите 2, если компьютер угадывает число:\n");
	scanf("%d",&r);

	if (r==1)
	{printf("Введите  предполагаемое число от 1 до 1000 \n"); 
		b = rand() % 1000; 
		while (a)
		{printf("%d-ая попытка\n", k);
			scanf("%d", &d);
			k++;
			if (b == d)
			{
				break;
			}
			if (d > b)
			{
				printf("Загаданное число меньше\n");
			}
			if (d < b)
			{
				printf("Загаданное число больше\n");
			}
		}
		printf("Угадали!!!\n");
		printf("Всего попыток %d: ", k-1);


		return;
	}

	if (r==2)
	{
		char c;
		printf("Введите загаданное число от 1 до 1000:\n");
		scanf("%d",&d);//загадываемое число
		b = rand() % 1000;
		while (b!=d)
		{
			printf("Если предполагаемое число %d \nбольше(>), введите '>' \nменьше(<), введите '<2'\nравно(=), введите '=':\n", b);
			scanf("%*с %c",&c);
			printf("%d-ая попытка\n", k);
			k++;		
			if (c=='>')
				b--;
			if (c=='<')
				b++;
			if (c=='=')
			{
				printf("Компьютер угадал ваше число %d\n",d);
				printf("Всего попыток: %d",k-1);
				return;
			}
		}
		
	}
	else 
	{
		printf("Такого режима не существует");
        } 
}
