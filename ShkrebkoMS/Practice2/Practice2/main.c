#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int game,count=0,Computer_Number,number,left=0,right=1000,middle;
	char answer;
	do
	{
		printf("Select the game mode (1-You guess the number given by the computer; 2-The computer guesses the number given by you)\n");
		scanf_s("%d", &game);
		if ((game != 1) && (game != 2))
		{
			printf("You made a mistake with the mode selection, try again!\n");
		}
	} while ((game != 1) && (game != 2));
	if (game == 1)
	{
		srand((unsigned int)time(NULL));
		Computer_Number = rand() % 1001;
		do
		{
			count++;
			do
			{
				printf("Try to guess the number\n");
				scanf_s("%d", &number);
				if ((number > 1000) || (number < 0))
				{
					printf("Enter a number from the range\n");
				}
			} while ((number > 1000) || (number < 0));
			if (number == Computer_Number)
			{
				printf("You guessed the number!\n");
			}
			else if (Computer_Number < number)
			{
				printf("The number of the computer is smaller\n");
			}
			else
			{
				printf("The number of the computer is bigger\n");
			}
			
		}while (Computer_Number != number);
	}
	else if (game==2)
	{
		printf("Guess a number from 1 to 1000 and enter it, the program will try to guess it: \n");
		do {
			scanf_s("%d", &number);
			if ((number > 1000) || (number < 1)) {
				printf("Incorrect number entered. Try again\n");
			}
		} while ((number > 1000) || (number < 1));
		printf("Rules:\n");
		printf("You can use: '=' '>' '<' \n");

		do
		{
			count++;
			middle = (left + right) / 2;
			printf("Is the number = %d\n", middle);
			do
			{
				scanf_s("%c", &answer);
			} while ((answer!= '=') && (answer != '>') && (answer != '<'));
			if (answer == '=')
			{
				printf("The computer guessed the number\n");
			}
			else if (answer == '>')
			{
				left = middle;
			}
			else if (answer =='<')
			{
				right = middle;
			}
		} while (middle != number);

	}

	printf("Number of attempts=%d", count);
	return 0; 
}