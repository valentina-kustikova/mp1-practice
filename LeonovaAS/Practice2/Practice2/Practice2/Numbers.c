#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int mode, num, guess, attempts = 0, end = 1000, start = 1;
    char hint;
    printf("select mode 1 or mode 2: ");
    scanf("%d", &mode);

    if (mode == 1)
    {
        srand((unsigned int)time(0));
        num = ((end - start) * rand()) / RAND_MAX + start;
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
        guess = ((end - start) * rand()) / RAND_MAX + start;
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
                if (hint == '>')
                {
                    start = guess;
                    guess = ((end - start) * rand()) / RAND_MAX + start;
                }
                if (hint == '<')
                {
                    end = guess;
                    guess = ((end - start) * rand()) / RAND_MAX + start;
                }
                if (hint == '=')
                {
                    printf("lol");
                }

            }

        } while (guess != num);
    }
    return 0;
}