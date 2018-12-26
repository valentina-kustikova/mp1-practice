
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 5
void choose(int *a, int n) //ÑÎĞÒÈĞÎÂÊÀ ÂÛÁÎĞÎÌ
{ 
	int i, min, j, minidx;
	for (i = 0; i < N; i++)
	{
		min = a[i];
		minidx = i;
		for (j = i + 1; j < N; j++)
		{
			min = a[j];
			minidx = j;
		}
		a[minidx] = a[i];
		a[i] = min;
	}
}

void insert(int *a, int n) //ÑÎĞÒÈĞÎÂÊÀ ÂÑÒÀÂÊÀÌÈ
{
	int i, tmp, j;
	for (i = 1; i < N; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > tmp))
		{
			a[j + 1] = a[j];
			a[j] = tmp;
		}
	}
}

void bubble(int *a, int n) //ÑÎĞÒÈĞÎÂÊÀ ÏÓÇÛĞÜÊÎÌ
{
	int i, j, tmp;
	for (i = 0; i < N; i++)
	{
		for (j = 1; j < N - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}
void main()
{
	int i,c,n;
	int *x;
	srand((unsigned int)time(0));
	setlocale(LC_ALL, "RUS");
	for (i = 0; i < N; i++)
	{
		x[i]=rand()% 50;
	}
	for (i = 0; i < N; i++)
	{
		printf("  %d ", x[i]);
	}
	printf("||");
	printf("1-Âûáîğîì 2- Âñòàâêàìè, 3-Ïóçûğüêîì");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		choose(x[N], n);
		for (i = 0; i < N; i++)
		{
			printf("  %d ", &x);
		}
	case 2:
	{
		insert(x[N], n);
		for (i = 0; i < N; i++)
		{
			printf("  %d ", &x);
		}
	}
	case 3:
		bubble(x[N], n);
		for (i = 0; i < N; i++)
		{
			printf("  %d ", &x);
		}
	}
}