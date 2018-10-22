#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void main () 
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int b[10];
	int n, n2, t, r, i, i2, B = 0, K = 0;
	long int N;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	printf ("Введите разрядность \n");
	scanf ("%d", &n);
	for (i = 0; i < 10; i++)
	{
		r = rand() % 10;
		t = a[r];
		a[r] = a[i];
		a[i] = t;
	}
	if (a[n-1] == 0)
	{
		r=0;
		do
		{
			r = rand() % 10;
		} while (r==n-1);
		t = a[n-1];
		a[r] = a[n-1];
		a[i] = t;
	}
	n2=1;
	for ( i = 0; i < n; i++)
	{
		n2 = n2*10;
	}
	while (1)
	{
		B=0;
		K=0;
		printf("Введите число \n");
		scanf("%d", &N);
		if (N > n2)
		{
			printf("Неверый ввод \n");
			continue;
		}
		for (i = 0; i < n - 1; i++)
		{
			b[i] = N % 10;
		}
		for ( i = 0; i < n-1; i++)
		{
			if (b[i] == a[i])
			{
				B++;
			}
			for ( i2 = 0; i2 < n-1; i2++)
			{
				if (b[i] == a[i2])
				{
					K++;
				}
			}
		}
		printf("Быков %d \nКоров %d \n", B, K - B);
		if (B == n)
		{
			printf("Вы победили");
			return;
		}
	}
}