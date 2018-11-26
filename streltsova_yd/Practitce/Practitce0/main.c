#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
    double x1, y1, r1, x2, y2, r2, d;
    setlocale(LC_ALL, "Russian");
    printf("Введите координаты и радиус первой окружности\n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Введите координаты и радиус второй окружности\n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
        printf("Окружности совпадают\n");
        return;
    }
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if ((r1 + r2) < d)
    {
        printf("Окружности не пересеккются\n");
        return;
    }
    if ((r1 + r2) == d)
    {
        printf("Окружности касаются внешним образом\n");
        return;
    }
    if (d == abs(r1 - r2))
    {
        printf("Окружности касаются внутренним образом\n");
        return;
    }
    if (d < abs(r1 - r2))
    {
        printf("Одна окружность лежит внутри другой\n");
        return;
    }
    printf("Окружности пересекаются в двух точках\n");
}
