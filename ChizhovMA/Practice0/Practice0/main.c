#include <stdio.h>
#include <locale.h>
#include <math.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	float x1, y1, r1, x2, y2, r2;
	printf("Введите координаты и радиус первой окружности");
	scanf("%f%f%f", &x1, &y1, &r1);
	printf("Введите координаты и радиус второй окружности");
	scanf("%f%f%f", &x2, &y2, &r2);


	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Окружности равны");
		return 1;
	}
	if (x1 == x2 && y1 == y2 && r1 > r2)
	{
		printf("Вторая окружность вписана впервую");
		return 1;
	}
	if (x1 == x2 && y1 == y2 && r1 < r2)
	{
		printf("Первая окружность вписана в первую");
		return 1;
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == (r1 + r2))
	{
		printf("Окружности имеют одну общую точку");
		return 1;
	}
	if (sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) >= (r1 + r2))
	{
		printf("Окружности не имеют общих точек");
		return 1;
	}
	else
	{
		printf("Окружности пресекаются в двух точках");
		return 1;
	}
	return 0;
}
