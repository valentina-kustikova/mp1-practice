#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float h, w, d;//h-высота w-ширина d-глубина
	float DVP, DSP, drev;
	float zad, bok, krish, dveri, polki;
	double kol;//количество полок
	setlocale(LC_ALL, "Russian");
	printf("Введите высоту, ширину, глубину\n");
	scanf("%f %f %f", &h, &w, &d);
	if ((h < 180) || (h > 220))
	{
		printf("Неправильная высота\n");
		return;
	}
	if ((d < 50) || (d > 90))
	{
		printf("Неправильная глубина\n");
		return;
	}
	if ((w < 80) && (w > 120))
	{
		printf("Неправильная ширина\n");
		return;
	}
	printf("Введите плотности ДВП, ДСП, дерева(КГ/М^3)\n");
	scanf("%f %f %f", &DVP, &DSP, &drev);
	if ((DVP <= 0) || (DSP <= 0) || (drev <= 0))
	{
		printf("Неправильная плотность\n");
		return;
	}
	kol = floor(h / 40);
	h = h / 100.0f;//Перевод в СИ см-->м
	w = w / 100.0f;
	d = d / 100.0f;
	zad = (h - 2 * 0.015f) * w * DVP * 0.005f;
	bok = 2.0f * DSP * (h - 2 * 0.015f) * (d - 0.005f)  * 0.015f;
	krish = 2.0f * DSP * w * d *0.015f;
	dveri = drev * (h - 2 * 0.015f) * (w - 2 * 0.015f) * 2.0f;
	polki = kol * (h - 2 * 0.015f) / (0.4f + 0.015f) * (w - 2 * 0.015f) * (d - 0.005f)* drev;
	printf("Масса шкафа равна %f\n", zad + bok + krish + dveri + polki);
}