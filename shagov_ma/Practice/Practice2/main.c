#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

void main(){
	int zag[10] = {0};
	int arr_number_user[10] = {0};
	int number_user, count, a, q, n, b, k, i, bull;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int) time(0));
	b = 1;
	q = 0;
	printf("Введите длину числа\n");
	scanf("%d",&n);
	while((b != 0) || (q == 1))//проверка загаданного числа
	{
		b = 0;
		q = 0;
		for (i = 0; i < n; i++)
		{
			zag[i] = rand() % 10;
		}
		if (zag[0] == 0)
		{
			q++;
		}
		for (i = 0; i < n;i++)
		{
			for(k = 0; k < i;k++)
			{
				if ((zag[k] == zag[i]))
				{
					b++;
					break;
				}
			}
		}
	}
	bull = 0;
	while (bull != n)
	{
		b = 1;
		count = 0;
		while ((b != 0) || (count != n))//проверка числа пользователя
		{
			printf("\nВведите число \n");
			scanf("%d", &number_user);
			a = number_user;
			count = 0;
			while(a != 0)
			{
				a= a/10;
				count++;
			}
			if (count != n)printf("Неверная длина числа");
			a = number_user;
			for (i = 0;i < n;i++)
			{
				arr_number_user[i] = a % 10;
				a = a / 10;
			}
			b = 0;
			for (i = 0; i < n; i++)
			{
				for(k = 0; k < i; k++)
				{
					if (arr_number_user[k] == arr_number_user[i])
					{
						b++;
						break;
					}
				}
			}
			if (b != 0)printf("Цифры в числе повторяются");
		}
		bull = 0;
		printf("\nОтгаданные быки:");
		for (i = 0; i < n; i++)
		{
			if (zag[i] == arr_number_user[i])
			{
				printf(" %d", zag[i]);
				bull++;
			}
		}
		printf("\nОтгаданные коровы:");
		for (i = 0;i < n;i++)
		{
			for(k = 0;k < n;k++)
			{
				if ((zag[i] == arr_number_user[k]) && (k != i))
				{
					printf(" %d", arr_number_user[k]);
				}
			}
		}
		
	}
	printf("\n Поздравляю! Вы отгадали все цифры.");
}
