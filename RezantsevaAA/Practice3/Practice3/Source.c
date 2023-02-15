#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>
#define N 5
void main()
{
    int number[N] = { 0 };
    int arr[N] = { 0 };
    int n, i, flag, j, r, p_num, cow, bull, check,p,flag1;
    printf("Enter the number of digits in the number from 2 to 5 ");
    srand(time(NULL));
    do {
        scanf("%d", &n);
        if ((n > 5) || (n < 2)) {
            printf("Invalid number entered. Try again\n");
        }
    } while ((n > 5) || (n < 2));
    number[0] = 1 + rand() % (9);
    r = 0;
    flag = 1;
    for (i = 1; i < n; i++)
    {
        flag = 1;
        while (flag == 1) {
            r = rand() % 10;
            flag = 1;
            for (j = 0; j < i; j++)
            {
                if (number[j] == r)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                number[i] = r;
                break;
            }
        }
    }
    bull = 0;
    
    while (bull != n)
    {
        printf("Try to guess the number: ");
        do {
            scanf(" %d", &p_num);
            check = 0;
            p = p_num;
            flag1 = 1;
            while (p > 0)
            {
                if ((p % 10) == (p / 10 % 10))
                {
                    flag1 = 0;
                    printf("Incorrect number entered. Try again: ");
                    break;
                }
                p = p / 10;
                check++;
            }
            if ((flag1 == 1)&&(check != n))
            {
                printf("Invalid number entered. Try again: ");
            }
        } while (check != n);
        i = n - 1;
        while (p_num > 0)
        {
            arr[i] = p_num % 10;
            p_num = p_num / 10;
            i--;
        }
        bull = 0;
        cow = 0;
        for (i = 0; i < n; i++)
        {
            if (number[i] == arr[i])
            {
                bull++;
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (number[i] == arr[j])
                {
                    if (i != j)
                        cow++;
                }
            }
        }
        printf("Number of bulls: %d. Number of cows: %d\n", bull, cow); 
    }
    printf("Congratulations! You guessed the number!");
}