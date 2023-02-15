#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int z[5];
	int a;
	int razr_a[5];
	int attemps = 0;
	int num_of_bulls = 0;
	int num_of_cows = 0;
	int k;
	int answer;
	printf("GAME:Bulls and cows\n");
	printf("Are you  ready?\n");
	system("pause");
	printf("Choose the length of the guessed number n (2-5) ");
	scanf("%d", &k);
	if ((k >= 6) || (k <= 1))
	{
		do {
			printf("Length can be only in the range of 2-5.Try again: ");
			scanf("%d", &k);
		} while ((k >= 6) || (k <= 1));
	}
	time_t t;
	srand((unsigned int)time(&t) << 16);
	z[0] = (rand() % 9) + 1;
	int i, j;
	for (i = 1; i < k; i++)
	{
		z[i] = rand() % 10;
	}
	int flag = 0;
	while (1)
	{
		flag = 0;
		for (i = 0; i < k; i++)
		{
			for (j = i + 1; j < k; j++)
			{
				if (z[i] == z[j])
				{
					z[i] = (i == 0) ? ((rand() % 9) + 1) : (rand() % 10);
					flag = 1;
				}
			}
		}
		if (flag == 0) { break; }
	}
	while (num_of_bulls != k)
	{
		int q=0;
		num_of_bulls = 0;
		num_of_cows = 0;
		printf("input the number: ");
		scanf("%d", &a);
		int tmp = a;
		while (tmp > 0) {
			tmp /= 10;
			q++;
		}
		if (k != q) {
			printf("You have specified a different number length (%d)\n", k);
			printf ("Do you want to try again ? (yes-1;no-2): ");
			scanf("%d", &answer);
			switch (answer) {
			case 1: {system("cls");  main(); }
			case 2: return 0;
			}
		}
		tmp = a;
		int b[5];
		for (i = 0; i < 5; i++) b[i] = 0;
		while (tmp) {
			b[tmp% 10] ++;
			tmp /= 10;
		}
		for (i = 0; i < 10; i++) {
			if (b[i] > 1) {
				printf("Digits in a number cannot be repeated\n");
				printf("Do you want to try again ? (yes-1;no-2) :");
				scanf("%d", &answer);
				switch (answer) {
				case 1: {system("cls");  main(); }
				case 2: return 0;
				};
			}
		}
		for (i = k - 1; i >= 0; i--)
		{
			razr_a[i] = a % 10;
			a /= 10;
		}
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < k; j++)
			{
				if (z[j] == razr_a[i])
				{
					if (i == j)
					{
						num_of_bulls++;
					}
					else
					{
						num_of_cows++;
					}
				}
			}
		}
		printf("%d bulls, %d cows.\n", num_of_bulls, num_of_cows);
		attemps++;
	}
	printf("Congradulations!\n");
	printf("it took you %d attemps\n", attemps);
	system("pause");
	return 0;
}
