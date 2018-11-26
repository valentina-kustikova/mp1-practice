#include <stdio.h>
#include <math.h>

#define E 0.00001

void main()
{
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0, r1 = 0, r2 = 0, R = 0;
    printf("Input x1,y1,r1,x2,y2,r2\n");
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2);

    if ((r1 <= 0) || (r2 <= 0))
    {
        printf("Imposible circle(s)\n");
        return;
    }

    R = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //Distance between centers of circles

    if ((R < E) && (r1 == r2))
    {
        printf("Circles are equal\n");
        return;
    }

    if ((R - r1 - r2) > E)
    {
        printf("Circles don't intersect, and don't lies one in the other\n");
        return;
    }

    if (fabs(R - r1 - r2) < E)
    {
        printf("Circles touches outside\n");
        return;
    }

    //From this moment r1+r2>R
    if (((R + r1 - r2) > E) && ((R + r2 - r1) > E)) 
    {
        printf("Circles intersect at two points\n");
        return;
    }

    if ((fabs(R + r1 - r2) < E) || (fabs(R + r2 - r1) < E)) 
    {
        printf("Circles touches inside\n");
        return;
    }

    if (((R + r1 - r2) < E) || ((R + r2 - r1) < E)) 
    {
        printf("One circle lie in the other\n");
        return;
    }
}
