#include <stdio.h>

int main() {
    float x1, y1, r1, x2, y2, r2, s;
    printf("Enter coordinates and radius of first circle\n");
    scanf_s("%f %f %f", &x1, &y1, &r1);
    printf("Enter coordinates and radius of second circle\n");
    scanf_s("%f %f %f", &x2, &y2, &r2);

    if ((r1 < 0) || (r2 < 0)) {
        printf("negative radiuses");
        return 1;
    }

    // расстояние между центрами окружностей
    s = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
            printf("circles match");
            return 0;
        }

    if (s > r1 + r2) {
        printf("circles don't intersert");
        return 0;
    }

    if ((s < r2 - r1) || (s < r1 - r2)) {
        printf("one circle in ohter circle");
        return 0;
    }

    if (s == r1 + r2) {
        printf("circles kasautsa vneshnim obrazom");
        return 0;
    }

    if ((s == r2 - r1) || (s == r1 - r2)) {
        printf("circles kasautsa vnutrennim obrazom");
        return 0;
    }

    printf("circles intersect");
    return 0;

}

