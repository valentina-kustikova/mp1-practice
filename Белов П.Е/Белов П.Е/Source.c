#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, r1;
    float x2, y2, r2;
    float distance;

    printf("Первая окружность\n");
    printf("Центр X: ");
    scanf("%f = x1", &x1);
    printf("Центр Y: ");
    scanf("y1 = %f", &y1);
    printf("Радиус: ");
    scanf("r1 = %f", &r1);

    printf("Вторая окружность\n");
    printf("Центр X: ");
    scanf("x2 = %f", &x2);
    printf("Центр Y: ");
    scanf("y2 = %f", &y2);
    printf("Радиус: ");
    scanf("r = %f", &r2);

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("Система координат\n");
    printf("Окружность 1: Центр(%f, %f), R=%f\n", x1, y1, r1);
    printf("Окружность 2: Центр(%f, %f), R=%f\n", x2, y2, r2);
    printf("Расстояние между центрами: %.2f\n", distance);

    printf("Результат\n");

    if (r1 <= 0 || r2 <= 0) {
        printf("Ошибка: радиус должен быть положительным!\n");
    }
    else if (distance == 0 && r1 == r2) {
        printf("Окружности совпадают\n");
    }
    else if (distance > r1 + r2) {
        printf("Окружности не касаются\n");
    }
    else if (distance == r1 + r2) {
        printf("Окружности соприкасаются (внешнее касание)\n");
    }
    else if (distance + (r1 < r2 ? r1 : r2) < (r1 > r2 ? r1 : r2)) {
        printf("Одна окружность включает в себя другую\n");
    }
    else if (distance + (r1 < r2 ? r1 : r2) == (r1 > r2 ? r1 : r2)) {
        printf("Окружности соприкасаются (внутреннее касание)\n");
    }
    else {
        printf("Окружности пересекаются\n");
    }

    return 0;
}