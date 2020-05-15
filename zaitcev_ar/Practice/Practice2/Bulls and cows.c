#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void main ()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int b[10];
    int n, n2, N2, c, tc, i, i2, B, K;
    srand((unsigned int)time(0));
    do
    {
        printf ("Vvedite kolichestvo tcifr v zagadannom chisle (do 10) \n"); 
        scanf("%d", &n);
    }while ((n <= 0)||(n > 10));

    for (i = 0; i < n;  i++)
    {
        c = rand() % 10;
        tc = a[c];
        a[c] = a[i];
        a[i] = tc;
    }
    if (a[n - 1] == 0)
    {
        do
        {
            c = rand() % 10;
        }while (c == n - 1);
        tc = a[n - 1];
        a[c] = a[n - 1];
        a[i] = tc;
    }
    n2 = 1;
    for (i = 0; i < n; i++)
    {
        n2 = n2 * 10;
    }
    while (1)
    {
        printf ("Vvedite chislo \n");
        scanf("%d", &N2);
        if (N2 > n2)
        {
            printf ("Neverni vvod \n");
            continue;
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] == a[i])
            {
                B++;
            }
            for (i2 = 0; i2 < n; i2++)
            {
                if (b[i] == a[i2])
                {
                    K++;
                }
            }
        }
        printf ("Bulls %d \n Cows %d \n", B, abs(K - B));
        if (B == n)
        {
            printf ("You Win!!!");
            return;
        }
    }
}