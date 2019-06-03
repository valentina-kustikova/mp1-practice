#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
    char regim, ocenka;
    int n, i, a, n1, n2;

    n1 = 1;
    n2 = 1000;

    do
    {
        printf("Hello, guess you in 1 mode and the computer guesses in 2 mode\n");
        printf("Select game mode (1 or 2) \n");
        scanf("%c", &regim);
    } while ((regim != '1') && (regim != '2'));

    switch (regim)
    {
    case '1':
        srand((unsigned int)time(0));
        n = rand() % (n2 - n1) + n1;
        i = 0;

        do
        {
            i++;
            do
            {
                printf("\nComputer: Enter your number\n User:");
                scanf("%d", &a);
            } while ((a < 1) || (a > 1000));

            if (n > a) printf(" Computer: Your number is less (NumComp > NumUser)");
            if (n < a) printf(" Computer: Your number is greater (NumComp < NumUser)");
            if (n == a)
            {
                printf(" Computer: GUESSED!");
                printf(" Number of attempts = %d ", i);
                return;
            }
        } while (a != n);

    case  '2':
        do
        {
            printf("Enter your number (1 - 1000)\n");
            scanf("%d", &n);
        } while ((n < 1) || (n > 1000));

        printf("\nUser: I made a number. Guess it, Computer!\n\n");
        i = 0;

        do
        {
            srand((unsigned int)time(0));
            a = rand() % (n2 - n1) + n1;

            i++;

            printf("\nComputer: I think this number is %d \n", a);
            printf(" User: Your number - ");
            scanf("%s", &ocenka);

            switch (ocenka)
            {
            case '>':
                n2 = a;
                break;
            case '<':
                n1 = a;
                break;
            case '=':
                printf(" User: GUESSED!");
                printf(" Number of attempts = %d ", i);
                return;
            default:
                printf("Please, enter only > or < or =\n");
            }
        } while (a != n);
    }
}