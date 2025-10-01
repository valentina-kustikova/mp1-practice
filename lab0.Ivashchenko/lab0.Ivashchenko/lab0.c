#include <stdio.h>
#include <math.h>

int main()
{
    float x1, x2, y1, y2, r1, r2;
    scanf("%f, %f, %f, %f, %f, %f,", &x1, &x2, &y1, &y2, &r1, &r2);
    float d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));



    if (r1 <= 0 || r2 <= 0)
    {
        printf("Radius dolzhen bit polozhitelnim");
        return 1;
    }

    float d = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));


    if ((x1 == y1) && (y2 == x2) && (r1 == r2))
    {
        printf("Okruzhnosti sovpadauyt");
        return 0;
    }

    if (d > (r1 + r2))
    {
        printf("Okruzhnosti ne kasauytsya");
        return 0;

    }

    if (d == (r1 + r2))
    {
        printf("Okruzhnosti kasauytsya vneshnim obrazom");
        return 0;
    }

    if ((d < (r1 + r2)) && (d > fabs(r1 - r2)))
    {
        printf("Okruzhnosti peresekauytsya");
        return 0;
    }

    if (d == fabs(r1 - r2))
    {
        printf("Okruzhnosti kasauytsya vnutrennim obrazom");
        return 0;
    }

    if (d < fabs(r1 - r2))
    {
        printf("Odna okruzhnost vnutri drugoy bez kasaniya");
        return 0;
    }

