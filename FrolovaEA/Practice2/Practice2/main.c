#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
int main()
{
	int a, number, attempt, b, i, res;
	char zn;
	srand(time(NULL));

	printf("Select game mode: 1-number guesses computer, 2 - the number is guessed by the person\n");
	do
	{
		scanf_s("%d", &a);
	} while ((a < 1) || (a > 2));

	switch (a)
	{
		case 1:
		{
			number = 1 + rand() % 1000;
			printf("Enter the number");
			i = 0;

			do
			{
				scanf_s("%d", &b);
				if (b < number) printf("less\n");
				if (b > number) printf("greater\n");
				i++;
			} while ((b != number));
			printf("you found the number - %d\n", b);
			printf("number of attempts - %d", i);

			break;
		}

		case 2:
		{	
			int res = 0, x = 1, y = 1000, num = 0;
			char zn;

			b = 1 + rand() % 1000;
			printf("number=%d\n", b);
			printf("Enter the zn\n");

			do
			{
				zn = getc(stdin);

				switch (zn)
				{
				case '>':
					printf("I will try again\n");
					y = b;
					b = x + rand() % (y - x + 1);
					printf("number=%d\n", b);
					break;

				case '<':
					printf("I will try again\n");
					x = b;
					b = x + rand() % (y - x + 1);
					printf("number=%d\n", b);
					break;

				case '=':
					printf("number is found\n");  res = 1; break;

					//default: printf("error");
				}
				num++;
			} while (res != 1);
			printf("i found the number - %d\n", b);
			printf("number of attempts - %d", num/2);
		}
	}
	return 0;
}
