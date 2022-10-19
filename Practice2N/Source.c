#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
	int a, n, d = 0, up = 1000, c, s, i, count = 0;
	char symbol;
	srand(time(NULL));
	printf("\tHi, dear friend. Let`s play the game\n");
	do
	{
		printf("\tChoose the game mode:\n\tPress 1 if you want to make a number\n\tPress 2 if you want to search the hidden number\t");
		scanf_s("%d", &c);
	} while (c != 1 && c != 2);
	switch (c)
	{
	case 1:

		do
		{
			printf("Input number from 0 to 1000:\t");
			scanf_s("%d", &n);
			getchar();
		} while (n < 0 || n>1000);
		srand(time(NULL));
		a = rand() % 1000;
		printf("Is it\t%d?\n", a);
		printf("\tInput <,>,=\t");
		do
		{
			scanf_s("%c", &symbol);
			switch (symbol)
			{
			case '=':
				printf("The program has found the number.\t It`s:%d", a); break;

			case '>':

				
				d = a;
				a = (d + 1) + rand() % (up - d + 1);
				printf("Is it:%d?\t", a);
				printf("%d\t%d\t", d, up); break;

				up = 1000;
			case'<':
				i = up;

				
				up = a;
				a = d + rand() % (a - d + 1);
				i = a;
				printf("Is it:%d\t", a);
				printf("%d\t%d\t", d, up); break;


			}
			count++;
		} while (symbol != '=');
		printf("Attemps = %d", count);

	case 2:
		
		a = rand() % 1000;
		printf("Input the number\t");
		do
		{
			scanf_s("%d", &n);
			if (n > a)
			{
				printf("The number is less\t");
				
			}
			else if (n < a)
			{
				printf("The number is much\t");
				
			}
			 else 
			{
				printf("Congratulations! You`re win!");
				printf("Attemps =\t%d", count);
				
			}
			count++;
		} while (n != a);

	}

	return 0;

}
