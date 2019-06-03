#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
    float r1, r2, x1, x2, y1, y2, d;
    setlocale(LC_ALL, "Rus");
    printf("Введите координаты центра 1ой окружности и её радиус\n");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Введите координаты центра 2ой окружности и её радиус\n");
    scanf("%f %f %f", &x2, &y2, &r2);
    d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if ((r1 == r2) && (x1 == x2) && (y1 == y2))
    {
        printf("Окружности совпадают\n");
        return;
    }
    if (d > (r1 + r2))
    {
        printf("Окружности лежат поодаль и не имеют общих точек\n");
        return;
    }
    if (d == (r1 + r2))
    {
        printf("Окружности касаются внешним образом\n");
        return;
    }

    if (d == (fabsf(r1 - r2)))
    {
        printf("Окружности касаются внутренним образом\n");
        return;
    }
    if (d < (fabsf(r1 - r2)))
    {
        printf("Окружность лежит внутри окружности \n");
        return;
    }

    if ((d < (r1 + r2)) && (d > (fabsf(r1 - r2))))
    {
        printf("Окружности пересекаются\n");
        return;
    }
}
