#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    float x01, x11, y01, y11, x02, x12, y02, y12;
    scanf_s("%f %f %f %f %f %f %f %f", &x01, &x11, &y01, &y11, &x02, &x12, &y02, &y12);
    float r1 = sqrt(pow(x11 - x01, 2) + pow(y11 - y01, 2)); // ����� ������� ������ ����������  
    float r2 = sqrt(pow(x12 - x02, 2) + pow(y12 - y02, 2)); // ����� ������� ������ ����������  
    float p = sqrt(pow(x02 - x01, 2) + pow(y02 - y01, 2)); // ���������� ����� �������� �����������

    if (x01 == x02 && y01 == y02) {
        if (r1 == r2) {
            printf("���������� ���������\n");
        }
        else {
            printf("���������� �������� ����������������\n");
        }
        return 0;
    }

    if (p > (r1 + r2)) {
        printf("���������� �� ����� ����� �����\n");
    }
    else if (p == (r1 + r2)) {
        printf("���������� �������� �����\n");
    }
    else {
        printf("���������� ������������ � 2� ������\n");
    }

    if (r1 > r2) {
        if (p == (r1 - r2)) {
            printf("���������� �������� �������\n");
        }
    }
    else {
        if (p == (r2 - r1)) {
            printf("���������� �������� �������\n");
        }
    }

    return 0;
}