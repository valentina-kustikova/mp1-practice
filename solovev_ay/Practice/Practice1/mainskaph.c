#include <stdio.h>
#include <math.h>
#include <locale.h>

	void main() {
	float h, w, d, rodvp, rodsp, rodereva, kolvopolok, m, mstenki, mbokovin, mkrishki, mdverei, mpolok;
	int b;
	setlocale(LC_ALL, "Russian");
	printf("Вычисление массы двухдверного шкафа фирмы Умелые ручки\n");
	printf("Введите высоту и ширину задней стенки шкафа в сантиметрах!\n");
	printf("Высота:");
	scanf("%f",&h);
	if ((h < 180) || (h > 220))
	{
	printf("Ошибка!\nВысота должна быть от 180 до 220 см.");
	return;
	}
	printf("Ширина:");
	scanf("%f",&w);
	if ((w < 80)||(w > 120))
	{
	printf("Ошибка!\nШирина должна быть от 80 до 120 см.\n");
	return;
	}
	printf("Параметры вашей задней накладной стенки шкафа:%.3f x %.3f\n",h, w);
	printf("Введите глубину боковин в сантиметрах:");
	scanf("%f", &d);
	if ((d < 50)||(d > 90))
	{
	printf("\nОшибка!\nГлубина должна быть от 50 до 90 см.");
	return;
	}
	printf("Параметры вашей боковины:%.3f x %.3f\n",h, d);
	printf("Параметры ваших нижней и верхней крышек:%.3f x %.3f\n",w, d);
	printf("Параметры вашей двери:%.3f x %.3f\n",h, w/2);
	kolvopolok = h/40;
	b = kolvopolok;
	printf("Введите плотность дерева в г/см^3:");
	scanf("%f", &rodereva);
	printf("Введите плотность ДСП в г/см^3:");
	scanf("%f", &rodsp);
	printf("Введите плотность ДВП в г/см^3:");
	scanf("%f", &rodvp);
	mstenki = rodvp * h * w * 0.5;
	mbokovin = 2 * h * d * 1.5 * rodsp;
	mkrishki = 2 * w * d * 1.5 * rodsp;
	mdverei = h * w * rodereva;
	mpolok = b * rodsp * (w-3) * d * 1.5;//взял толщину полки 15мм
	m = mstenki + mbokovin + mkrishki + mdverei + mpolok;
	m = m/1000;
	printf("Масса шкафа:=%.3f килограмм!\n",m);
	return;
	}