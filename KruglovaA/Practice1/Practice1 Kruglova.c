#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	double h, w, d, tsten, tbok, tkrysh, tdver, tpolk, dvp, dsp, der;
	tsten = 5.0 / 1000.0; //������� ������ ������
	tbok = 15.0 / 1000.0; // ������� ������� ������
	tkrysh = 15.0 / 1000.0; // ������� ������ ������� � ������
	tdver = 1.0 / 1000.0; // ������� �����
	tpolk = 15.0 / 1000.0;
	dvp = 300;
	dsp = 550;
	der = 520;//��������� �����

	do {
		printf("������� �������� h, w � d :");
		scanf("%lf %lf %lf", &h, &w, &d);
		if ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)) {
			printf("������ �������� �������, ��������� ����\n");
		}
	} while (((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)));
	double v1, m1, v2, m2, v3, m3, v4, m4, v5, m5;
	h = h / 100.0;
	w = w / 100.0;
	d = d / 100.0;
	v1 = h * w * tsten; //����� ������ ������
	v2 = (h * d * tbok) * 2; // ����� ���� ������� ������
	v3 = (w * d * tkrysh) * 2; // ����� ������
	v4 = (h * w * tdver); // ����� ������
	v5 = (d * (w - 2 * tbok) * tpolk); //����� ����� �����
	m1 = dvp * v1;
	m2 = dsp * v2;
	m3 = dsp * v3;
	m4 = der * v4;
	m5 = dsp * v5;
	double res = 40.0;
	res = 40.0 / 100.0;
	double kolpol;
	kolpol = (h / (res + tpolk));
	double RES;
	RES = m1 + m2 + m3 + m4 + m5 * kolpol;
	printf("��������� �����: %lf", RES);
	return 0;
}