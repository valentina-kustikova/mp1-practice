#include <stdio.h>
#include <math.h>

void main()
{
    double x1, y1, x2, y2, r1, r2, d;
    printf("VVedite coordinaty i radius pervoy okruzhnosti \n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    if (r1 < 0)
    {
        printf("Radius okruzhnosty - otritsatel'noe chislo \n");
        return;
    }
    printf("VVedite coordinaty i radius vtoroy okruzhnosti \n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if (r1 < 0)
    {
        printf("Radius okruzhnosty - otritsatel'noe chislo \n");
        return;
    }
    d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    if (d > (r2 + r1))
    {
        printf("Okruzhnosty ne peresekayuts'a \n");
        return;
    }
    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
        printf("Okruzhnosti sovpadayut \n");
        return;
    }
    if (d == (r2 + r1))
    {
        printf("Okruzhnosty vneshne kasayuts'a \n");
        return;
    }
    if ((d + r2 < r1) || (d + r1 < r2))
    {
        printf("Odna Okruzhnost' vhodit v druguyu \n");
        return;
    }
    if ((d + r2 == r1) || (d + r1 == r2))
    {
        printf("Odna okruzhnost' vnutrnne kasaets'a drugoy \n");
        return;
    }
    if ((d - r1 < r2) || (d - r2 < r1))
    {
        printf("Okruzhnosty peresekayuts'a \n");
        return;
    }
}
