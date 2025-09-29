#include <locale.h>
#include <stdio.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	float r1, r2, x1, y1, x2, y2, rast;
	scanf_s("%f %f %f %f %f %f", &r1, &r2, &x1, &y1, &x2, &y2);
	rast = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (rast > (r1 + r2))
	{
		printf("Окружности не имеют общих точек");
	}
	if ((rast < (r1 + r2)) && rast != 0 && rast != fabs(r1 - r2))
	{
		printf("Окружности имеют две общие точки");
	}
	if (rast == 0 && (r1 == r2))
	{
		printf("Окружности совпадают");
	}
	if (rast == fabs(r1 - r2))
	{
		printf("Окружности касаются внутренним образом");
	}
	if (rast == (r1 + r2))
	{
		printf("Окружности касаются внешним образом");
	}
	return 0;
}