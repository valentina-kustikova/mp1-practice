#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main() {
    srand(time(NULL));
    int number, user_number, mode, try = 0;
    number = 1 + rand() % (1000);
    do {
        printf("Select game mode (1 or 2): ");
        scanf_s("%d", &mode);
        if ((mode != 1) && (mode != 2))
        {
            printf("Invalid mode selection, try again!\n");
        }
    } while ((mode < 1) || (mode > 2));
    if (mode == 1) {
        printf("The program guessed a number from 1 to 1000. Try to guess it)) : ");
        do {
            scanf_s("%d", &user_number);
            if (user_number == number)
                printf("You guessed the number!\n");
            else if (user_number < number)
                printf("The hidden number is more.Try again : ");
            else
                printf("The hidden number is less. Try again: ");
            try++;
        } while (user_number != number);
        printf("You guessed the number %d in %d tries", number, try);
    }
    else {
        printf("Choose a number from 1 to 1000 and enter it. The program will try to guess it: ");
        do {
            scanf_s("%d", &user_number);
            if (user_number > 1000 || user_number < 0) {
                printf("You entered an invalid number\n");
            }
        } while (user_number > 1000 || user_number < 0);
        int a = 1, b = 1000, number, try = 0;
        char sign;

        printf("Print '<' if your number is less than guessed\n");
        printf("Print '>' if your number is more than guessed\n");
        printf("Print '=' if your number equals guessed\n");

        while (a <= b) {
            try++;
            number = (b + a) / 2;
            printf("%d?\n", number);
            do {
                scanf_s("%c", &sign);
            } while (sign != '=' && sign != '<' && sign != '>');

            if (sign == '=') break;
            if (sign == '<') b = number - 1;
            else a = number + 1;
        }
        printf("Program guessed the number %d in %d tries!", number, try);
    }
}
