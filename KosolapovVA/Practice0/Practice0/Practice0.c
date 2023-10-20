#include <stdio.h>
#include <math.h>


int main()
{
    double x1, x2 ,y1, y2, r1, r2;
    printf("Input coordinate 1st circle  and radius:");
    scanf(" %lf, %lf, %lf", &x1, &y1, &r1);
    if (r1 <= 0)
    {
        printf("radius 1st circle is incorrect");
        return 0;
    }
    printf("x=%lf, y=%lf, r=%lf \n", x1, y1, r1);
    printf("Input coordinate 2nd circle and radius:");
    scanf(" %lf, %lf, %lf", &x2, &y2, &r2);
    if (r2 <= 0)
    {
        printf("radius 2nd circle is incorrect");
        return 0;
    }
    printf("x=%lf, y=%lf, r=%lf \n", x2, y2, r2);
    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    { 
        printf("Circle match");
        return 0;
    }
    double distance, a,b;
    a = x1 - x2;
    b = y1 - y2;
    distance = sqrt(a * a + b * b);
    printf("Distance=%lf \n", distance);
    if (distance > r1 + r2)
    {
        printf("Circles have not general dots");
    }
    else if (distance == r1 + r2)
    {
        printf("Circles have one general dots");
    }
    else if (distance == abs(r2 - r1))
    {
        printf("Circles have one general dots and circle in circle");
    }
    else if (distance < abs(r2 - r1))
    {
        printf("Circle in circle");
    }
    else
    {
        printf("Circles have two general dots");
    }
    return 0;
}
