#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	int h, d, w;
	double pDVP, pDSP, pWOOD, mBack, mSides, mTop, mShelf, mDoors , Mass;
	setlocale(LC_ALL, "Russian");
	printf("Укажите высоту шкафа в см(от 180 до 220 см)\n");
	scanf("%d", &h);
	if ((h > 220) || (h < 180))
	{
		printf("Ошибка: Высота шкафа выходит за заданные пределы\n");
		return;
	}
	h /= 100.0;
	printf("Укажите ширину шкафа в см(от 80 до 120 см)\n");
	scanf("%d", &w);
	if ((w > 120) || (w < 80))
	{
		printf("Ошибка: Ширина шкафа выходит за заданные пределы\n");
		return;
	}
	w /= 100.0;
	printf("Укажите глубину шкафа в см(от 50 до 90 см)\n");
	scanf("%d", &d);
	if ((d > 90) || (d < 50))
	{
		printf("Ошибка: Глубина шкафа выходит за заданные пределы\n");
		return;
	}
	d /= 100.0;
	printf("Введите плотность ДВП в кг/м^3 \n");
	scanf("%lf", &pDVP);
	if (pDVP <= 0) 
	{
		printf("Ошибка: Плотность должна быть больше нуля\n");
		return;
	}

	printf("Введите плотность ДСП в кг/м^3 \n");
	scanf("%lf", &pDSP);
	if (pDSP <= 0) {
		printf("Ошибка: Плотность должна быть больше нуля\n");
		return;
	}

	printf("Введите плотность дерева в кг/м^3 \n");
	scanf("%lf", &pWOOD);
	if (pWOOD <= 0) 
	{
		printf("Ошибка: Плотность должна быть больше нуля\n");
		return;
	}
	mBack = (h * w * 0.005 * pDVP);
	mSides = (2 * h * d * 0.015 * pDSP);
	mTop = (2 * w * d * 0.015 * pDSP);
	mDoors = (h * w * 0.01 * pWOOD);
	mShelf = floor((h - 2 * 0.015) / (0.4 + 0.015)) * (w - 2 * 0.015) * (d - 0.005) * 0.015 * pDSP;
	Mass = mBack + mSides + mTop + mDoors + mShelf;
	printf("Масса шкафа: %lf кг \n", Mass);
}	
