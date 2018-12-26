#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h> 


void main()
{
	int n, i, j, a[10], c, b, k, g[10], f, d, u;
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "Rus");
	printf("Введи длину числа.\n");
	for (;;)
	{
		scanf("%d", &n);
		if (n>0) break;
	}
	u = 0;
	for (;;)
	{
		a[0] = rand()%10;
		if (a[0] > 0)break;
	}
	for (i = 1; i < n; i++)
	{
		a[i] = rand() % 10;
		for (;;)
		{
			for (j = 0; j < i; j++)
			{
				if (a[j] == a[i])
				{
					a[i] = rand(0)%10;
					u++;
				}
			}
			if (u == 0)break;
			u = 0;
		}
	}
	printf("\nЗагадано число длиной %d. Цифры не повторяются. Отгадай это число.\n", n);
	do 
	{
		b = 0;
		k = 0;
		scanf("%d", &c);
		f = n-1;
		while (f != -1)
		{
			d = c % 10;
			g[f] = d;
			c /= 10;
			f=f-1;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((g[i] == a[j]) && (i == j))
				{
					b++;
				}
				if ((g[i] == a[j]) && (i != j))
				{
					k++;
				}
			}
		}
		if (b != n)
		{
			printf("\nКоровы = %d, быки = %d. Попробуйте еще раз.\n", k, b);
		}
	} while (b != n);
	printf("\nВы отгадали!\n");
	

}