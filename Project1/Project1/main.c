#include <stdio.h>
#include <math.h>
#include <locale.h>
int main() {
	float r1,r2,x1,x2,y1,y2,rast;
	setlocale(LC_ALL, "Russian");
	printf("������� ������ ������ ����������:");
	scanf_s("%f", &r1);
	printf("������� ������ ������ ����������:");
	scanf_s("%f", &r2);
	printf("������� ���������� ������ ����������:");
	scanf_s("%f %f", &x1,&y1);
	printf("������� ���������� ������ ����������:");
	scanf_s("%f %f", &x2,&y2);
	rast = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (rast > r1 + r2) {
		printf("���������� ����������� ������� ������� � �� ��������");
		return 0;
	}
	if (rast == r1 + r2) {
		printf("���������� �������� ������� �������");
		return 0;
	}
	if ((rast > fabsf(r1 - r2)) && (rast < r1 + r2)) {
		printf("���������� ������������ � 2 ������");
		return 0;
	}
	if ((rast == 0.0) && (r1 == r2)) {
		printf("���������� ���������(���� ����������)");
		return 0;
	}
	if (rast == fabsf(r1 - r2)) {
		printf("�������� ���������� �������");
		return 0;
	}
	if ((rast < fabsf(r1 - r2))&&(rast!=0.0)) {
		printf("���������� ����������� ���������� ������� � �� ��������(������ �� ���������)");
		return 0;
	}
	if ((rast == 0.0) && (r1 != r2)) {
		printf("���������� ����������� ���������� ������� � �� ��������(������ ���������)");
		return 0;
	}
	return 0;
}