#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int mode, num, guess, attempts = 0, new;
    char hint;
    printf("select mode 1 or mode 2: ");
    scanf("%d", &mode);

    if (mode == 1)
    {
        srand((unsigned int)time(0));
        num = ((1000 - 1) * rand()) / RAND_MAX + 1;
        do
        {
            attempts += 1;
            printf("input your guess: ");
            scanf("%d", &guess);
            if (guess == num)
            {
                printf("congrats! u won! your attempts: %d \n", attempts);
            }
            if (guess < num)
            {
                printf("> \n");
            }
            if (guess > num)
            {
                printf("< \n");
            }

        } while (guess != num);
    }
    else
    {
        printf("input your number: \n");
        scanf("%d", &num);
        guess = ((1000 - 1) * rand()) / RAND_MAX + 1;
        do
        {
            attempts += 1;
            if (guess == num)
            {
                printf("computer won! his attempts: %d\n", attempts);
            }
            else
            {
                printf("guess is: %d. Give a hint please \n", guess);
                scanf("%c", &hint);
                new = guess;
                switch (hint)
                {
                case '<': guess = ((1000 - new) * rand()) / RAND_MAX + new;
                    break;
                case '>': guess = ((new - 1) * rand()) / RAND_MAX + 1;
                    break;
                }

            }

        } while (guess != num);
    }
    return 0;
}