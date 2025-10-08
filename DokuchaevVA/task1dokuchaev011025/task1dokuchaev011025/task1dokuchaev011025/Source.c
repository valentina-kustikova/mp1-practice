#include <stdio.h>
#include <locale.h>
int main() {
	float h, w, d, massa1, massa2, massa3, massa4, massa5, massa, n;
	float der = 700.f, dsp = 800.f, dvp = 735.f, tder = 10.f, tdsp = 15.f, tdvp = 5.f;
	setlocale(LC_ALL, "Rus");

	do
	{
		printf_s("������� �������� ������ ����� H (� ��, 180-220)\n");
		scanf_s("%f", &h);
	} while ((h < 180.f) || (h > 220.f));
	h = h * 10.f;

	do
	{
		printf_s("������� �������� ������ ����� W (� ��, 80-120)\n");
		scanf_s("%f", &w);
	} while ((w < 80.f) || (w > 120.f));
	w = w * 10.f;	

	do
	{
		printf_s("������� �������� ������� ����� D (� ��, 50-90)\n");
		scanf_s("%f", &d);
	} while ((w < 80.f) || (d > 90.f));
	d = d * 10.f;

	n = ((h / 10.f)/40)-1;
	n=(int)n;

	massa1 = (h+30) * tdvp * w * dvp / 1000000000.0f; //����� ������ ������
	massa2 = h * tdsp * d * dsp / 1000000000.0f * 2.f;//������� ������
	massa3 = w * d * dsp * tdsp / 1000000000.0f * 2.f;// ��� � �������
	massa4 = w * (h+30) * tder * der / 1000000000.0f;// �����
	massa5 = (w - 2.f*tdsp) * d * dsp * tdsp * n / 1000000000.0f;
	massa = massa1 + massa2 + massa3 + massa4 + massa5;
	printf("����� ����� = %.1f ��\n\n\n", massa);
	printf("������ ������ ������ = %.1f ��\n", massa1);
	printf("����� ������� ������ = %.1f ��\n", massa2);
	printf("����� ��� � ������� = %.1f ��\n", massa3);
	printf("����� ������ = %.1f ��\n", massa4);
	printf("����� ����� � �� ����������= %.1f ��, %.0f\n", massa5, n);
	return 0;
}