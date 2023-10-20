#include <stdio.h>
int main()
{
    double h, w, d, V1, m1, V2, m2, V3, m3, V4, m4, V5, m5;
    double tolsina1 = 0.005;
    double tolsina2 = 0.015;
    double tolsina3 = 0.01;
    double DVP = 950;
    double DSP = 650;
    double wood = 660;
    int k = 0;
    int t = 0;
    printf("Input h,w,d in meters: ");
    do {
        t = 0;
        scanf("%lf %lf %lf", &h, &w, &d);
        if ((h < 1.80) || (h > 2.20) || (w < 0.80) || (w > 1.20) || (d < 0.50) || (d > 0.90)) {
            t = 1;
        }
    } while (t);
    V1 = h * w * tolsina1;//накладна€ задн€€ степна
    m1 = DVP * V1;
    V2 = 2 * (h * d * tolsina2);//2 боковины
    m2 = V2 * DSP;
    V3 = 2 * (w * d * tolsina2);//верхн€€ и нижн€€ крышки
    m3 = V3 * DSP;
    V4 = h * w * tolsina3;//накладные двери
    m4 = V4 * wood;
    V5 = (w - 0.03) * d * tolsina2;//одна полка
    while (h >= 0.4) {
        h = h - 0.4 - 0.015;
        k++;
    }
    m5 = DSP * V5 * k;
    printf("Weight:%lf\n", (m1 + m2 + m3 + m4 + m5));
    return 0;
}
