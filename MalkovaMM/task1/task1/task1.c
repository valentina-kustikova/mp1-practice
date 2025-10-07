#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	float h, w, d, x;
	float m, dvp, dsp, der;
	do
	{
		printf("Введите высоту шкафа 180-220 см: ");
		scanf_s("%f", &h);
	} while ((h < 180) || (h > 220));
	do
	{
		printf("Введите ширину шкафа 80-120 см: ");
		scanf_s("%f", &w);
	} while ((w < 80) || (w > 120));
	do
	{
		printf("Введите глубину шкафа 50-90 см: ");
		scanf_s("%f", &d);
	} while ((d < 50) || (d > 90));
	if (h <= 200)
	{
		x = 4;
	}
	else
	{
		x = 5;
	}
	dvp = (h * w * 0.5 * 850) / 1000000;
	der = (h * w * 1 * 720) / 1000000;
	dsp = ((2*d*h + w*d*2 + d*w*x) * 1.5 * 620) / 1000000;
	m = dsp + der + dvp;
	printf("Масса шкафа %f кг", m);
	return 0;
}
