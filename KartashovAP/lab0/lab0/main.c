#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float raznost_radiusov, R_center, centrX1, centrX2, centrY1, centrY2, r1, r2;
	setlocale(LC_ALL, "Russian");
	printf("�����1 (x y), �����2 (x y), ������1, ������2\n");
	scanf_s("%f %f %f %f %f %f", &centrX1, &centrY1, &centrX2, &centrY2, &r1, &r2);
	R_center = sqrtf((centrX2 - centrX1) * (centrX2 - centrX1) + (centrY2 - centrY1) * (centrY2 - centrY1));
	if (r1 > r2)
		raznost_radiusov = r1 - r2;
	else
		raznost_radiusov = r2 - r1;
	if (R_center == 0 && r1 == r2)
		printf("���������� ���������\n");
	else if (R_center > r1 + r2)
		printf("���������� �� ������������\n");
	else if (R_center == r1 + r2)
		printf("���������� �������� � 1-�� �����\n");
	else if (R_center > raznost_radiusov && R_center < r1 + r2)
		printf("���������� ������������ � ���� ������\n");
	else if (R_center == raznost_radiusov && R_center > 0)
		printf("���� ���������� ��������� ������ ������ � �������� �������\n");
	else if (R_center < raznost_radiusov)
		printf("���� ���������� ��������� ������ ������ � �� �������� �������\n");
	return 0;
}