#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "Russian");
	float dvp = 800.0, dsp = 735.0, der = 700.0, t_bvn = 0.015, t_zad = 0.005, t_dver = 0.01, h, d, w,ves,k;
	
	do{
		printf("������� ������ ����� �� 180 �� 220 �� ������������:");
		scanf_s("%f", &h);
		if (h > 220) {
			printf("����� ������ ���� ������ 220\n");
		}
		if (h < 180) {
			printf("����� ������ ���� ������ 180\n");
		}
	} while ((h > 220) || (h < 180));
	do {
		printf("������� ������ ����� �� 80 �� 120 �� ������������:");
		scanf_s("%f", &w);
		if (w > 120) {
			printf("����� ������ ���� ������ 120\n");
		}
		if (w < 80) {
			printf("����� ������ ���� ������ 80\n");
		}
	} while ((w > 120) || (w < 80));
	do {
		printf("������� ������� ����� �� 50 �� 90 �� ������������:");
		scanf_s("%f", &d);
		if (d > 90) {
			printf("����� ������ ���� ������ 90\n");
		}
		if (d < 50) {
			printf("����� ������ ���� ������ 50\n");
		}
	} while ((d > 90) || (d < 50));
	if (fmodf(h, 40) == 0) {
		k = h / 40 - 1;
	}
	else {
		k = floorf(h / 40);
	}
	printf("���-�� �����:%f\n", k);
	ves = dvp * ((h/100) * (w/100) * t_zad) + 2 * dsp * ((h/100) * (d/100)  * t_bvn) + 2 * dsp * ((w/100) * (d/100)  * t_bvn) + 2 * der * ((h/100) * (w/100) * t_dver) + k * dsp*((w/100) * (d/100) * t_bvn);
	printf("��� �����:%f kg\n", ves);
	return 0;
}