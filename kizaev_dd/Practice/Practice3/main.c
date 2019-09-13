#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_1 ()
{    
    int att = 1, man = 1001, comp = 1 + rand() % 999;

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

void game_2 ()
{
    char answ = '!';
    int comp = 0, att = 0, upper = 1001, lower = 1, man = 1001;

    do
    {
        printf ("enter your number \n");
        scanf ("%d", &man);
    }
    while ((man < 1) || (man > 1000));

    printf ("trying to guess \n");
    printf ("\n");

    while (answ != '=') // (man != comp) makes the user say only true
    {
        att++;
        comp = lower + (upper - lower) / 2;
        printf ("%d \n", comp);
        scanf ("%*c%c", &answ);

                //write > if your number is > than computer's
                //write < if your number is < than computer's

        switch (answ)
        {
            case '<':
                upper = comp;
            break;
            
            case '>':
                lower = comp;
            break;

            case '=':
                printf ("I win! Number %d in %d attempts \n", comp, att);
            break;

            default:
            {
                printf("enter only >, <, = and don't lie :) \n");
                printf("try again \n");
            }
            break;
        }
    }
}

void game_3 ()
{
    char answ = '!';
    int comp = 0, att = 0, man = 1001, upper = 1001, lower = 1, prev = -1;

    do
    {
        printf ("enter your number \n");
        scanf ("%d", &man);
    }
    while ((man < 1) || (man > 1000));

    printf ("trying to guess \n");
    printf ("\n");

    while (answ != '=') // (comp != man) // checking makes the user say only true
    {
        att++;
        do
            comp = lower + rand() % (upper - lower);
        while (comp == prev);

        printf ("%d \n", comp);
        scanf ("%*c%c", &answ);

        //write > if your number is > than computer's
        //write < if your number is < than computer's

        switch (answ)
        {
            case '<':
                upper = comp;
            break;

            case '>':
                lower = comp;
            break;

            case '=':
                printf ("I win! Number %d in %d attempts \n", comp, att);
            break;

            default:
            {
                printf("enter only >, <, = and don't lie :) \n");
                printf("try again \n");
                break;
            }
        }
    prev = comp;
    }
}

void main ()
{
    int mode;
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
    
    switch (mode)
    {    
        case 1:
            game_1();
        break;

        case 2:
            game_2();
        break;
        case 3:
            game_3();
        break;
    }
    system ("pause");
}