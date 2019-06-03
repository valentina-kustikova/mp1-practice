#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

void main()
{
	int a[10], b[10];
	int n, cows = 0, bulls = 0, p, i, j;
	int temp = 1;
	do
	{
		printf("Enter n: ");
		scanf("%d", &n);
		if ((n <= 0) || (n >= 10))
			printf("Number does not exist \n");
	} while ((n <= 0) || (n >= 10));
	srand((unsigned int)time(0));
	while (temp)
	{
		temp = 0;
		for (i = 0; i < n; i++)
			a[i] = rand() % 9;
		if (a[0] == 0)
			a[0] = rand() % 9 + 1;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (a[i] == a[j])
				{
					temp = 1;
					break;
				}
	}
	while (bulls != n)
	{
		cows = 0;
		bulls = 0;
		printf("Enter your number: ");
		scanf("%d", &p);
		if (p <= 0)
		{
			printf("Error. Your number is not correct");
			break;
		}
		for (i = n; i > 0; i--)
		{
			b[i - 1] = p % 10;
			p /= 10;
		}
		for (i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (b[i] == a[j])
					cows++;
		for (i = 0; i < n; i++)
			if (a[i] == b[i])
				bulls++;
		if (cows >= bulls) //Без этого условия при выигрыше получаем
			cows -= bulls; //и число быков, и число коров
		printf("Cows: %d\n", cows);
		printf("Bulls: %d\n", bulls);
	}
	printf("You win!!!");
}

