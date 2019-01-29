#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int v, c, a, i, q, w;
	char p;
	i = 0;
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(0));
	printf("Выберите режим - 1 или 2\n");
	for (;;)
	{
		scanf("%d", &v);
		if ((v == 1) || (v == 2)) break;
	}
	if (v == 1)
	{
		for (;;)
		{
			a = rand() % 1001;
			if (a != 0)break;
		}
		printf("Угадайте число.\n");
		for (;;)
		{
			scanf("%d", &c);
			if (c > a)
			{
				printf("Загаданное число меньше.\n");
			}
			if (c < a)
			{
				printf("Загаданное число больше.\n");
			}
			i++;
			if (a == c) break;
		}
		printf("Угадали, число попыток = %d.\n", i);
	}
	else
	{
		printf("Загадайте число от 1 до 1000.\n");
		scanf("%d", &a);
		q = 1;
		w = 1000;
		p = '>';
		while(p != '=')
		{
			for (;;)
			{
				c = rand() % 1001;
				if ((c>= q)&&(c<=w)) break;
			}
			printf("%d\n", c);
			printf("Введите >, < или =\n");
			scanf("%c", &p);
			if (p == '>')
			{
				q = c;
			}
			if (p == '<')
			{
				w = c;
			}
		}
	}
}