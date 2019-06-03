#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main ()
{
    int dig[10], num [10];
    int n = 0, k = 0, i, j, inp, flag, att;
    time_t t;

    srand ((unsigned) time(&t));

    while ((n < 1) || (n > 9))
    {
        printf ("enter length of a number \n");
        scanf ("%d", &n);
    }
    
    //creating a number with different digits
    for (i = 0; i <= 9; i++)
        dig[i]=i; //array of unused digits
    
    num[0] = 1 + rand() % 9;
    dig[num[0]] = -1;

    for (i = 1; i < n; i++)
    {
        do
            k = rand() % 10;
        while (dig[k] < 0);

        num[i] = dig[k];
        dig[k] = -1;
    }
    /*

    //show machine's number (debug)
    for (i = 0; i < n; i++)
    {
        printf ("%d", num[i]);
    }
    printf ("\n");
    printf ("try to guess! \n");

    */

    //GAME
    att = 0;
    do
    {
        flag = 0;
        printf ("enter your number \n");
        scanf ("%d", &inp);
        att++;
        i = 0;
        k = inp;
        do
        {
            dig[n - 1 - i] = k % 10;
            k = k / 10;
            i++;
        }
        while (k != 0);
        
        //looking for wrong input
        
        if (i != n)
            flag = 1;
        else
            for (i = 0; i <n ; i++)
                for (j = i + 1; j < n; j++)
                    if ((dig [i] == dig[j]))
                        flag = 2;
        
        //error reports OR game
        if (flag == 1)
            printf ("wrong length, try again \n");
        else
            if (flag == 2)
                printf ("use a number with different digits \n");
            else
            {
                int b = 0, c = 0;
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        if ((num [i] == dig[j]))
                            if (i == j)
                                b++;
                            else
                                c++;    
                if (b == n)
                {
                    printf ("You win! Number %d in %d attempts \n", inp, att);
                    flag = 9;
                }
                else
                    printf ("%d bulls, %d cows \n", b, c);
            }        
    }
    while (flag != 9);
}