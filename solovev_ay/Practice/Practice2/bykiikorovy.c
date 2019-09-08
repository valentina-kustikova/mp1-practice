#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 10
void main()
{
	int randommas[N];
	int osnova[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };//ввел массив как базу для создания рандомных чисел
	int otvet[N];
	int i = 0, kolvoznakov = 0, kolvokorov = 0, kolvobykov = 0, x = 100, y, z, score = 0;
	setlocale(LC_ALL, "Russian");
	srand((unsigned int)time(0));
	printf("Введите количество знаков от 1 до 10\n");
	while ((kolvoznakov < 1) || (kolvoznakov > 10))
		scanf("%d", &kolvoznakov);//проверка на ввод количества знаков
	printf("Компьютер загадал %d значное число!", kolvoznakov);
	//генерирую случайный массив randommas
	i = kolvoznakov;
	while (i > 0)
	{
		x = 10.0 / RAND_MAX * rand();
		if (i == kolvoznakov)
			x = 9.0 / RAND_MAX * rand() + 1;
		//со второго знака генерирую от 0 до 9
		if (osnova[x] != -1) //выполняется при начале работы с еще не задействованным эл-том osnova
		{
			randommas[i] = osnova[x];
			osnova[x] = -1;//принимаю рандомные значения в массив//исключаю повторы
			i--;
		}
	}
	do
	{
		x = 0;
		printf("Введи число без повторяющихся цифр = ");
		kolvobykov = 0;
		kolvokorov = 0;//обнулил счетчики количества животных 
		scanf("%d", &y);
		score++;//записываю число попыток
		for (i = kolvoznakov; i > 0; i--)
		{
			otvet[i] = y % 10;
			y = y / 10;
		}//конвертирую вводимое пользователем число в массив вида 
		for (i = kolvoznakov; i > 0; i--)
		{
			for (y = (i - 1); y > 0; y--)
			{
				if (otvet[i] == otvet[y]) x++;
			}
		} while (x != 0);
		for (i = kolvoznakov; i > 0; i--)
		{
			for (y = kolvoznakov; y > 0; y--)
			{
				if ((randommas[i] == otvet[y]) && (i == y))
					kolvobykov++; //высчитываю быков
				if ((randommas[i] == otvet[y]) && (i != y))
					kolvokorov++; //высчитываю коров
			}
		}
		printf("Коров = %d и Быков = %d \n", kolvokorov, kolvobykov);
	} while (kolvobykov != kolvoznakov);
	printf("Ты выиграл! Число попыток - %d!", score);
}

