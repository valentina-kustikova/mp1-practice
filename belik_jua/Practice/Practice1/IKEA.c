#include <stdio.h>

void main()
{
    double h = 0, w = 0, d = 0, m = 0, dvp, dsp, der;

    do{
        printf("180 < h < 220, h = \n");
        scanf("%lf", &h);
    } while ((h > 220) || (h < 180));
    h = h * 0.01;
    do {
        printf("80 < w < 120, w = \n");
        scanf("%lf", &w);
    } while ((w > 120) || (w < 80));
    w = w * 0.01;
    do {
        printf("50 < d < 90, d = \n");
        scanf("%lf", &d);
    } while ((d > 90) || (d < 50));
    d = d * 0.01;

    printf("density dvp \n");
    scanf("%lf", &dvp);
    printf("density dsp \n");
    scanf("%lf", &dsp);
    printf("density wood \n");
    scanf("%lf", &der);
    dvp = 0.005 * dvp;
    dsp = 0.015 * dsp;
    der = 0.01 * der;

    m = dvp * h * w + 2 * dsp * h * d + 2 * dsp * w * d + der * h * w;
    m = m + dsp * ((int)((h - 2 * 0.015) / (0.4 + 0.015))) * (w - 2 * 0.015) * (d - 0.005);
    printf("massa = %lf kg", m);
}
