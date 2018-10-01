#include <stdio.h>
#include <locale.h>

void main()
{
	double w, h, d, dsp, dvp, wood;
	double rp, side, lid, door, shelf, tm;
	setlocale(LC_ALL, "Russian");
	printf("Высота (180 – 220 см), ширина (80 – 120 см), глубина (50 – 90 см),\nПлотность ДСП, ДВП, дерева в кг/м^3\n\n");
	scanf("%lf %lf %lf %lf %lf %lf", &h, &w, &d, &dsp, &dvp, &wood);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90) || (dsp < 0) || (dvp < 0) || (wood < 0)) {
		printf("Некорректный ввод\n");
		return;
	}
	h /= 100;
	w /= 100;
	d /= 100;
	rp = h * w * 0.005 * dvp;
	side = 2 * h * d * 0.015 * dsp;
	lid = 2 * w * d * 0.015 * dsp;
	door = w * h * 0.01 * wood;
	if (h > 200)
		{shelf = 4 * w * d * 0.015 * dsp;}
	else
		{shelf = 3 * w * d * 0.015 * dsp;}
	tm = rp + side + lid + door + shelf;
	printf("\nПолная масса шкафа равна %.3lf кг\n\n", tm);
}