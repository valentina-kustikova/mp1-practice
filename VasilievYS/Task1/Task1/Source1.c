#include <stdio.h>
#include <locale.h>
int main()
{
	float m, wPol, w, h, tDvp = 0.5, tDsp = 1.5, tDer = 1.0, d; //в см
	float pDer = 0.72, pDsp = 1.3, pDvp = 0.85; //в г/см3
	int cPol;
	setlocale(LC_ALL, "RUS");
	do
	{
		printf("Введите высоту(180-220см), ширину(80-120см), глубину(50-90см): ");
		scanf_s("%f %f %f", &h, &w, &d);
	} while ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90));
	if (((int)h % 40) == 0)
	{
		cPol = (h / 40) - 1;
	}
	else
	{
		cPol = h / 40;
		cPol = (int)cPol;
	}
	wPol = w - 2 * tDsp;
	m = (pDvp * h * w * tDvp) + (pDsp * h * d * tDsp * 2) + (pDsp * w * d * tDsp * 2) + (pDer * h * w * tDer) + (pDsp * d * wPol * tDsp * cPol);
	printf("Масса шкафа = %f кг", m/1000);
	return 0;
}