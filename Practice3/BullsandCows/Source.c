#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int main()
{
	int a, n, Array[N], i, count = 0, j = 1, bulls = 0, cows = 0, value, Arr[N], Num[N] = { 0,1,2,3,4 }, Cr[N] = { 0,1,2,3,4, }, attemps = 0;
	srand(time(NULL));
	do
	{
		printf("Input length from 2 to 5\t");
		scanf_s("%d", &n);
	} while (n < 2 || n>5);
	switch (n)
	{
	case 2:
		do
		{
			a = rand() % (100 - 10 - 1) + 10;
			for (i = 0; i < n; i++)
			{
				Array[i] = a % 10;
				a /= 10;
			}
			for (i = 0; i < n; i++)
			{
				for (j = 1; j < n; j++)
				{
					if (Array[i] == Array[j]) break;
					else count++;
				}
			}
		} while (count != 1);
		count = 0;
		do {
			cows = 0;
			bulls = 0;
			do {
			A:			printf("Input value:\t");
				scanf_s("%d", &value);
			} while (value < 10 || value > 100);
			for (i = 0; i < n; i++)
			{
				Arr[i] = value % 10;
				value /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = 1; j < n; j++)
				{
					if (Arr[i] == Arr[j] && i != j)
					{
						printf("Wrong value\t"); goto A;
					}

				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i == j)
						bulls++;
			}
			printf("bulls - %d\t", bulls);
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i != j)
						cows++;
			}
			printf("cows - %d\t", cows);
			attemps++;
		} while (bulls != n);
		if (bulls == n) printf("Wow, you`re win! Attemps = %d\n", attemps);
		break;
	case 3:
		do
		{
			count = 0;
			a = rand() % (1000 - 100 - 1) + 100;
			for (i = 0; i < n; i++)
			{
				Array[i] = a % 10;
				a /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (Array[i] == Array[j]) count++;

				}
			}
		} while (count > 0);
		do
		{
			cows = 0;
			bulls = 0;
			do {
			B:		printf("Input value:\t");
				scanf_s("%d", &value);
			} while (value < 100 || value > 1000);
			for (i = 0; i < n; i++)
			{
				Arr[i] = value % 10;
				value /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = 1; j < n; j++)
				{
					if (Arr[i] == Arr[j] && i != j) {
						printf("Wrong value\t"); goto B;
					}

				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i == j)
						bulls++;
			}
			printf("bulls - %d\t", bulls);
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i != j)
						cows++;
			}
			printf("cows - %d\t", cows);
			attemps++;
		} while (bulls != n);
		if (bulls == n) printf("Wow, you`re win! Attemps = %d\n", attemps);
		break;
	case 4:
		do
		{
			count = 0;
			a = rand() % (10000 - 100 - 1) + 1000;
			for (i = 0; i < n; i++)
			{
				Array[i] = a % 10;
				a /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (Array[i] == Array[j]) count++;

				}
			}
		} while (count > 0);
		do
		{
			cows = 0;
			bulls = 0;
			do {

			C:		printf("Input value:\t");
				scanf_s("%d", &value);
			} while (value < 1000 || value > 10000);
			for (i = 0; i < n; i++)
			{
				Arr[i] = value % 10;
				value /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = 1; j < n; j++)
				{
					if (Arr[i] == Arr[j] && i != j) {
						printf("Wrong value\t"); goto C;
					}

				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i == j)
						bulls++;
			}
			printf("bulls - %d\t", bulls);
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i != j)
						cows++;
			}
			printf("cows - %d\t", cows);
			attemps++;
		} while (bulls != n);
		if (bulls == n) printf("Wow, you`re win! Attemps = %d\n", attemps);
		break;
	case 5:
		do
		{
			count = 0;
			a = rand() % (100000 - 100 - 1) + 10000;
			for (i = 0; i < n; i++)
			{
				Array[i] = a % 10;
				a /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (Array[i] == Array[j] && Array[i] < 10000) count++;

				}
			}
		} while (count > 0);
		do
		{
			cows = 0;
			bulls = 0;
			do {
			D:		printf("Input value:\t");
				scanf_s("%d", &value);
			} while (value < 10000 || value > 100000);
			for (i = 0; i < n; i++)
			{
				Arr[i] = value % 10;
				value /= 10;
			}
			for (i = 0; i < n - 1; i++)
			{
				for (j = 1; j < n; j++)
				{
					if (Arr[i] == Arr[j] && i != j) {
						printf("Wrong value\t"); goto D;
					}

				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i == j)
						bulls++;
			}
			printf("bulls - %d\t", bulls);
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (Array[i] == Arr[j] && i != j)
						cows++;
			}
			printf("cows - %d\t", cows);
			attemps++;
		} while (bulls != n);
		if (bulls == n) printf("Wow, you`re win! Attemps = %d\n", attemps);
		break;


	}

	return 0;
}