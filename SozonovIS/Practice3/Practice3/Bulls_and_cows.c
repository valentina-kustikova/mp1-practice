#include <stdio.h>
#include <stdlib.h> 
#define S 5
void main()
{
	int i, j, n, x = 0, y, a[S], b[S], k, z, r, m, bulls, cows;
	do
	{
		printf("Enter the length of the guessed number n=");
		scanf_s("%d", &n);
	} while ((n < 2) || (n > 5));
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
	i = 0;
	while (i < n) {
		r = rand() % 10;
		for (j = 0; j < i; j++)
		{
			if (a[j] == r) 
				break;
		}
		if (j == i)
			a[i++] = r;
	}
	for (i = 0; i < n; i++)
	{
		k = a[i];
		for (j = n - 1; j > i; j--)
			k *= 10;
		x = x + k;
	}
	printf("x=%d\n", x);
	printf("I guessed the number. Try to guess it\n");
	scanf_s("%d", &y);
	while (x != y)
	{
		i = 1;
		bulls = 0;
		cows = 0;
		while (y > 0)
		{
			m = y % 10;
			for (j = 0; j < n; j++)
			{
				if (a[j] == m)
				{
					if (j == n - i)
						bulls++;
					else
						cows++;
				}
			}
			y /= 10;
			i++;
		}
		printf("%d bull(s), %d cow(s)\n", bulls, cows);
		scanf_s("%d", &y);
	}
	printf("Guessed");
}