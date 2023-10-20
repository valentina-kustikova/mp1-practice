#include <stdio.h>
#include <math.h>
int main()
{
    double x1, y1, r1, x2, y2, r2, d;
    printf("Input radius and coordinates for 1st circle x1, y1, r1\n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    if (r1 <= 0)
    {
        printf("Invalid radius r1 value");
        return 0;
    }
    printf("Input radius and coordinates for 2nd circle x2, y2, r2\n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if (r2 <= 0)
    {
        printf("Invalid radius r2 value");
        return 0;
    }
    d = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
        printf("The circles coincide with each other");
        return 0;
    }
    if (d > (r1 + r2))
    {
        printf("The circles are separated");
        return 0;
    }
    if ((0 <= d) && (d < (r1 - r2)))
    {
        printf("The first circle inside second");
        return 0;
    }
    if (d == (r1 + r2) && (r1 != r2))
    {
        printf("The circles touch each other in one dot");
        return 0;
    }
    if (d == (r1 - r2) && (r1 != r2))
    {
        printf("The circles touch each other in one dot");
        return 0;
    }
    printf("The circles are crossed");

    return 0;

}