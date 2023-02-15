#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void main()
{
	int mode_game;
	printf("Welcome to the 'Guess the number game'!\n");
	do {
		printf("Please select mode:\n 1: you guess the number of the computer\n 2: the computer guesses your number\n");
		scanf("%d", &mode_game);
	} while ((mode_game > 2) || (mode_game < 1));
	if (mode_game == 1)
	{
		int random_num;
		int k = 0;
		int player_num = 0;
		printf("I made a number, guess it!\n");
		srand(time(NULL));
		random_num = 1 + rand() % (1000 - 1 + 1);
		while (player_num != random_num)
		{
			printf("Enter your number ");
			scanf("%d", &player_num);
			k++;
			if (player_num > random_num)
			{
				printf("The hidden number is less\n");
				
			}
			else if (player_num < random_num)
			{
				printf("The hidden number is greater\n");
			
			}
		}
		k++;
		printf("Congratulations! You guessed the number\nThe number of your attempts: %d", k);
	}
	else if (mode_game == 2)
	{
		int min_num = 1, max_num = 1000;
		int k = 0;
		int random_num2, player_num;
		char symbol;
		do {
			printf("During the game, enter\n '>' if your number is greater\n '<' if your number is less\n '=' if the computer guessed the number\n");
			printf("Enter your number from 1 to 1000 ");
			scanf("%d", &player_num);
		} while ((player_num > 1000) || (player_num < 1));
		
		srand(time(NULL));
		random_num2 = min_num + rand() % (max_num - min_num + 1);
		k++;
		printf("%d? ", random_num2);
		scanf(" %c", &symbol);
		

		while (true)
		{
			if (symbol == '>')
				min_num = random_num2 + 1;
			else if (symbol == '<')
				max_num = random_num2 - 1;
			else if (symbol == '=') 
				break;
			
			srand(time(NULL));
			random_num2 = min_num + rand() % (max_num - min_num + 1);
			k++;
			printf("%d? ", random_num2);
			scanf(" %c", &symbol);
		}
		printf("The computer guessed the number!\nThe number of attempts %d ", k);
	}
}
