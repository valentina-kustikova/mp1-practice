#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float x01, x11, y01, y11, x02, x12, y02, y12;
    scanf_s("%f %f %f %f %f %f %f %f", &x01, &x11, &y01, &y11, &x02, &x12, &y02, &y12);
    float r1 = sqrt(pow(x11 - x01, 2) + pow(y11 - y01, 2)); // длина радиуса первой окружности  
    float r2 = sqrt(pow(x12 - x02, 2) + pow(y12 - y02, 2)); // длина радиуса второй окружности  
    float p = sqrt(pow(x02 - x01, 2) + pow(y02 - y01, 2)); // Расстояние между центрами окружностей

    if (x01 == x02 && y01 == y02) {
        if (r1 == r2) {
            printf("Окружности совпадают\n");
        }
        else {
            printf("Окружности являются концентрическими\n");
        }
        return 0;
    }

    if (p > (r1 + r2)) {
        printf("Окружности не имеют общих точек\n");
    }
    else if (p == (r1 + r2)) {
        printf("Окружности касаются извне\n");
    }
    else {
        printf("Окружности пересекаются в 2х точках\n");
    }

    if (r1 > r2) {
        if (p == (r1 - r2)) {
            printf("Окружности касаются изнутри\n");
        }
    }
    else {
        if (p == (r2 - r1)) {
            printf("Окружности касаются изнутри\n");
        }
    }

    return 0;
}