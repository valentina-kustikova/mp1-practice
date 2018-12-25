#include <stdio.h>
#include <math.h>

void main()
{
    float x1, y1, x2, y2, r1, r2;
    double d;
    printf("Vvedite koordinati chentra i radius 1 okr");
    scanf("%f%f%f", &x1, &y1, &r1);
    printf("Vvedite koordinati chentra i radius 2 okr");
    scanf("%f%f%f", &x2, &y2, &r2);
    if ((r1 <= 0) || (r2 <= 0))
    {
        printf("Oshibka");
        return;
    }
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d == (r1 + r2))
    {
        printf("Kasayutsya vneshne");
        return;
    }
    if (d == (r1 - r2))
    {
        printf("Kasayutsya vnytri");
        return;
    }
    if ((d > (r1 - r2)) && (d < (r1 + r2)))
    {
        printf("Peresekayutsya");
        return;
    }
    if ((d < (r1 - r2)) && (d >(r1 + r2)))
    {
        printf("Ne peresekayutsya");
        return;
    }
}
