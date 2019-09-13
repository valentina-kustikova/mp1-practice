#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct goods
{
    char name [32];
    char code [5];
    int amount;
    int price;
    int discount;
}

goods [9999];

int lsc = -1; // last scanned code

void scangood() // scanning function
{
    int id, dec;
    char s[10];
    do
    {
        id = 0; dec = 1;
        printf ("enter code (0001 to 9999) \n");
        scanf ("%s", s);

        for (int j = 3, dec = 1; j >= 0; j--, dec = dec * 10)
        {
            int t = s[j] - '0';
            if ((strlen (s) != 4) || (t > 9) || (t < 0))
                id = 10000;
            else
                id += t * dec;
        }            
    }
    while ((id > 9999) || (id < 1));
    lsc = id - 1;
    printf ("%s: %s scanned \n", goods[lsc].code, goods[lsc].name);
}

void show_scanned() // function displays info about the last scanned good
{
    if (lsc == -1)
        printf ("no codes scanned during this session \n");
    else
    {
        printf ("Code: %s \n", goods[lsc].code);
        printf ("Name: %s \n", goods[lsc].name);
        printf ("Price: %d ru \n", goods[lsc].price);
        printf ("Discount: %d %%\n", goods[lsc].discount);
    }
}

void addtocheck() // function adds 1 unit of last scanned good to the check
{
    if (lsc == -1)
    {
        printf ("no codes scanned during this session, starting scanner...\n");
        scangood ();
        addtocheck();
    }
    else
    {
        goods[lsc].amount++;
        printf ("%s: %s added\n", goods[lsc].code, goods[lsc].name);

        printf ("Name: %s | Amount in check: %d \n",
        goods[lsc].name, goods[lsc].amount);

    }
}

void formcheck() // function displays check with all info about added goods
{
    int empty = 1, tsum = 0;
    float disc = 0.0f;
    for (int i = 0; i < 9999; i++)
        if (goods[i].amount != 0)
        {
            int sum = goods[i].amount * goods[i].price;
            
            printf ("Name: %s | Price: %d ru | Amount: %d | Sum: %d ru \n",
            goods[i].name, goods[i].price, goods[i].amount, sum);
            
            tsum += sum;
            disc += (goods[i].discount) * 0.01f * sum;
            empty = 0;
        }
    if (empty == 1)
        printf ("empty check, no goods added \n");
    else 
    {
        printf ("Total sum: %d ru \n", tsum);
        printf ("Total discount: %.2f ru \n", disc);
        printf ("Total sum to pay: %.2f ru \n", (float)tsum - disc);
    }    
}

void total() // function displays total sums and the total discount
{
    int empty = 1, tsum = 0;
    float disc = 0.0;
    for (int i = 0; i < 9999; i++)
        if (goods[i].amount != 0)
        {
            int sum = goods[i].amount * goods[i].price;
            tsum += sum;
            disc += (goods[i].discount) * 0.01f * sum;
            empty = 0;
        }
    if (empty == 1)
    {
        printf ("Total sum: 0.00 ru \n");
        printf ("Total discount: 0.00 ru \n");
        printf ("Total sum to pay: 0.00 ru \n");
    }
    else 
    {
        printf ("Total sum: %d ru \n", tsum);
        printf ("Total discount: %.2f ru \n", disc);
        printf ("Total sum to pay: %.2f ru \n", (float)tsum - disc);
    }
}

void main()
{
    int i, mode = 0;
    time_t t;
    srand ((unsigned) time(&t));

    for (i = 0; i < 9999; i++)
    {    
        sprintf (goods[i].code, "%04d", i + 1); 
        sprintf (goods[i].name, "product%s", goods[i].code);
        // generated names instead of printing 9999 real ones
        goods[i].amount = 0;
        // amount in check
        goods[i].price = 1 + rand() % 1000;
        goods[i].discount = 1 + rand() % 50;        
        /* existence in the check of this kind of product,
        without taking into account the amount */
    }

    printf ("Choose operation \n");
    printf ("1 - scan code \n");
    printf ("2 - show information from scanned code \n");
    printf ("3 - add good to check \n");
    printf ("4 - form the final check \n");
    printf ("5 - count total sum \n");
    printf ("0 - exit \n");

    do
    {
        printf ("################################################ \n");
        do
        scanf ("%d", &mode);
        while ((mode<0) || (mode > 5));

        switch (mode)
        {
        case 1:
            scangood();
        break;    

        case 2:
            show_scanned();
        break;

        case 3:
            addtocheck();
        break;

        case 4:
            formcheck();
        break;

        case 5:
            total();
        break;
        }
    }
    while (mode!=0);
    system ("pause");
}
