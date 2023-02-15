#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 5
int main()
{
	int   len, i, a, k, d, j, fl, s, get, buk, korova, check, m;
    int arr[N] = { 0 };
    int b[N] = { 0 };
    srand((unsigned int)time(NULL));
	printf("Choose the length of the number (from 2 to 5): ");
    do {
        scanf(" %d", &len);
        if ((len > 5) || (len < 2)) {
            printf("Incorrect number entered. Try again: ");
        }
    } while ((len > 5) || (len < 2));
    arr[0] = 1+ (rand() % 9);
    d = 0;
    fl = 1;
    for (i = 1; i < len; i++)
    {
        fl = 1;
        while (1) {
            d = rand() % 10;
            fl = 1;
            for (j = 0; j < i; j++)
            {
                if (arr[j] == d)
                {
                    fl = 0;
                    break;
                }
            }
            if (fl == 1)
            {
                arr[i] = d;
                break;
            }
        }
    }
    get = 0;
    buk = 0;
    korova = 0;
    check = 10;
    for (i = 1; i < len - 1; i++)
    {
        check = check * 10;
    }
    while (buk != len)
    {
        printf("Try to guess the number: ");
        do {
            scanf(" %d", &get);
            if ((get < check) || (get >= check*10)) {
                printf("Incorrect number entered. Try again: ");
            }
            else {
                m = get;
                while (m > 0) {
                    if ((m % 10) == (m / 10 % 10))
                    {
                        printf("Incorrect number entered. Try again: ");
                        break;
                    }
                    m = m / 10;
                }
            }
        } while ((get < check) || (get >= check * 10));
        i = len - 1;
        while (get > 0)
        {
            b[i] = get % 10;
            get = get / 10;
            i--;
        }
        buk = 0;
        korova = 0;
        for (i = 0; i < len; i++)
        {
            if (arr[i] == b[i])
            {
                buk++;
            }
        }
        for (i = 0; i < len; i++)
        {
            for (j = 0; j < len; j++)
            {
                if (arr[i] == b[j])
                {
                    if (i!=j)
                        korova++;
                }
            }
        }
        printf("Number of bulls: %d. Number of cows: %d\n", buk, korova);
    }
    printf("Congratulations!");
}