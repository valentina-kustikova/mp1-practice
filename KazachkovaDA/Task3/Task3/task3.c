#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 5

int main()
{
	setlocale(LC_ALL, "Rus");
	int arr[N], player[N], n, numb, i, l, guess, j, bull, cow;
	l = 1;

	do 
	{
		printf_s("Введите длину слова:\n");
		scanf_s("%d", &n);
	} while (n < 2 || n >5);
	
	for (i = 0; i < n; i++) {
		l *= 10;
	}

		srand(time(NULL));
		numb = rand() % (l - l / 10) + l / 10;

		for (i = 0; i < n; i++) {
			arr[n-i-1] = numb % 10;
			numb /= 10;
		}
	
	do
	{
		cow = 0;
		bull = 0;
		do
		{
			printf_s("\nВведите вашу догадку:");
			scanf_s("%d", &guess);
		} while ((guess >= l) || (guess < (l / 10)));

		for (i = 0; i < n; i++) 
		{
			player[n-i-1] = guess % 10;
			guess /= 10;
		}

		for (i = 0; i < n; i++)
		{
			if (arr[i] == player[i])
			{
				bull++;
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (arr[i] == player[j])
				{
					cow++;
				}
			}
		}
		cow = cow - bull;
		printf_s("Быков: %d, коров: %d\n", bull, cow);
	} while (bull != n);
	if (bull = 2) {
		printf_s("Вы угадали!");
	}
	return 0;
}