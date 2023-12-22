#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
int main()
{
    int n, i, j, num1[N],num2[N], guess, cows = 0, bulls = 0;
    do {
        printf("Input number length from 2 to 5: ");
        scanf("%d", &n);
    } while ((n < 2) || (n > 5));
    srand((unsigned int)time(0));
    num1[0] = 1 + rand() % 9;
    for (i = 1; i < n; i++)
    {
        while (1)
        {
            int digit = rand() % 10;
            int one = 1;
            for (j = 0; j < n; j++)
                if (num1[j] == digit) one = 0;

            if (one)
            {
                num1[i] = digit;
                break;
            }
        }
    }
    do {
        cows = 0; bulls = 0;
        printf("Input your guess:\n");
        scanf("%d", &guess);
        for (i = n - 1; i >= 0; i--){
            num2[i] = guess % 10;
            guess = guess / 10;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (num2[i] == num1[j]){
                    if (i == j) bulls++;
                    else if (i != j) cows++;
                }
            }
        }
        printf("cows: %d bulls: %d\n", cows, bulls);
    } while (bulls != n);
    printf("You win! Number was:");
    for (i = 0; i < n; i++)
    {
        printf("%d", num1[i]);
    }
    return 0;
}
    