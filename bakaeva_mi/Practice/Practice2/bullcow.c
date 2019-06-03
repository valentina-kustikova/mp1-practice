#include <stdio.h> 
#include <stdlib.h>
#include <time.h>  
#define max_size 10 

void main()
{
    int dlina = 0, i = 0, j = 0, n1 = 0;
    int n2 = 9, a, a1, k = 1;
    int prov = 0, bull = 0, cow = 0, h = 1;
    int chislo[max_size] = { 0 };
    int proverka[max_size] = { 0 };

    printf("WELCOME TO THE GAME 'BULLS AND COWS' \n \n");
    do
    {
        printf("Computer: Enter the lengh of the number (to 10)\n"); //Proverka 
        scanf("%d", &dlina);

    } while ((dlina < 0) || (dlina > max_size));

    srand((unsigned int)time(0));

    chislo[0] = rand() % 8 + 1;
    for (i = 1; i < dlina; i++)
    {
        chislo[i] = rand() % 9;
        if (i > 0)
            for (j = 0; j < i; j++)
                if (chislo[i] == chislo[j])
                {
                    i--;
                    break;
                }
    }
   
    printf("Computer: I made a number, try to guess it!\n");

    while (bull != dlina) {

        bull = 0;
        cow = 0;

        do
        {
            k = 0;
            printf("\nComputer: Enter your number\nUser: ");
            scanf("%d", &a);
            a1 = a;
            prov = 0;

            while (a1 != 0)
            {
                prov++;
                a1 /= max_size;
            }
            if ((a < 0) || (prov != dlina)) k = 1;

            a1 = a;

            for (i = dlina; i > 0; i--)
            {
                proverka[i - 1] = (a1 % max_size);
                a1 /= max_size;
            }

            for (i = 0; i < dlina; i++)
                for (j = i + 1; j < dlina; j++)
                    if (proverka[i] == proverka[j])
                        k = 1;
        } while (k);


        for (i = 0; i < dlina; i++)
            for (j = 0; j < dlina; j++)
                if (chislo[i] == proverka[j]) cow++;
        for (i = 0; i < dlina; i++)
            if (chislo[i] == proverka[i]) bull++;

        if (bull < dlina) printf("Computer: bulls = %d cows = %d\n", bull, cow);
    }
    printf("Computer: YOU WIN!");
    return;
}