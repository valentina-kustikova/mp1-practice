#include <stdio.h>
void main()
{
    double h, w, d, Massa; //vysota(h), shirina(w), glubina(d)
    double pDVP, pDSP, pDerevo; //plotnosti
    double zad, bok, verkh, niz, dveri, polki; //komplektuyushhie shkafa
    float x;
    printf("Vvedite v sm po poryadku vysotu (h), shirinu (w), glubinu(d) \nDannye dolzhny sootvetstvovat' sleduyushhemu: \n180 <= h <= 220; \n80 <= w <= 120; \n50 <= d <= 90; \n");
    scanf("%lf %lf %lf", &h, &w, &d);
    
    if ((h < 180) || (220 < h))
    {
        printf("Nepravil'nye vysota \n");
        return;
    }

    if ((w < 80) || (120 < w))
    {
        printf("Nepravil'nye shirina \n");
        return;
    }

    if ((d < 50) || (90 < d))
    {
        printf("Nepravil'nye glubina \n");
        return;
    }
    
    printf("Vyberete 1 ili 2 \n1 - ispol'zovanie standart nastroek (DVP = 850; DSP = 650; Derevo = 690) \n2 - vvod znachenij plotnostei samostoyatel'no  \nDannye vvodyatsya v kg/m^3 \n");
    scanf("%f", &x);
    
    if ((x < 1) || (2 < x))
    {
        printf("Nepravil'nye dannye \n");
        return;
    }

    if (x == 1)
    {
        pDVP = 850;
        pDSP = 650;
        pDerevo = 690;
    }

    if (x == 2)
    {
        printf("Vvedite plotnost' DVP (pDVP); plotnost' DSP (pDSP); plotnost' dereva (pDerevo) \n");
        scanf("%lf %lf %lf", &pDVP, &pDSP, &pDerevo);

        if ((pDVP <= 0) || (pDSP <= 0) || (pDerevo <= 0))
        {
        printf("Nepravil'nye dannye \n");
        return;
        }
    }
    
    h *= 0.01;
    w *= 0.01;
    d *= 0.01;
    verkh = (w * d * 0.015) * pDSP; //naklad po verx vsego
    niz = (w * d * 0.015) * pDSP; //naklad po verx vsego
    zad = ((h - 0.03) * w * 0.005) * pDVP;
    bok = 2 * ((h - 0.03) * (d - 0.015) * 0.015) * pDSP;
    dveri = ((h - 0.03) * w * 0,01) * pDerevo; 
    polki = (((h - 0.03) / (0.4f + 0.015)) * (d - 0.015) * (w - 0.03) * 0.015) * pDSP;
    Massa = verkh + niz + zad + bok + dveri + polki;
    printf("%lf Massa shkafa\n", Massa);
}