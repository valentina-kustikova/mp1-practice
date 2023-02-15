#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int game, number, option_number, count, good, min, max;
    count = 0;
    char answer=' ';
    srand((unsigned int)time(NULL));
    printf("Select the game mode (1-You guess the number given by the computer; 2-The computer guesses the number given by you): ");
    scanf("%d", &game);
    if (game == 1)
    {
        printf("The program made a number from 1 to 1000. Try to guess it. ");
        number = 1 + rand() % (1000);
        do {
            count++;
            scanf("%d", &option_number);
            if (option_number == number)
                printf("Congratulations, you guessed the number!");
            else if (option_number < number)
                printf("The hidden number is bigger. Try again: ");
            else
                printf("The hidden number is smaller. Try again:");
        } while (option_number != number);
    }
    else if (game == 2)
    {
        printf("Guess a number from 1 to 1000 and enter it. The program will try to guess it: \n");
        do {
            scanf("%d", &number);
            if ((number > 1000) || (number < 1)) {
                printf("Incorrect number entered. Try again: ");
            }
        } while ((number > 1000) || (number < 1));
        
        option_number  = 1 + rand() % (1000);
        min = 1;
        max = 1000;
        while (answer!='=') {
            printf("Number %d\n", option_number);
            printf("What is the number?(=,<,>)\n ");
            scanf(" %c", &answer);

            count++;
            if (answer == '>') {
                min = option_number;
                option_number =option_number + (max-min)/2;
            }
            else if (answer == '<') {
                max = option_number;
                option_number = option_number - (max - min) / 2;
            }
        }

    }
    printf("Number: %d was guessed in %d attempts", number, count);
}