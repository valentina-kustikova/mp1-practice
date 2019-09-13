#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(int* dig, int* num, int n, int att)
{
	int inp, flag = 0, i = 0, k;

	printf("enter your number \n");
	scanf("%d", &inp);

	k = inp;

	do
	{
		dig[n - 1 - i] = k % 10;
		k = k / 10;
		i++;
	} while (k != 0);

	if (i != n)
	{
		printf("wrong length, try again \n");
		return 1;
	}

	for (i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if ((dig[i] == dig[j]))
			{
				printf("use a number with different digits \n");
				return 2;
			}

	int b = 0, c = 0;
	for (i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((num[i] == dig[j]))
				if (i == j)
					b++;
				else
					c++;
	if (b == n)
	{
		printf("You win! Number %d in %d attempts \n", inp, att);
		return 0;
	}
	else
	{
		printf("%d bulls, %d cows \n", b, c);
		return 3;
	}
}

void main()
{
	int dig[10], num[10];
	int n = 0, k = 0, i, result;
	time_t t;

	srand((unsigned)time(&t));

	while ((n < 1) || (n > 9))
	{
		printf("enter length of a number \n");
		scanf("%d", &n);
	}

	//creating a number with different digits
	for (i = 0; i <= 9; i++)
		dig[i] = i; //array of unused digits

	num[0] = 1 + rand() % 9;
	dig[num[0]] = -1;

	for (i = 1; i < n; i++)
	{
		do
			k = rand() % 10;
		while (dig[k] < 0);

		num[i] = dig[k];
		dig[k] = -1;
	}

	int att = 1;

	do
	{
		result = game(dig, num, n, att);
		att++;
	} while (result != 0);

	system("pause");
}