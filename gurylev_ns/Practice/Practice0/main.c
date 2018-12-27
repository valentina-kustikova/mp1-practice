#include <stdio.h>
#include <math.h>

void main()
{
    float x1, y1, r1, x2, y2, r2, d;
    scanf("%f%f%f", &x1, &y1, &r1);
    scanf("%f%f%f", &x2, &y2, &r2);
    scanf("%f", &d);

    if ((r1 == r2) && (x1 == x2) && (y1 == y2))
    {
        printf("Circles match");
        return;
    }
    if (d == (r1 + r2))
    {
        printf("Circles intersect at one point");
        return;
    }

    if (d > r1 + r2)
    {
        printf("Circles do not intersect");
        return;
    }

    if (d > (r1 - r2) && d < (r1 + r2))
    {
        printf("Circles intersect at two points");
        return;
    }

    if (d > (r1 - r2) && d > (r2 - r1))
    {
        printf("The circle is in the circle");
        return;
    }
}