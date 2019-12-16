#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void main()

{
	int n, i, b = 0, w = 1, c = 9, q, m, p = 0, d = 0;
	int a[10], t[10];
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	do
	{
		printf("¬ведите количество знаков n в числе \n");
		scanf("%d", &n);
	} while (n < 1 || n>10);
	for (i = 0; i < n; i++)
	{
		a[i] = rand() * (c - b) / RAND_MAX + b;
		while (a[0] == 0)
		{
			if (a[0] = 0)
				a[0] = rand() * (c - w) / RAND_MAX + w;
		}
		for (q = 0; q < i; q++)
		{
			if (a[i] == a[q])
			{
				a[i] = rand() * (c - b) / RAND_MAX + b;
				i = 1;
				break;
			}
		}
	}
	while (1)
	{
		p = 0;
		d = 0;
		printf("¬ведите n-значное число с неповтор€ющимис€ цифрами \n");
		for (m = 0; m < n; m++)
		{
			scanf("%d", &(t[m]));
		}
		for (i = 0; i < n; i++)
		{
			for (m = 0; m < n; m++)
			{
				if ((t[m] == a[i]) && (m == i))
					p++;
				else if ((t[m] == a[i]) && (m != i))
					d++;
			}
		}
		printf("число коров %d \n", d);
		printf("число быков %d \n", p);
		if ((d == 0) && (p == n))
		{
			printf("число угадано \n");
			break;
		}
	}
}