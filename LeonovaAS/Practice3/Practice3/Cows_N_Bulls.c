#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int n, i, j, num[6], guess[6], cows = 0, bulls = 0, att = 0;

    do {
        printf("Input n: \n");
        scanf("%d", &n);
    } while ((n < 2) || (n > 5));

    srand((unsigned int)time(0));

    for (i = 0; i < n; i++)
    {
        num[i] = rand() % 10;    
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                while (num[i] == num[j])
                {
                    num[i] = rand() % 10;
                }
            }
        }

    }
    do {
        att++; 
        cows = 0;
        bulls = 0;
        printf("Input your guess\n");
        for (i = 0; i < n; i++) {
            printf("digit number %d is:\n", i + 1);
            scanf("%d", &guess[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j) {
                    if (num[i] == guess[j]) {
                        bulls++;
                    }
                }
                else if (num[i] == guess[j]) {
                    cows++;
                }
            }
        }
        printf("cows: %d bulls: %d\n", cows, bulls);
    } while (bulls != n);

    printf("You won! Your attempts: %d.The number was:\n", att);
    for (i = 0; i < n; i++) {
        printf("%d\n", num[i]);
    }
 
}
