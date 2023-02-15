#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define K 10
int main()
{
    int len, i, tmp, number, d, j, f, k, TryNumber, bulls, cows, LIMIT, AR[N] = { 0 }, arr[N] = { 0 }, chekar[K] = { 0 };
    srand((unsigned int)time(NULL));
    printf("Choose the length of the number (from 2 to 5): \n");
    do {
        scanf("%d", &len);
        if ((len > 5) || (len < 2)) {
            printf("Incorrect number entered. Try again: \n");
        }
    } while ((len > 5) || (len < 2));
    arr[0] = 1 + (rand() % 9);
    for (i = 1; i < len; i++)
    {
        f = 1;
        while (1) {
            d = rand() % 10;
            f = 1;
            for (j = 0; j < i; j++)
            {
                if (arr[j] == d)
                {
                    f = 0;
                    break;
                }
            }
            if (f == 1)
            {
                arr[i] = d;
                break;
            }
        }
    }
    d = 1;
    number = 0;
    for (i = len - 1; i >= 0; i--)
    {
        number = number + arr[i] * d;
        d = d * 10;
    }
    bulls = 0;
    
    while ( bulls != len )
    {
        printf("Try to guess the number: \n");
        do {
            scanf("%d", &TryNumber);
            f = 1;
            LIMIT = 0;
            tmp = TryNumber;
            while (tmp > 0)
            {
                tmp /= 10;
                LIMIT++;
            }
            if (LIMIT!=len) {
                printf("Incorrect number entered. Try again: \n");
            }
            tmp = TryNumber;
            for (i = 0; i < len; i++)
            {
                k = tmp % 10;
                chekar[k]++;
                tmp /= 10;
            }
            for (i = 0; i < K; i++)
            {
                if (chekar[i] > 1)
                {
                    f = 0;
                    break;
                }
            }
            if (f == 0)
            {
                printf("Enter a number with different digits \n");
            }
            for (i = 0; i < K; i++)
            {
                chekar[i] = 0;
            }
        } while ((LIMIT!=len) || (f == 0));
        i = len - 1;
        while (TryNumber > 0)
        {
            AR[i] = TryNumber % 10;
            TryNumber = TryNumber / 10;
            i--;
        }
        bulls = 0;
        cows = 0;
        for (i = 0; i < len; i++)
        {
            if (arr[i] == AR[i])
            {
                bulls++;
            }
        }
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
            {
                if ( ( arr[i] == AR[j] ) && (i != j) )
                {
                    cows++;
                }
            }
        }
        printf("Number of bulls: %d. Number of cows: %d\n", bulls, cows);
    }
    printf("Congratulations!");
    return 0;
}