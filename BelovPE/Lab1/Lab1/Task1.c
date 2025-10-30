#include <stdio.h>
#include <locale.h>

#define p_dvp 735 //��������� ���
#define p_dcp 800 //��������� ���
#define p_tree 700 //��������� ������(���)

int main(void) {
	double h, w, d;
	setlocale(LC_ALL, "");
	printf("������� ������, ������ � ������� ����� � �� � ��������� �������:\n");
	do {
		scanf_s("%lf", &h);
		if (h < 180 || h > 220) printf("������������ �������� ������ �����: 180-220 ��\n");
	} while (h < 180 || h > 220);

	do {
		scanf_s("%lf", &w);
		if (w < 80 || w > 120) printf("������������ �������� ������ �����: 80-120 ��\n");
	} while (w < 80 || w > 120);

	do {
		scanf_s("%lf", &d);
		if (d < 50 || d > 90) printf("������������ �������� ������� �����: 50-90 ��\n");
	} while (d < 50 || d > 90);

	double Mback_wall, Mrl_wall, Mhl_wall, Mdoors, Mshelves;
	Mback_wall = (((h * w) / 10000) * 0.005) * p_dvp;
	Mrl_wall = (((h * d) / 10000) * 0.015) * p_dcp * 2;
	Mhl_wall = ((((w * d) / 10000) * 0.015)) * p_dcp * 2;
	Mdoors = (((h * w) / 10000) * 0.01) * p_tree;
	Mshelves = (((((w - 3) * (d - 1.5)) / 10000) * 0.015)) * p_dcp * (((h - 3) / 40) - 1);

	printf("����� �����: %.3lf ��", Mback_wall + Mrl_wall + Mhl_wall + Mdoors + Mshelves);

	return 0;
}