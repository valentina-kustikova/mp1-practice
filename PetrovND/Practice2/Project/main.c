#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	short gameMode, userNum, randomNumber, a = 1, b = 1000;
	int attemptsNumber = 0;
	char userSymbol;

	do {
		printf("Choose a game mode...\n 1) You guess the number the computer wants\n 2) The computer guesses the number you intend\n");
		if (scanf("%hd", &gameMode) != 1) {
			printf("Enter only numbers...");
			return 1;
		}
	} while ((gameMode > 2) || (gameMode < 1));

	switch (gameMode) {

		case 1: //Computer guesses number
			srand((unsigned int)time(NULL));
			randomNumber = a + rand() % (b - a + 1);

			while (1){

				do {
					printf("\nEnter your intended number in range from 1 to 1000...\n");
					if (scanf("%hd", &userNum) != 1) {
						printf("Enter only numbers...");
						return 1;
					}
				} while ((userNum < 1) || (userNum > 1000));

				attemptsNumber++;
				if (userNum < randomNumber)
					printf("Your number < than the hidden number\n");
				if (userNum > randomNumber)
					printf("Your num > than the hidden number\n");
				if (userNum == randomNumber) {
					printf("You win! Hidden number is: %hd\n", randomNumber);
					printf("Attempts number: %d", attemptsNumber);
					break;
				}
			}
			break;
		case 2: //User guesses number
			
			printf("\nGuess the number from 1 to 1000\n");
			printf("Answer, your mysterious number is > or < or = the number claimed by computer.\n");
			while (1){

				srand((unsigned int)time(NULL));
				randomNumber = a + rand() % (b - a + 1);

				printf("Your mysterious number is %hd?\n", randomNumber);
				do {
					scanf("%c", &userSymbol);
				} while ((userSymbol != '=') && (userSymbol != '<') && (userSymbol != '>'));

				attemptsNumber++;
				if (userSymbol == '<')
					b = randomNumber-1;
				if (userSymbol == '>')
					a = randomNumber+1;
				if (userSymbol == '=') {
					printf("Your mysterious number is %hd!\n", randomNumber);
					printf("Attempts number: %d", attemptsNumber);
					break;
				}
			}
			break;			
	}
	return 0;
}