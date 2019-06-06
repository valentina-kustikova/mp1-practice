#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int a, b, c, x, y, z, q, w;
	c = 0;
	z = 0;
	x = 0;
	y = 1000;
	setlocale(LC_ALL, "Russian");
	char sign = '!';
	srand((unsigned int)time(0));
	printf("нажмите 1, если хотите отгадать чило; нажмите 2, если хотите загадать число");
	scanf("%d", &w);
	if (w == 1)
	{
		do { a = rand(); } while ((a < 0) || (a > 1000));

		printf("отгадайте число");
		do {
			scanf("%d", &b);
			if (b > a) printf("загаданное число меньше");
			if (b < a) printf("загаданное число больше");
			c += 1;
		} while (b != a);
		printf("число попыток:""%d", c);
	}
	if (w == 2)
	{
		printf("загадайте число");
		scanf("%d", &a);
		do {
			do { b = rand(); } while ((b < x) || (b > y));
			printf("%d", b);
			printf("введите <, если ваше число меньше; введите >, если ваше число больше");
			//scanf("%d", &q);
			scanf("%*c%c", &sign);
			if (sign == '<') 
			y = b; 
			else 
			{
			if (sign == '>') 
			x = b; 
			else  
			return;
			}
			z += 1;
		} while (b != a);
		printf("число попыток:""%d", z);
	}
}