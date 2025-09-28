#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, r1, x2, y2, r2, d;
    scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
    if (r1 < 0 || r2 < 0) {
        printf("������������� �������");
        return 1;
    }
    d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (d > r1 + r2) {
        printf("����� ����� ���");
        return 0;
    }
    if (d == r1 + r2) {
        printf("������� �������");
        return 0;
    }
    if (d < fabs(r1 - r2)) {
        printf("���������� ����� � ����������");
        return 0;
    }
    if (d == fabs(r1 - r2)) {
        printf("���������� �������");
        return 0;
    }
    if (d < r1 + r2 && d > fabs(r1 - r2)) {
        printf("��� ����� �����");
        return 0;
    }
    if (r1 == r2 && x1 == x2 && y1 == y2) {
        printf("���������� ���������");
        return 0;
    }
}