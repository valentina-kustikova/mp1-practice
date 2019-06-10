#include <stdio.h>
#include <locale.h>

void main()
{
	float w, d, h, m1, m2, m3, m4, m5, m, n;
	float tdvp, tdsp, twood, dvp, dsp, wood; //Плотность и толщина
	setlocale(LC_ALL, "Russian");

	tdvp = 0.005f;
	tdsp = 0.015f;
	twood = 0.001f;

	printf("Введите плотность материала ДВП (кг/м^3)\n");
	scanf_s("%f", &dvp);

	printf("Введите плотность материала ДСП (кг/м^3)\n");
	scanf_s("%f", &dsp);

	printf("Введите плотность материала ДРЕВЕСИНА (кг/м^3)\n");
	scanf_s("%f", &wood);

	setlocale(LC_ALL, "Russian");
	printf("Высота шкафа (от 180 до 220 (см))");
	scanf_s("%f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Введена неверная высота");
		return;
	}
	printf("Ширина шкафа (от 80 до 120 (см))");
	scanf_s("%f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Введена неверная ширина");
		return;
	}
	printf("Глубина шкафа (от 50 до 90 (см))");
	scanf_s("%f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Введена неверная глубина");
		return;
	}

	h /= 100.0f;
	w /= 100.0f;
	d /= 100.0f;

	//Расчет массы
	m1 = ((h - 2 * 0.015) * (w - 2 * 0.015) * tdvp * dvp);     //Задняя стенка     
	m2 = (2 * (h - 2 * 0.015) * (d - 0.005) * tdsp * dsp);     //Боковины   
	m3 = (2 * (w - 2 * 0.015) * (d - 0.005) * tdsp * dsp);     //Верхняя и нижняя крышки   
	m4 = ((h - 2 * 0.015) * (w - 2 * 0.015) * twood * wood);   //Двери
	m5 = (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005) * 0.02f * tdsp;  //Полки

	//Общая масса
	m = m1 + m2 + m3 + m4 + m5;
	printf("Масса шкафа (кг) %.3f\n", m);
}

