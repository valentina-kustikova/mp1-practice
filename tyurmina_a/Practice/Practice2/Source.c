#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int i, j, s = 1;
	int b, k, c, c1, c2, n;
	int a[10];
	int y[10];
	setlocale(LC_ALL, "RUS");
	srand((unsigned int)time(0));
	printf("Введите длину числа");
	scanf("%d", &n);
	for (;;)
	{
		a[0] = rand() % 10;
		if (a[0] > 0)break;
	}
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &(a[i]));
	}
	a[0] = y[0];
	for(i = 1; i < n; i++)
	{
		int f = 0;
		for (j = 0; j < i; j++)
			{
				if (a[j] == a[i])
				{
					f = 1;
				}
				if (f == 0)
				{
					y[s] = a[i];
					s++;
			    }
		     }
	}
	for ( ; ; )
	{
		k = 0;
		b = 0;
		printf("Введите ваше предположение ");
		scanf("%d", &c);
		c2 = c;
		for (i = n - 1; i >= 0; i++)
		{
			c1 = c % 10;
			y[i] = c1;
			c = c / 10;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((y[i] == a[j]) && (i == j))
				{
					b++;
				}
				if ((y[i] == a[j]) && (i != j))
				{
					k++;
				}
			}
		}
		if (b != n)
		{
			printf("Коровы = %d, Быки = %d", k, b);
		}
		if (b == n)
			break;
	}
	printf("%d", c2);
}