#include <stdio.h>
#include <math.h>

int main() {
    float x1, y1, r1;
    float x2, y2, r2;
    float distance;

    printf("������ ����������\n");
    printf("����� X: ");
    scanf("%f = x1", &x1);
    printf("����� Y: ");
    scanf("y1 = %f", &y1);
    printf("������: ");
    scanf("r1 = %f", &r1);

    printf("������ ����������\n");
    printf("����� X: ");
    scanf("x2 = %f", &x2);
    printf("����� Y: ");
    scanf("y2 = %f", &y2);
    printf("������: ");
    scanf("r = %f", &r2);

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("������� ���������\n");
    printf("���������� 1: �����(%f, %f), R=%f\n", x1, y1, r1);
    printf("���������� 2: �����(%f, %f), R=%f\n", x2, y2, r2);
    printf("���������� ����� ��������: %.2f\n", distance);

    printf("���������\n");

    if (r1 <= 0 || r2 <= 0) {
        printf("������: ������ ������ ���� �������������!\n");
    }
    else if (distance == 0 && r1 == r2) {
        printf("���������� ���������\n");
    }
    else if (distance > r1 + r2) {
        printf("���������� �� ��������\n");
    }
    else if (distance == r1 + r2) {
        printf("���������� ������������� (������� �������)\n");
    }
    else if (distance + (r1 < r2 ? r1 : r2) < (r1 > r2 ? r1 : r2)) {
        printf("���� ���������� �������� � ���� ������\n");
    }
    else if (distance + (r1 < r2 ? r1 : r2) == (r1 > r2 ? r1 : r2)) {
        printf("���������� ������������� (���������� �������)\n");
    }
    else {
        printf("���������� ������������\n");
    }

    return 0;
}