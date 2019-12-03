#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, k, l, i = 0;
	int h = 1, a = 1;
	int r, b = 1000;
	char q;
	do
	{
		printf("Выберите 1 или 2 режим \n");
		scanf("%d", &n);
	} while (n < 1 || n > 2);
	srand((unsigned int)time(0));
	if (n == 1)
	{
		printf("попробуйте отгадать k, загадав число от 1 до 1000 \n");
		k = a + rand() % b;
		while (1)
		{
			i++;
			scanf("%d", &l);
			if (l < k)
				printf("k больше \n");
			else if (l > k)
				printf("k меньше \n");
			else
			{
				printf("число угадано \n");
				break;
			}
		}
		printf("колличество попыток %d \n", i);
	}
	if (n == 2)
	{
		do
		{
			printf("загадайте произвольное число от 1 до 1000 и введите его \n");
			scanf("%d", &r);
		} while (r < 1 || r > 1000);
		k = rand() * (b - a) / RAND_MAX + a;
		printf("число, выбранное компьютером %d \n", k);
		while (1)
		{
			scanf("%c", &q);
			if (q == '<')
			{
				b = k;
				k = rand() * (b - a) / RAND_MAX + a;
				printf("число, выбранное компьютером %d \n", k);
				h++;
			}
			else if (q == '>')
			{
				a = k;
				k = rand() * (b - a) / RAND_MAX + a;
				printf("число, выбранное компьютером  %d \n", k);
				h++;
			}
			else if (q == '=')
			{
				printf("число угадано \n");
				break;
			}
		}
		printf("колличество попыток %d \n", h);
	}
}



