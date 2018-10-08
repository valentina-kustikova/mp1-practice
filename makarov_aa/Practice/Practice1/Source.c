#include <stdio.h>
#include <locale.h>
#define pDSP 700 // плотность ДСП
#define pDVP 900 // Плотность ДВП
#define pWOOD 550 // Плотность дерева
void main() {
	float h, w, d; // параметры шкафа
	float m; // масса шкафа
	int k; // количество полок
	setlocale(LC_ALL, "Russian");
	printf("Введите высоту шкафа (в см)\n");
	scanf("%f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Модели с заданными параметрами не существует");
		return;
	}
	printf("Введите глубину шкафа (в см)\n");
	scanf("%f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Модели с заданными параметрами не существует");
		return;
	}
	printf("Введите ширину шкафа (в см)\n");
	scanf("%f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Модели с заданными параметрами не существует");
		return;
	}
	k = (int)(h - 3.0) / 40;
	if (((int)h % 40) == 0)
		k--;
	m = (pDVP * h * w * 0.5f /*задняя стенка*/ + pDSP * 2 * h * d * 1.5f/*боковины*/ + pDSP * 2.0f * w * d * 1.5f/*крышки*/ + pWOOD * h * w * 1.0f/*Двери*/ + pDSP * (float)k * (d - 0.5f) * (w - 3.0f) * 1.5f/*Полки*/) / 1000000.0f;
	printf("Масса шкафа %1.1f кг\n", m);
	printf("%d", k);
}