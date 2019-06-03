#include <stdio.h>
#include <math.h>
#define qdcp 0.015
#define qdvp 0.005
#define qder 0.01


void main() {
    double w, h, d, dcp, dvp, der;
    double m1, m2, m3, m4, m5, m;

    printf(" Vvedite visotu (180sm - 220sm), shirinu (80sm - 120sm) i glubinu (50sm - 90sm) shkafa \n");
    scanf(" %lf %lf %lf", &h, &w, &d);

    if ((h < 180) || (h > 220))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    if ((w < 80) || (w > 120))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    if ((d < 50) || (d > 90))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    printf(" Vvedite plotnost DSP, DVP i plotnost dereva ( kg/m3 ) \n");
    scanf("%lf %lf %lf", &dcp, &dvp, &der);

    if ((dcp < 0) || (dvp < 0) || (der < 0))
    {
        printf(" Error - nekorrektni vvod ");
        return;
    }

    h /= 100;
    w /= 100;
    d /= 100;

    m1 = (h * w * qdvp * dvp);          //Zadnia stenka
    m2 = (2 * dcp * h * d * qdcp);     //Bokovini
    m3 = (2 * dcp * w * d * qdcp);     //Verh i niz
    m4 = (h * w * qder * der);           //Dveri
    m5 = (int)((h - 2 * qdcp) / (0.4 + qdcp)) * (w - 2 * qdcp) * (d - qdvp);    //Polki
    m = m1 + m2 + m3 + m4 + m5;

    printf(" Massa shkafa = %.2lf kg \n", m);
    return;
}