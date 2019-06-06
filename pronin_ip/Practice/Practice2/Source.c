#include <stdio.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

#define B 10

void main()
{
	int q, a, b, c, cop, d, n, x = 0, y = 9, z = 1, i, j, bull, cow, number;
	int f[B];
	int g[B];
	int l[B];
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	cow = 0;
	bull = 0;
	c = 0;
	d = 1;
	printf("введите длину загадываемого числа");
	scanf("%d", &n);
	a = rand() * (y - z) / RAND_MAX + z;
	do
	{
		b=rand() * (y - x) / RAND_MAX + x;
		//printf("c=""%d", b);
		cop = a;
		do
		{
			if (a % 10 == b)
			{
				a = 0;
				c = 1;
			}
			else a = a / 10;
			
		} while (a != 0);
		if (c != 1)
		{
			a = cop * 10 + b;
			d += 1;
			//printf("cумма=""%d", a);
			
		}
		else
		{
			a = cop;
			c = 0;
		}
		//printf("cop=""%d", a);
	} while (d < n);
	printf("a=""%d", a);
	//число сгенерировано
	for (i = n - 1; i >= 0; i--)
	{
		f[i] = a % 10;
		a = a / 10;
	}
	//число записано в массив
	do
	{
		printf("отгадай число");
		scanf("%d", &number);
		q = number / pow(10, n - 1);
		if (q == 0 || q > 9)
		{
			printf("введеное число не соответствует введеной длине");
			return;
		}
		for (i = 0; i < n; i++)
		{
			l[i] = number % 10;
			number = number / 10;
		}
		for (i = 0; i < n; i++)
			g[i] = l[n - i -1];
		//начинается сравнение
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((f[i] == g[j]) && (i == j))
					bull += 1;
				if (f[i] == g[j])
					cow += 1;
			}
		}
		printf("коров=""%d", (cow - bull));
		printf("быков=""%d", bull);
		if (bull != n)
		{
			cow = 0;
			bull = 0;
		}
	} while (bull != n);
	printf("число отгадано!!!");
}
