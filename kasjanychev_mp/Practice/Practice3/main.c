#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define N 1000
void main()
{
	int x, rezhim, sch = 0;
	setlocale(LC_ALL, "Russian");
	printf("Выберете режим (1 or 2)\n");
	scanf("%d", &rezhim);
	if (rezhim == 1)
	{
		int y;
		y = -1;
		srand((unsigned int)time(0));
		x = 0 + rand() % N;
		while (x != y)
		{
			printf("Введите отгадку\n");
			scanf("%d", &y);
			if (x < y) printf("Загаданное число <\n");
			if (x > y) printf("Загаданное число >\n");
			sch++;
		}
		printf("Вы угадали! Число %d, кол-во попыток=%d\n", x, sch);
	}
	else
	{
        int a[N], i, k, y, m, n2, n1;
        char z;
        m = 1;
        y = -1;
        n2 = N;
        n1 = 0;
        k = 0;
        printf("Введите число\n");
	    scanf("%d", &x);
	    while (m != 0)
	    {
		    srand((unsigned int)time(0));
		    y = n1 + rand()%(n2-n1+1);
		    printf("%d\n", y);
		    printf("Введите знак (<, > или =)\n");
		    scanf("%*c%c", &z);
		    k++;
		    if (z == '=') m = 0;
		    if (z == '<') n2 = y;
		    if (z == '>') n1 = y;
        }
        printf("Программа угадала ваше число! Число=%d, кол-во попыток=%d", y, k);
    }
}
