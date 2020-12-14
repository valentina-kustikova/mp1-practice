#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int version = -1, restart = 0;
    int ZagadanoeChislo = 0, Chislo = 0, popitki = 0, i = 1, j = 1000;
    char znak;
    srand((unsigned int)time(0));
    printf("-----Dobro pozhalovat' v igru <Ugadaj chislo>-----\n\n");

    do
    {
    printf("Vyberete versiyu igry (1 ili 0): \n1 - Programma zagadyvaet chislo, a vy ego ugadyvaete. \n0 - Vy zagadyvaete chislo, a programma ego ugadyvaet. \nVersiya - ");
    scanf("%d", &version);
    while ((version != 1) && (version != 0))
    {
        printf("Nepravil'nyj vybor versii.");
        break;
    }

    if (version == 1)
    {
        printf("Programma zagadyvaet chislo ot 1 do 1000. \n");
        ZagadanoeChislo = (rand() % 1000) + 1;
    }
    while (version == 1) 
    {
        popitki++;
        do 
        {
            printf("Chislo = ");
            scanf("%d", &Chislo);
        }
        while ((Chislo < 1) || (Chislo > 1000));
        if (Chislo < ZagadanoeChislo)
        {
            printf("---Vvodimoe chislo <Menshe> zagadannogo---\n");
        }
        if (Chislo > ZagadanoeChislo)
        {
            printf("---Vvodimoe chislo <Bolshe> zagadannogo---\n");
        }        
        if (Chislo == ZagadanoeChislo)
        {
            printf("Zagadanoe chislo = %d \n-----You WIN!!!-----\n", ZagadanoeChislo);
            if (popitki == 1)
            {
                printf("Vy vyigrali s 1 popytki.\n");
            }
            else
            {
                printf("Vy vyigrali s %d popytok.\n", popitki);
            }
            version = -1;
            Chislo = 0;
        }
    }

    while (version == 0) 
    {
        while ((Chislo < 1) || (Chislo > 1000))
        {
            printf("Vy zagadyvaete chislo ot 1 do 1000. \nVashe chislo = ");
            scanf("%d", &Chislo);
        }
        popitki++;
        ZagadanoeChislo = 1.0 * (j - i) / RAND_MAX * rand() + i;
        printf("Chislo: %d\n", ZagadanoeChislo);        
        printf("Vvedite '<' esli chislo Bolshe vashego.\n"); 
        printf("Vvedite '>' esli chislo Menshe vashego.\n");
        printf("Vvedite '=' esli chislo Ravno vashemy.\n");
        do 
        {   
            scanf("%c", &znak);
        } 
        while ((znak != '>') && (znak != '<') && (znak != '='));
        switch (znak) 
        {
        case '<': 
            j = ZagadanoeChislo;
            break;    
        case '>': 
            i = ZagadanoeChislo;
            break;    
        case '=': 
            printf("Zagadanoe chislo = %d \n-----WIN!!!-----\n", Chislo);
            if (popitki == 1)
            {
                printf("Vy vyigrali s 1 popytki.\n");
            }
            else
            {
                printf("Popytok %d\n", popitki);
            }
            version = -1;
            Chislo = 0;
            break;
        }
    }
    printf("\nRestart? \n1 = Da \n0 = Net\n");    
    scanf("%d", &restart);
    }
    while (restart == 1);
} 