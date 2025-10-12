#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_ALL, "Russian");
	float dvp = 800.f, dsp = 735.f, der = 700.f, t_bvn = 0.015f, t_zad = 0.005f, t_dver = 0.01f, h, d, w,ves,k;
	
	do{
		printf("������� ������ ����� �� 180 �� 220 �� ������������:");
		scanf_s("%f", &h);
		if (h > 220.f) {
			printf("����� ������ ���� ������ 220\n");
		}
		if (h < 180.f) {
			printf("����� ������ ���� ������ 180\n");
		}
	} while ((h > 220.f) || (h < 180.f));
	do {
		printf("������� ������ ����� �� 80 �� 120 �� ������������:");
		scanf_s("%f", &w);
		if (w > 120.f) {
			printf("����� ������ ���� ������ 120\n");
		}
		if (w < 80.f) {
			printf("����� ������ ���� ������ 80\n");
		}
	} while ((w > 120.f) || (w < 80.f));
	do {
		printf("������� ������� ����� �� 50 �� 90 �� ������������:");
		scanf_s("%f", &d);
		if (d > 90.f) {
			printf("����� ������ ���� ������ 90\n");
		}
		if (d < 50.f) {
			printf("����� ������ ���� ������ 50\n");
		}
	} while ((d > 90.f) || (d < 50.f));
	if (fmodf(h, 40.f) == 0) {
		k = h / 40.f - 1.f;
	}
	else {
		k = floorf(h / 40.f);
	}
	printf("���-�� �����:%f\n", k);
	ves = dvp * ((h/100.f) * (w/100.f) * t_zad) + 2.f * dsp * ((h/100.f) * (d/100.f)  * t_bvn) + 2.f * dsp * ((w/100.f) * (d/100.f)  * t_bvn) + (der * ((h/100.f) * (w/100.f) * t_dver)) + k * dsp*((w/100.f-2.f*t_bvn) * (d/100.f) * t_bvn);
	printf("��� �����:%f kg\n", ves);
	return 0;
}