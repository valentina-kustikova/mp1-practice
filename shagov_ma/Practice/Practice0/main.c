#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float x, y, r; //координаты первой окр
	float a, b, c; //координаты второй окр
	float k; //расстояние между центрами
	setlocale(LC_ALL, "Russian");
	printf("Введите координаты центра первой окружности и ее радиус\n");
	scanf("%f %f %f", &x, &y, &r);
	printf("Введите координаты центра второй окружности и ее радиус\n");
	scanf("%f %f %f", &a, &b, &c);
	if ((x == a) && (y == b) && (r == c))
	{
		printf("Окружности совпадают\n");
		return;
	}
	if ((x == a) && (y == b) && (r != c))
	{
		printf("Одна окружность вложена в другую и их центры совпадают\n");
		return;
	}
	k = sqrt((x - a) * (x - a) + (y - b) * (y - b));
	if ((k + r < c) || (k + c < r))
	{
		printf("Одна окружность вложена в другую и их центры не совпадают\n");
		return;
	}
	if (k > r + c)
	{
		printf("Окружности не пересекаются\n");
		return;
	}
	if ((k + r == c) || (k + c == r))
	{
		printf("Окружности касаются внутренним образом\n");
		return;
	}
	if (k == r + c)
	{
		printf("Окружности касаются\n");
		return;
	}
	
		printf("Окружности пересекаются\n");
		return;
}