#include <stdio.h>
#define t 0.015
#define pd 700
#define pdsp 800
#define pdvp 735
int main() {
	double mass, h, w, d, m1, m2, m3, m4, m5, copy;
	int k = 0;

	printf("������� ������, ������ � ������� �����");
	do {
		scanf_s("%f %f %f", &h, &w, &d);
	} while (!(h >= 180 && h <= 220 && w >= 80 && w <= 120 && d >= 50 && d <= 90));

	m1 = h * w * pdvp * 0.005;    //������ ������
	m2 = 2 * (h - 2 * t) * (d - 0.01) * t * pdsp;    //��������
	m3 = 2 * w * d * t * pdsp;    //������
	m4 = h * w * pd * 0.01;       //������
	//k = int((int(h * 1000)) / 415)
	copy = h;
	while (copy >= 0.415) {
		copy -= 0.4;
		k++;
	}
	k--;
	m5 = k * (w - t * 2) * (d - 0.01) * t * pdsp;  //�����
	printf("����� ������ ����� = %f", m1 + m2 + m3 + m4 + m5);
	printf("����� � ��� %d", k);
	return 0;
}