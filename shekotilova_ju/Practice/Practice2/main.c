#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 

void main()
{
    int Bull = 0, Cow = 0, n, k, i, j, num, p, ch, a[N],c[N];
    int b[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand((unsigned int)time(0));
    do 
    {
        printf("Choose the length of number (enter a number 1-9): \n");
        scanf("%d", &n);
    }while ((n <= 0) || (n > 10));
    printf("Program made a number \n");
    i=n-1;
    k=9.0/RAND_MAX*rand()+1;
    a[0]=k;
    b[k]=-1;
    while(i>0)
    {
        k=10.0/RAND_MAX*rand();
        if (b[k]!=-1) 
        {
            a[i]=b[k];
            b[k]=-1;
            i--;
        } 
    }
    printf("\nEnter a number with the same lenght(%d)(figures shouldn't be repeated)", n);
    do 
    {
        printf("\n Number= ");
        scanf("%d", &num);
        Bull = 0;
        Cow = 0;
        k = 0;
        ch = 0;
        p = num;
        while (p>0)
        {
            p = p/10;
            ch++;
        }
        if (ch!=n)
        {
            printf("Error (your number !=%d) ", n);
            continue;
        }
        do 
        {
            for (i=(n - 1);i>= 0;i--)
            {
                c[i]=num%10;
                num=num/10;
            }
            for (i= (n-1);i>= 0;i--)
            {
                for (j=(i-1);j>= 0;j--)
                {
                    if (c[i]==c[j]) 
                    k++;
                }
            }
        } while (k);
        for (i = (n - 1); i >= 0; i--)
        {
            for (j = (n - 1); j >= 0; j--)
            {
                if ((a[i] == c[j]) && (i == j)) 
                Bull++;
                if ((a[i] == c[j]) && (j != i)) 
                Cow++;
            }
        }
        printf("Cow = %d \nBull = %d\n", Cow, Bull);
    } while (Bull != n);
    printf("\nYou won!!!\n");
} 
