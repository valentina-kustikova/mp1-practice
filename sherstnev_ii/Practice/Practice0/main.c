#include <stdio.h>
#include <math.h>

void main()
{
    float x1, y1, x2, y2, r1, r2, t;
    printf("Enter x1   ");
    scanf("%f", &x1);
    printf("\nEnter y1   ");
    scanf("%f", &y1);
    printf("\nEnter r1   ");
    scanf("%f", &r1);
    printf("\nEnter x2   ");
    scanf("%f", &x2);
    printf("\nEnter y2   ");
    scanf("%f", &y2);
    printf("\nEnter r2   ");
    scanf("%f", &r2);
    t = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
        printf("Circles match \n");
        return;
    }
    if (t > r1 + r2)
    {
        printf("Circles do not interact \n");
        return;
    }
    if (t == r1 + r2)
    {
        printf("Circles touch each other \n");
        return;
    }
    if ((r1 > t + r2) || (r2 > t + r1))
    {
        printf("One circle lies within another \n");
        return;
    }
    if ((r1 == t + r2) || (r2 == t + r1))
    {
        printf("One circle lies within another and touch it \n");
        return;
    }
    printf("Circles intersect \n");
}
