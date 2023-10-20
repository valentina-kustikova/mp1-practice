#include <stdio.h>

int main()

{
    double h, w, d, m1, m2, m3, m4, m5, colvopolk = 5, m;

    do {

        printf("Input height, depth,  width of the wardrobe ");

        scanf("%lf %lf %lf", &h, &d, &w);

    } while ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90));

    h -= 3;

    if (h <= 206) {

        colvopolk = 4;

    }

    m1 = d * w * 1.5 * 2 * 0.65;

    m2 = h * d * 1.5 * 2 * 0.65;

    m3 = (h + 3) * w * 0.66;

    m4 = colvopolk * d * (w - 3) * 0.65;

    m5 = h * w * 0.5 * 0.75;

    m = (m1 + m2 + m3 + m4 + m5) / 1000;

    printf("Weight of your wardrode in kg: %lf", m);

    return 0;
}