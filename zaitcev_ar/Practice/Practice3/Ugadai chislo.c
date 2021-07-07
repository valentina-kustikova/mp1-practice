#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main ()
{
    int regim, n, n1, n2, a, c, d;
    char otnoshenie;
    c = 0;
    n1 = 1;
    n2 = 1000;
    srand ((unsigned int)time(0));

    do
    {
        printf (" enter (1 or 2) for choice regima\n ");
        scanf("%d", &regim);
    } while ((regim != 1) && (regim != 2));

    if (regim == 1)
    {
        n = (rand() % 1000) + 1;
        while (1)
        {
            printf (" Vvedite luboe chislo\n ");
            scanf ("%d", &d);
            c++;
            if (d == n)
            {
                break;
            }
            if (d > n)
            {
                printf (" Vvodimoe chislo bolshe zagadannogo\n\n ");
            }
            if (d < n)
            {
                printf (" Vvodimoe chislo menshe zagadannogo\n\n ");
            }
        }
        printf (" You ugadali chislo \n kolichestvo hodov = %d ", c);
        return;
    }

    if (regim == 2)
    {
        do
        {
            printf(" Vvedite chislo (1-1000) (enter 2 times) \n ");
            scanf("%d", &n);
        } while ((n < n1) || (n > n2));

        do {
            c++;
            a = (n2 - n1) / RAND_MAX * rand() + n1;
            printf(" Computer: This chislo %d ", a);

            printf(" User: Your otnoshenie (>, <, =) - "); 
            scanf("%*c%c", &otnoshenie);

            switch (otnoshenie)
            {
            case '>':
                a = (n2 - 1) / RAND_MAX * rand() + n1;
                break;
            case '<':
                a = (n2 - n1) / RAND_MAX * rand() + n1;
                break;
            case '=':
                printf(" User: Ugadali. ");
                printf(" Number of attempts = %d ", c);
                return;
            }
            } while (a != 0);
    }
}