#include <stdio.h> 
#include <math.h> 

void main()
{
    double x1, x2, y1, y2, r1, r2, d;
    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    scanf("%lf %lf", &r1, &r2);
    if ((d == 0) && (r1 == r2))
    {
        printf("Okruzhnosti sovpadaut");
        return;
    }
    if (d < abs(r1 - r2))
    {
        printf("Odna okruzhnost lezhit v drugoi");
        return;
    }
    if ((d == abs(r1 - r2)) && (r1 != r2))
    {
        printf("Odna okruzhnost kasaetsya drugoi vnutrennim obrazom");
        return;
    }
    if (d == (r1 + r2))
    {
        printf("Odna okruzhnost kasaetsya drugoi vneshnim obrazom");
        return;
    }
    if (d > (r1 + r2))
    {
        printf("Okruzhnosty ne peresekautsya");
        return;
    }
    if (d < (r1 + r2) && d > abs(r1 - r2))
    {
        printf("Okruzhnosty peresekautsya");
    }
}
