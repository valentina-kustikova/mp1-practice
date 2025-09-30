#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "RU");
	double x1, y1, r1;
	double x2, y2, r2;
	double distance;

	printf("������� ���������� x1 � y1 � ������ r1: ");
	scanf_s("%lf %lf %lf", &x1, &y1, &r1);

	printf("������� ���������� x2 � y2 � ������ r2: ");
	scanf_s("%lf %lf %lf", &x2, &y2, &r2);

	if (r1 < 0 || r2 < 0) {
		printf("������ ������ ���� �������������");
		return 1;
	}

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	if (distance > r1 + r2) {
		printf("���������� �� ������������\n");
	}
	else if (distance < fabs(r1 - r2)) {
		printf("���� ���������� ������ ������\n");
	}
	else if (distance == 0 && r1 == r2) {
		printf("���������� ���������\n");
	}

	else if (distance == r1 + r2 || distance == fabs(r1 - r2)) {
		printf("���������� ����� ���� ����� �������\n");
	}

	else {
		printf("���������� ������������\n");
	}
	return 0;
}