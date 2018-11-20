#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main ()
{
    int mode, att;
    time_t t;
    
    mode = 0;
    srand ((unsigned) time(&t));
    
    printf ("choose game mode \n");
    do
    {
        printf ("1 - you guess \n");
        printf ("2 - clever computer guesses \n");
        printf ("3 - lucky computer guesses \n");
        scanf ("%d", &mode);
    } 
    while ((mode != 2) && (mode != 1) && (mode != 3));
    
    if (mode == 1)
    {
        int man, comp;
        comp = 1 + rand() % 999;
        man = 1001;
        att = 1;
        while (man != comp)
        {
            printf ("enter your number \n");
            scanf ("%d", &man);
            att++;
            if (man < comp)
                printf ("Too little \n");
            else
                if (man > comp)
                    printf ("Too much \n");
        }
        printf ("You win! Number %d in %d attempts \n", comp, att);
    }
    else
        if (mode == 2)
        {
            char answ;
            int comp, man, upper, lower;
            comp = 0;
            att = 0;
            upper = 1001;
            lower = 1;
            man = 1001;

            do
            {
                printf ("enter your number \n");
                scanf ("%d", &man);
            }
            while ((man < 1) || (man > 1000));

            printf ("trying to guess \n");
            printf ("\n");

            while (comp != man)
            {
                att++;
                comp = lower + (upper - lower) / 2;
                printf ("%d \n", comp);
                scanf (" %c", &answ);
            
                //write > if your number is > than computer's
                //write < if your number is < than computer's

                if ((answ == '<') && (comp > man))
                    upper = comp;
                else
                    if ((answ == '>') && (comp < man))
                        lower = comp;
                    else
                        if ((answ == '=') && (comp = man))
                            printf ("I win! Number %d in %d attempts \n", comp, att);
                        else
                        {
                            printf("enter only >, <, = and don't lie :) \n");
                            printf("try again \n");
                            break;
                        }
            }
        }
        else
            if (mode == 3)
            {
                char answ;
                int comp, man, upper, lower, prev;
                comp = 0;
                att = 0;
                upper = 1001;
                lower = 1;
                man = 1001;
                prev = -1;

                do
                {
                    printf ("enter your number \n");
                    scanf ("%d", &man);
                }
                while ((man < 1) || (man > 1000));

                printf ("trying to guess \n");
                printf ("\n");

                while (comp != man)
                {
                    att++;
                    do
                        comp = lower + rand() % (upper - lower);
                    while (comp == prev);

                    printf ("%d \n", comp);
                    scanf (" %c", &answ);

            //write > if your number is > than computer's
            //write < if your number is < than computer's

                    if ((answ == '<') && (comp > man))
                        upper = comp;
                    else
                        if ((answ == '>') && (comp < man))
                            lower = comp;
                        else
                            if ((answ == '=') && (comp = man))
                                printf ("I win! Number %d in %d attempts \n", comp, att);
                            else
                            {
                                printf("enter only >, <, = and don't lie :) \n");
                                printf("try again \n");
                                break;
                            }
                prev = comp;
                }
            }
}