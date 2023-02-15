#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(NULL));
    int number, user_number;
    int min = 1, max = 1000, try = 0;
    char mode, answer;
    number = 1 + rand() % (1000);
    printf("Select operating mode 1 or 2: ");
    scanf("%c", &mode);
    switch (mode) {
    case '1':
        printf("The program guessed a number from 1 to 1000. Try to guess it)) : ");
        do {
            scanf("%d", &user_number);
            if (user_number == number)
                printf("You guessed the number!\n");
            else if (user_number < number)
                printf("The hidden number is greater.Try again : ");
            else
                printf("The hidden number is less. Try again: ");
            try++;
        } while (user_number != number);
        printf("You guessed the number %i in %i tries!", number, try);
        break;
    case '2':
        printf("Think of a number from 1 to 1000 and enter it. The program will try to guess it: ");
        do {
            scanf("%d", &user_number);
            if (user_number > 1000 || user_number < 0) {
                printf("Invalid number entered\n");
            }
        } while (user_number > 1000 || user_number < 0);
        while (user_number != number) 
        {
            number = min + rand() % (max - min + 1);
            printf("Is it number %d ? ", number);
            scanf("%c", &answer);
            if (scanf("%c", &answer) != 1) 
            {
                while ((answer = getchar()) != '\n' && answer != EOF) 
                {
                    ;
                }
            }
            try++;
            if (answer == '=')
                printf("The program guessed the number %i in %i tries!", number, try);
            else if (answer == '>')
                min = 1 + number;
            else if (answer == '<')
                max = number - 1;
        }
        break;
    }
    return 0;
}