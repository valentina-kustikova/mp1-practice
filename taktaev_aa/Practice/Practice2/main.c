 #include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <locale.h> 
#define N 10 
void main ()
{ 
	int chisloC[N]; 
	int baserng[N]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int chislo4[N]; 
	int i, j, cifri=0, korovi = 0, biki = 0, x, y, proverka = 0, pr = 0, f=0; 
	setlocale(LC_ALL, "Russian"); 
	srand((unsigned int)time(0)); 
	printf("Игра 'Быки и Коровы'. Правила:\n 1. Вы выбираете количество знаков числа, которое будет участвовать в игре.\n 2.Компьютер загадывает это число без повторяющихся цифр.\n 3.Затем Вы пытаетесь угадать его, на что получаете количество коров(количество угаданных цифр, но на неверных позициях) и количество быков(угаданных цифр на верной позиции).\n");
	do
	{
		printf("	Введите количество цифр в числе:\n");
		scanf("%d", &cifri);
	} while((cifri < 1) || (cifri > 10)); 
	printf("	Загадываю %d-значное число...\n", cifri); 
	i = 0;
	while (i < cifri) 
	{ 
		if (i == 0) x = 1 + rand() % 9; //первая цифра ! = 0
		else x = rand() % 10; 
		if (baserng[x] != -1) //записываю в базовый массив из цифр -1, когда эта цифра использовалась в рандомном числе
		{ 
			chisloC[i] = x; 
			baserng[x] = -1;
			i++; 
		} 
	} 
	//for (i = 0 ; i < cifri; i++) printf("%d", chisloC[i]); //проверка
	do 
	{  
		printf("Введите %d-значное число без повторяющихся цифр:\n", cifri); 
		scanf("%d", &y); 
		proverka = 0; 
		korovi = 0;
		biki = 0;
		pr = y; //чтобы не портить переменную у
		while (pr > 0)
		{
			pr = pr / 10;
			proverka++;
		}
		if (proverka != cifri)
		{
			printf("В введенном числе должно быть %d знаков(а)!\n", cifri);
			continue;
		}
		pr = y;
		for (i = cifri-1; i >=0; i--) //обратный порядок занесения в массив для удобства (операции % и /)
		{ 
			chislo4[i] = pr % 10; 
			pr = pr / 10;
		}
		f = 0;
		for (i = 0; i < cifri; i++) 
		{
			for (j = (i+1); j < cifri; j++)
			if (chislo4[i] == chislo4[j]) 
			{
				printf("Число должно быть без повторов!\n");
				f = 1;
			}
		}
		if (f == 1) continue;//чтобы пользователь мог исправить неправильно введенное число
		for (i = 0; i < cifri; i++) 
		{ 
			for (j = 0; j < cifri; j++) 
			{ 
				if ((chisloC[i] == chislo4[j]) && (i == j)) biki++; 
				if ((chisloC[i] == chislo4[j]) && (i != j)) korovi++;
			} 
		} 
		printf("Количество коров - %d;\nKоличество быков - %d.\n", korovi, biki); 
	} while (biki != cifri); 
	printf("Поздравляю! Вы выиграли!\n"); 
}