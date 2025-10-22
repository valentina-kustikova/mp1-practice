#include <stdio.h>
#include <locale.h>
#define t 0.015
#define pd 700  // kg/m3
#define pdsp 800
#define pdvp 735
int main() {
	double mass, h, w, d, m1, m2, m3, m4, m5;
	int k = 0, hi, wi, di;                     //������������ ������������� ��������� h, w, d, � � �� ���������� ���������� �� ����������� < � >
	setlocale(LC_ALL, "Rus");

	do {
		printf("������� ������, ������ � ������� ����� ����� ������\n");
		scanf_s("%d %d %d", &hi, &wi, &di);
		if ((hi < 180) || (hi > 220) || (wi < 80) || (wi > 120) || (di < 50) || (di > 90))
			printf("������ ����������\n");
	} while ((hi < 180) || (hi > 220) || (wi < 80) || (wi > 120) || (di < 50) || (di > 90));
	h = hi;
	w = wi;
	d = di;
	h /= 100;                                                         printf("h = %f m\n", h);       //m
	w /= 100;                                                         printf("w = %f m\n", w);
	d /= 100;                                                         printf("d = %f m\n", d);
	m1 = h * w * pdvp * 0.005;                                        printf("m1 = %f kg\n", m1);    //������ ������     ( m*m*m * (kg/m3) = kg)
	m2 = 2 * (h - 2 * t) * (d - 0.01) * t * pdsp;                     printf("m2 = %f kg\n", m2);    //��������
	m3 = 2 * w * d * t * pdsp;                                        printf("m3 = %f kg\n", m3);    //������
	m4 = h * w * pd * 0.01;                                           printf("m4 = %f kg\n", m4);    //������
	k = (hi <= 202) ? 4 : 5;
	m5 = k * (w - t * 2) * (d - 0.01) * t * pdsp;                     printf("m5 = %f kg\n", m5);    //�����
	printf("\n����� ������ ����� = %f kg\n", m1 + m2 + m3 + m4 + m5);
	printf("����� � ��� %d\n", k);
	return 0;
}