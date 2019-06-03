#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int n, i, j, flag, bulls, cows;
    long long num = 0, clone, num1;
    int a[10], b[10];
    printf ("Bulls and cows\n");
    printf ("Enter the length of the desired number\n");
    do
    {
        scanf ("%d", &n);
    } while ((n <= 0) || (n > 10));
    i = n;
    srand ((unsigned int)time(0));
    while (i != 0)
    {
        j = 10.0 / RAND_MAX * rand();
        flag = 0; clone = num;
        while (clone != 0)
        {
            if (j == clone % 10)
                flag = 1;
            clone /= 10;
        }
        if (((i == n) || (i == 1)) && (j == 0))
            flag = 1;
        if (flag == 0)
        {
            num = num * 10 + j;
            i--;
        }
    }
    for (i = 0; i < n; i++)
    {
        a[i] = num % 10;
        num = num / 10;
    }
    printf ("Number generated. Try to guess it. Enter a number with non-repeating digits of length %d\n", n);
    bulls = 0;
    while (bulls != n)
    {
        do
        {
            flag = 0; i = 0;
            scanf ("%lld", &num1);
            clone = num1;
            while (clone != 0)
            {
                clone = clone / 10;
                i++;
            }
            if (i == n)
            {
                for (i = n - 1; i > -1; i--)
                {
                    b[i] = num1 % 10;
                    num1 = num1 / 10;
                }
                for (i = 0; i < n - 1; i++)
                    for (j = i + 1; j < n; j++)
                        if (b[i] == b[j])
                            flag = 1;
            }
            else flag = 1;
        } while (flag != 0);
        bulls = cows = 0;
        for ( i = 0; i < n; i++) 
            for (j = 0; j < n; j++)
            {
                if ((a[i] == b[j]) && (i == j)) 
                    bulls++;
                if ((a[i] == b[j]) && (i != j))
                    cows++;
            }
            printf ("Number of bulls = %d\n", bulls);
            printf ("Number of cows = %d\n", cows);
    }
    printf ("You guessed the number");
}