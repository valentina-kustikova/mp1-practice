#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[5] = { 0 }, b[5] = { 0 }, i = 0, ii = 0, n = 0, k, l, f = 1, n1, n2, bull = 0, cow = 0;
	time_t t;
	srand((unsigned)time(&t));
	printf("Enter the length of the number (from 2 to 5 inclusive):\n ");
	do {
		scanf("%d", &n);
	} while ((n < 2) && (n > 5));
	for (i = 0; i < n; i++) 
	{
		do {
			k = (rand() % 9) + 1;
			if ((a[0] != k) && (a[1] != k) && (a[2] != k) && (a[3] != k) && (a[4] != k))
			{
				a[i] = k;
			}
		} while (a[i] == 0);
	}
	for (i = 0; i < n; i++) 
	{
		f *= 10;
	}
	do {
		printf("\nEnter your guess: ");

		do {
			scanf("%d", &l);
		} while ((l < f) && (l > 10 * f - 1));//proverka vvedennogo znachenia
		for (i = n - 1; i >= 0; i--) //chislo prevrashaem v massiv
		{
			b[i] = l % 10;
			l /= 10;
		}
		ii++;
		for (n1 = 0; n1 < n; n1++) //hodim po 2d massivy i sravnivaem s polz. vvodom
		{
			for (n2 = 0; n2 < n; n2++) 
			{
				if ((n1 == n2) && (a[n1] == b[n2])) 
				{
					bull++;
				}
				else if ((n1 != n2) && (a[n1] == b[n2])) 
				{
					cow++;
				}
			}
		}
		printf("bulls: %d", bull);
		printf(", cows: %d\n", cow);
		if (bull == n) 
		{
			printf("You guessed it! Number of attempts: %d", ii);
			break;
		}
		cow = 0;
		bull = 0;
	} while (1);
	return 0;
}