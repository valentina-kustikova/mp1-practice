#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char a;
	printf("Select game 1 or 2:\n ");
	do {
		scanf("%c", &a);
	} while ((a != '1') && (a != '2'));

	if (a == '1')
	{
		int a, n, i = 0;
		srand((unsigned int)time(NULL));
		n = rand() % 1000;
		printf("Enter a number from 0 to 1000...\n");

		while (1) {
			do {
				scanf("%d", &a);
			} while (a > 1000 || a < 0);

			if (a < n)
			{
				printf("Bigger\n");
				i++;
			}
			else if (a > n) 
			{
				printf("Smaller\n");
				i++;
			}
			else 
			{
				printf("WOW, you guessed it!\n Number of attempts: %d", i + 1);
				break;
			}
		}
		return 0;
	}
	else 
	{
		int a1 = 1, a2 = 1000, d = 0, c = d, i1 = 0;
		char b = ' ';
		printf("Guess a number from 1 to 1000\n");
		while (b != '=')
		{
			i1++;
			c = (a1 + a2) / 2;
			if (c == d)
			{
				c = c - 1;
			}
			printf("%d", c);
			printf("?\n");
			do {
				scanf("%c", &b);
			} while ((b != '<') && (b != '>') && (b != '='));
			if (b == '<')
			{
				a2 = c;
			}
			else if (b == '>')
			{
				a1 = c;
			}
			else
			{
				printf("WOW, I guessed it!\n Number of attempts: %d", i1);
			}
			d = c;
		}
	}
	return 0;
}