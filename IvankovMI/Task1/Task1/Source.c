#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	float x1, x2, y1, y2, r1, r2;
	//setlocale(LC_CTYPE, "Russi�n");
	setlocale(LC_ALL, "Rus");
	//scanf_s("������� ���������� � ������ ������ ���������� (x y r): %f %f %f", &x1, &y1, &r1);
	//scanf_s("������� ���������� � ������ ������ ���������� (x y r): %f %f %f", &x2, &y2, &r2);
	printf("������� ���������� � ������ ������ ���������� (x y r):");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("������� ���������� � ������ ������ ���������� (x y r):");
	scanf_s("%f %f %f", &x2, &y2, &r2);
	if ((r1 == 0) || (r2 == 0)) { printf("������ �� ����� ���� �������"); return 1; }
	if ((x1 == x2) && (y1 == y2)) { printf("���������� �����"); return 0; }
	double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d > r1 + r2) { printf("���������� ������� ���� �� �����"); return 0; }
	if (d == r1 + r2) { printf("���������� ������ �������� ���� �����"); return 0; }
	float rma = (r1 > r2) ? r1 : r2;
	float rmi = (r1 < r2) ? r1 : r2;
	if (d > rma) { printf("���������� ������ ������������"); return 0; }
	if (d == rma) { printf("���������� ������������, ����� ����� �� ��� ����� �� ������"); return 0; }
	if (d + rmi == rma) { printf("���������� ��������� �������� ���� �����"); return 0; }
	if (d + rmi > rma) { printf("���������� ��������� ������������"); return 0; }
	printf("���� ���������� ��������� ������ ������"); return 0;
}