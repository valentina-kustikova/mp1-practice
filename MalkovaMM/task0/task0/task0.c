#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	float x1, y1, r1, x2, y2, r2;
	setlocale(LC_ALL, "Rus");
	printf("������� ������ � �������: x1 y1 r1 x2 y2 r2");
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	float rast = sqrt(fabs(x1 - x2) * fabs(x1 - x2) + fabs(y1 - y2) * fabs(y1 - y2));
	if (r1 <= 0 || r2 <= 0)
	{
		printf("������������ ������");
		return 0;
	}
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("���������� ���������");
		return 0;
	}
	if (rast > r1 + r2)
	{
		printf("���������� �� ������������ � �� ����� ���� � �����");
		return 0;
	}
	if (rast == r1 + r2)
	{
		printf("���������� ������� ������� �������� � ����� �����");
		return 0;
	}
	if (rast + r1 < r2)
	{
		printf("������ ���������� ��������� ������ ������ � ��� �� �������� ���� �����");
		return 0;
	}
	if (rast + r2 < r1)
	{
		printf("������ ���������� ��������� ������ ������ � ��� �� �������� ���� �����");
		return 0;
	}
	if (rast + r1 == r2)
	{
		printf("������ ���������� ��������� ������ ������ � ��� �������� ���� ����� � ����� �����");
		return 0;
	}
	if (rast + r2 == r1)
	{
		printf("������ ���������� ��������� ������ ������ � ��� �������� ���� ����� � ����� �����");
		return 0;
	}
	printf("���������� ������������ � ���� ������");
	return 0;

}