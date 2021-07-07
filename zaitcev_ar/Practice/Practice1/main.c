#include <stdio.h>
#include <math.h>

void main()
{
    float h, w, d, dcp, dvp, der, m1, m2, m3, m4, m5, m;
    float tdcp, tdvp, tder;   //Tolshina dcp,dvp,dereva

    tdcp = 0.015;
    tdvp = 0.005;
    tder = 0.01;

    printf(" Vvedite plotnost dcp(700-800), dvp(800-900), der(670-770) shkafa \n ");
    scanf("%f %f %f", &dcp, &dvp, &der);

    printf(" Vvedite visotu(180cm-220cm), shirinu(80cm-120cm) i glubinu (50cm-90cm) shkafa \n ");
    scanf("%f %f %f",&h, &w, &d);

    if ((h < 180) || (h > 220))
    {
        printf("Error,nekorrektni vvod");
        return;
    }
    if ((w < 80) || (w > 120)) 
    {
        printf("Error,nekorrektni vvod"); 
        return;
    } 
    if ((d < 50) || (d > 90))
    {
        printf("Error,nekorrektni vvod");
        return;
    }

    h = h / 100.0;
    w = w / 100.0;
    d = d / 100.0;

    m1 = (h * w * tdvp * dvp);                                                       //Zadnia stenka
    m2 = (2 * h * d * tdcp * dcp);                                                   //Bokovini
    m3 = (2 * w * d * tdcp * dcp);                                                   //Verh i niz
    m4 = (h * w * tder * der);                                                       //2 dveri
    m5 = (int)((h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005) * dcp);    //Polki

    m = m1 + m2 + m3 + m4 + m5;

    printf(" Macca shkafa(kg) = %f ", m);
    return;
}
