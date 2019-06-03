#include <stdio.h>
#include <math.h>
void main()
{
    double h, w, d, p1, p2, p3, m1, m2, m3, m4, m;
    printf ("Enter the height (from 180 to 220 cm), width (from 80 to 120 cm) and depth (from 50 to 90 cm) of the Cabinet in centimeter\n");
    scanf ("%lf %lf %lf", &h, &w, &d);
    if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
    {
        printf ("Incorrect data");
        return;
    }
    h = h * 0.01;
    w = w * 0.01;
    d = d * 0.01;
    printf ("Enter the density of fiberboard, chipboard and wood in kg / m^3\n");
    scanf ("%lf %lf %lf", &p1, &p2, &p3);
    m1 = p1 * h * w * 0.005;
    m2 = 2 * p2 * d * 0.015 * (h + w);
    m3 = p3 * h * w * 0.01;
    m4 = ((int)((h - 2 * 0.015) / (0.4 + 0.015))) * (w - 2 * 0.015) * (d - 0.005);
    m = m1 + m2 + m3 + m4;
    printf ("Cabinet weight - %lf", m);
}
