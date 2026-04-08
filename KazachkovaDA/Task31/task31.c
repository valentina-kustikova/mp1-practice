#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 5

int main()
{
	int arr[N], player[N], n, numb, i, l, guess, j, bull, cow, digit, flag, temp;
	setlocale(LC_ALL, "Rus");
	l = 1;

	do
	{
		printf_s("Введите количество цифр:\n");
		scanf_s("%d", &n);
	} while (n < 2 || n >5);

	for (i = 0; i < n; i++) {
		l *= 10;
	}

	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		flag = 0;
		do
		{
			digit = rand() % 10;
		} while (digit == 0);


		for (j = 0; j < n; j++)
		{
			if (arr[j] == digit)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			arr[i] = digit;
		}
		else
		{
			i--;
		}
	}
	/*
	* for (i = 0; i < n; i++)
	{
		printf_s("%d", arr[i]);
	}
	*/

	do
	{
		cow = 0;
		bull = 0;

		do
		{
			flag = 1;
			printf_s("\nВведите вашу догадку:");
			scanf_s("%d", &guess);
			temp = guess;

			for (i = 0; i < n; i++)
			{
				player[n - i - 1] = guess % 10;
				guess /= 10;
			}

			for (i = 0; i < n; i++) {
				for (j = i + 1; j < n; j++) {
					if ((player[i] == player[j]) || (player[j] == 0))
					{
						flag = 0;
					}
				}
			}

		} while ((temp >= l) || (temp < (l / 10)) || (flag == 0));


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
	if (bull == n) {
		printf_s("Вы угадали!");
	}
	return 0;
}