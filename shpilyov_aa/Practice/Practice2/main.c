#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

void main()
{
	int n, x, i, j, cow = 0, bull = 0;
	int a[10], b[10];
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("Введите длину загадываемого числа: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		a[i] = 0 + rand() % 9;
	if (a[0] == 0)
		a[0] = 1 + rand() % 9;
	printf("Компьютер загадал число, попробуйте отгадать: ");
	while (1)
	{
		scanf("%d", &x);
		for (j = 0; j < n; j++)
		{
			b[n - 1 - j] = x % 10;
			x = x % 10;
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (a[i] == b[j])
					if (i == j)
						bull++;
					else cow++;
		if (bull == n)
		{
			printf("Вы угадали! %d", x);
			break; 
		}		
		printf("Коров: %d\nБыков: %d\n", cow, bull);
		cow = bull = 0;
	}
}