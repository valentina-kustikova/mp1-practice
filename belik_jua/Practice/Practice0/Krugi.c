#include <stdio.h>
#include <math.h>

void main()
{
    double x1, x2, r1, y2, y1, r2, d;
    printf("x1 -? y1 -? r1 -? \n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("x2 -? y2 -? r2 -? \n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if ((d == 0) && (r1 == r2))
    {
        printf("sovpadaut");
        return;
    }
    if (d < fabs(r1 - r2))
    {
        printf("1 vnutri drugogo");
        return;
    }
    if (d == fabs(r1 - r2))
    {
        printf("vnutrennee kasanie");
        return;
    }
    if (d == (r1 + r2))
    {
        printf("vneshnee kasanie");
        return;
    }
    if (d > (r1 + r2))
    {
        printf("ne peresekautsya");
        return;
    }
    printf("peresekautsya");
}
