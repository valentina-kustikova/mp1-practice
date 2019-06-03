#include<stdio.h>
#include<math.h>
#include<locale.h>

void main()
{
    float x1, x2, y1, y2, r1, r2, l;
    setlocale(LC_ALL, "Rus");
    scanf("%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &r1, &r2);
    l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (r1 <= 0 || r2 <= 0)
    {
        printf("Радиус не может быть <= 0");
        return;
    }
    if ((l == 0) && (r1 == r2))
    {
        printf("Окружности совпадают");
        return;
    }
    if (l > r1 + r2)
    {
        printf("Одна окружность находится вне другой, не имеют общих точек");
        return;
    }
    if (l == r1 + r2)
    {
        printf("Окружности касаются внешне, имеют 1 общую точку (точка касания)");
        return;
    }
    if (l > r1 + r2)
    {
        printf("Одна окружность находится вне другой, не имеют общих точек");
        return;
    }
    if ((l == r1 - r2) || (l == r2 - r1))
    {
        printf("Окружности имеют внтуреннее касание");
        return;
    }
    if ((l < r1 - r2) || (l < r2 - r1))
    {
        printf("Одна окружность находится внтури другой");
        return;
    }
    printf("Окружности пересекаются, имеют 2 общие точки");
}
