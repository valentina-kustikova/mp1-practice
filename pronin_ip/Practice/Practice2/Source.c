#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#define x10 

void main()
{
	int   c, g, cop, n, m, d, y, i, j, cow, bull;
	long a;
	int x[10];
	int z[10];
	cow = 0;
	bull = 0;
	y = 1;
	m = 0;
	d = 1;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	printf("введите колличество знаков числа");
	scanf("%d", &n);
	do { a = rand(); } while ((a < 1) || (a > 9));
	do {
		cop = a;
		do {
			c = rand();
		} while ((c < 0) || (c > 9) || (c == (a % 10)));
		do {
			a = a / 10;
			if ((a % 10) == c)
			{
				y = 1;
				break;
			}
			else y = 0;
			m += 1;
		} while ((a / 10) != 0);
		if (y != 1)
		{
			d += 1;
			a = cop * 10 + c;
			m = 0;
		}
		else
		{
			if (a <= 9)
			{
				do { g = rand(); } while ((g < 0) || (g > 9) || (g == a));
				a = a * 10 + g;
				d = 2;
			}
			else {
				d = (d - m - 1);
			}
		}
	} while (d < n);
	//рандомное n значное число сгенерировано
	//printf("a=""%d", a);
	for (j = 0; j < n; j++)
		{
			z[j] = a % 10;
			a = a / 10;
		}
	do
	{
		printf("введите n значное число");
		for (i = 0; i < n; i++)
			scanf("%d", &(x[i]));
		//массивы образованны
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((z[i] == x[j]) && (i == j))
					bull += 1;
				if (z[i] == x[j])
					cow += 1;
			}
		}
		printf("колличество коров=""%d", (cow - bull));
		printf("колличество быков=""%d", bull);
		if (bull != n)
		{
			cow = 0;
			bull = 0;
		}	
	} while (bull !=n);
		printf("число отгаданно!");
}
