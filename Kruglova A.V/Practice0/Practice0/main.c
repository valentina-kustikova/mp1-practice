#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	int x1, x2, y1, y2, r1, r2;
	setlocale(LC_ALL, "Rus");
	double d;
	printf("Input x1, y1, x2, y2, r1, r2\n");
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r1, &r2);
	if (r1 <= 0)
	{
		printf("Не является окружностью, r1- отрицательный\n");
		return 0;
	}
	if (r2 <= 0)
	{
		printf("Не является окружностью, r2 - отрицательный\n");
		return 0;
	}
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("Окружности равны");
	}
	else if (r1 + r2 < d)
	{
		printf("Окружности не пересекаются, не имеют общих точек");
	}
	else if (d < abs(r1 - r2))
	{
		printf("Окружности вложены друг в друга и не имеют общих точек");
	}
	else if (d == r1 + r2)
	{
		printf("Окружности касаются внешне, имеют одну общую точку");
	}
	else if (d == r1 - r2)
	{
		printf("Окружности касаются внутренне, имеют одну общую точку");
	}
	else
	{
		printf("Окружности пересекаются, две общие точки");
	}

}