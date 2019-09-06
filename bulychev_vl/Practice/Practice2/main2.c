#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 

void main()
{
    int Bull = 0, Cow = 0, Nomer, k, i, j, CHislo, Pr1, Proverka;
    int A[N];
    int C[N];
    int B[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("Dobro pozhalovat' v igru <Bulls and Cows> \nTSel' igry: Otgadat' zagadannoe programmoj chislo \nPravila igry: \n1. Vyberite dlinu chisla 0 < Nomer < 10 \n2. Vvedite chislo dlinnoyu toj tsifry kotoroyu vybrali. TSifry v chisle ne dolzhny povtoryat'sya. \n3. Programma vam vydast chislo Korov i Bykov \n<Korovy> - TSifra ugadana na nevernoj pozitsii \n<Byki> - TSifra ugadana vplot' do pozitsii \n4. Povtoryat' do tekh por poka chislo bykov ne sovpadet s zagadannoj tsifroj ili Programma vydast: <You WIN!!!> \n---------------------------------------------\n");
    srand((unsigned int)time(0));

    do 
    {
        printf("Vyberite dlinu chisla 0 < Nomer < 10 \nNomer = ");
        scanf("%d", &Nomer);
    }
    while ((Nomer <= 0) || (Nomer > 10));
    printf("Programma zagadyvaet %d - znachnoe chislo.\n", Nomer);
    i = Nomer - 1;
    k = 9.0 / RAND_MAX * rand() + 1;
    A[0] = k;
    B[k] = -1;
    while (i > 0)
    {
        k = 10.0 / RAND_MAX * rand();
        if (B[k] != -1) 
        {
            A[i] = B[k];
            B[k] = -1;
            i--;
        } 
    }

    printf("\nVvedite chislo dlinnoyu %d tsifry. TSifry v chisle ne dolzhny povtoryat'sya.", Nomer);

    do 
    {
        printf("\nCHislo = ");
        scanf("%d", &CHislo);
        Bull = 0;
        Cow = 0;
        k = 0;
        Proverka = 0;
        Pr1 = CHislo;

        while (Pr1 > 0)
        {
            Pr1 = Pr1 / 10;
            Proverka++;
        }
        if (Proverka != Nomer)
        {
            printf("!!! V vvedennom chisle dolzhno byt' %d cifr !!!  ", Nomer);
            continue;
        }

        do 
        {
            for (i = (Nomer - 1); i >= 0; i--)
            {
                C[i] = CHislo % 10;
                CHislo = CHislo / 10;
            }
            for (i = (Nomer - 1); i >= 0; i--)
            {
                for (j = (i - 1); j >= 0; j--)
                {
                    if (C[i] == C[j]) 
                    k++;
                }
            }
        } 
        while (k != 0);
        for (i = (Nomer - 1); i >= 0; i--)
        {
            for (j = (Nomer - 1); j >= 0; j--)
            {
                if ((A[i] == C[j]) && (i == j)) 
                Bull++;
                if ((A[i] == C[j]) && (j != i)) 
                Cow++;
            }
        }
        printf("Cow = %d and Bull = %d", Cow, Bull);
    } 
    while (Bull != Nomer);
    printf("\n-----------\nYou WIN!!!\n-----------\n");
}