#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char a;
	printf("Vuberite igru 1, 2: ");
	do {
		scanf("%c", &a);
	} while ((a != '1') && (a != '2'));
	if (a == '1')
	{
		int n, i = 0, a;
		srand((unsigned int)time(NULL));
		n = rand() % 1000;
		printf("vedite vashe predpologenie: ");
		do {
			i++;
			scanf("%d", &a);
			if (a == n)
			{
				printf("Vu ygadali: %d", i);
				return 0;
			}
			else if (a < n)
			{
				printf("bol'she\n");
			}
			else
			{
				printf("men'she\n");
			}
		} while (1);
	}

	else
	{
		int a1 = 1, a2 = 1000, d = 0, c = d, i1 = 0;
		char b = ' ';
		printf("Zagadaite chislo ot 1 do 1000\n");
		while( b != '=')
		{
			i1++;
			c = (a1 + a2) / 2;
			if (c == d)
			{
				c = c - 1;
			}
			printf("%d", c);
			printf("?");
			do {
				scanf("%c", &b);
			} while ((b != '<') && (b != '>') && (b != '='));
			if (b == '<')
			{
				a2 = c;
			}
			else if (b == '>')
			{
				a1 = c; 
			}
			else
			{
				printf("ugadal! %d", i1);
			}
			d = c;
		}
	}
	return 0;
}