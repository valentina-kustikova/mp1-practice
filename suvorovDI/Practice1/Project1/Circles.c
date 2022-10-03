#include <stdio.h>
#include <math.h>

int main() {
    /*
        2е окружности задаются координатами центра и радиусами - определите взаимное расположение окружностей
        1.
    */
    double x1, x2, y1, y2, r1, r2, d;
    scanf_s("%lf%lf%lf%lf%lf%lf", &x1, &x2, &y1, &y2, &r1, &r2);

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (d == 0) {
        if (r1 == r2) {
            printf("the same circles");
        }
        else {
            printf("one circle into other and there is no touching");
        }
    }
    else if (d > (r1 + r2)) {
        printf("circles do not touch");
    }
    else if (d == (r1 + r2)) {
        printf("circles touch at one point and no circle is inside the other ");
    }
    else { //расстояние между центрами меньше чем сумма их радиусов
        if (d == fabs(r1 - r2)) {
            printf("circles touch at one point and one of circles is inside the other");
        }
        else if (d < fabs(r1 - r2)) {
            printf("one of circles is inside the other and no touching");
        }
        else {
            printf("2 points");
        }
    }

    return 0;
}