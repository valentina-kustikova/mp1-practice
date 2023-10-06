#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
    double x1, x2, y1, y2, r1, r2;
    int flag;

    setlocale(LC_ALL, "Rus");
    printf("Input x1,y1,r1: ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);

    printf("Input x2,y2,r2: ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);
    flag = 0;
    if (r1 <= 0)
    {
        printf("Неправильный радиус 1\n");
        flag++;
    }
    if (r2 <= 0)
    {
        printf("Неправильный радиус 2\n");
        flag++;
    }
    if (flag > 0)
    {
        return 0;               
    }

    printf(" \n");
    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
        printf("окружности совпадают\n");
    }
    else if (r1 + r2 < sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))
    {
        printf("окружности не пересекаются\n");
    }
    else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) < abs(r1 - r2))
    {
        printf("окружности вложены\n");
    }
    else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == r2 + r1)
    {
        printf("окружности касаются(внешним образом)\n");
    }
    else if (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) == abs(r2 - r1))
    {
        printf("окружности касаются(внутренним образом)\n");
    }
    else
    {
        printf("окружности пересекаются\n");
    }
    return 0;
}

//Формула для расстояния между точками: sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))