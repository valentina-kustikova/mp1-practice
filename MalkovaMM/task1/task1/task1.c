#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float h, w, d, x;
	float m, dvp, dsp, der;
	do
	{
		printf("������� ������ ����� 180-220 ��: ");
		scanf_s("%f", &h);
	} while ((h < 180.f) || (h > 220.f));
	do
	{
		printf("������� ������ ����� 80-120 ��: ");
		scanf_s("%f", &w);
	} while ((w < 80.f) || (w > 120.f));
	do
	{
		printf("������� ������� ����� 50-90 ��: ");
		scanf_s("%f", &d);
	} while ((d < 50.f) || (d > 90.f));
	if (h <= 200.f)
	{
		x = 4;
	}
	else
	{
		x = 5;
	}
	dvp = ((h + 1.5f *2.f) * w * 0.5f * 735.f) / 1000000.f;
	der = ((h + 1.5f * 2.f) * w * 1.f * 700.f) / 1000000.f;
	dsp = ((2.0f*d*h + w*d*2.0f + d*(w - 1.5f*2.f)*x) * 1.5f * 800.f) / 1000000.f;
	m = dsp + der + dvp;
	printf("����� ����� %f ��", m);
	return 0;
}
