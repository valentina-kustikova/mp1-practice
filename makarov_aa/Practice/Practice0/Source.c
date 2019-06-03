#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
    double x1, y1, r1, x2, y2, r2, o;
    setlocale(LC_ALL, "Russian");
    printf("Введите х координату центра первой окружности \n");
    scanf("%lf", &x1);
    printf("Введите у координату центра первой окружности \n");
    scanf("%lf", &y1);
    printf("Введите радиус первой окружности \n");
    scanf("%lf", &r1);
    printf("Введите х координату центра второй окружности \n");
    scanf("%lf", &x2);
    printf("Введите у координату центра второй окружности \n");
    scanf("%lf", &y2);
    printf("Введите радиус второй окружности \n");
    scanf("%lf", &r2);
    o = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    //квадрат расстояния для упрощения условий
    if ((r1 == r2) && (o == 0))
    {
        printf("Совпадают");
        return;
    }
    if (o == (r1 + r2) * (r1 + r2))
    {
        printf("Касаются снаружи");
        return;
    }
    if (o == (r1 - r2) * (r1 - r2))
    {
        printf("Одна касается другой изнутри");
        return;
    }
    if (o < (r1 - r2) * (r1 - r2))
    {
        printf("Одна окружность в другой без касания");
        return;
    }
    if (o > (r1 + r2) * (r1 + r2))
    {
        printf("Не пересекаются");
        return;
    }
    printf("Пересекаются");
}