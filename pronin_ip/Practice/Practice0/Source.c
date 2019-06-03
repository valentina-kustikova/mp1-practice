#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	float x, y, r, x1, y1, r1, L;
	setlocale(LC_ALL, "Russian");
	printf("Введите координаты центра первой окружности");
	scanf("%f %f", &x, &y);
	printf("Введите радиус первой окружности");
	scanf("%f", &r);
	printf("Введите координаты центра второй окружности");
	scanf("%f %f", &x1, &y1);
	printf("Введите радиус второй окружности");
	scanf("%f", &r1);
	L = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
	if ((r < 0) || (r1 < 0))
	{
		printf("Ошибка");
		return;
	}
	if (L > (r + r1))
	{
		printf("Окружности не пересекаются");
		return;
	}
	if (L == (r + r1))
	{
		printf("Окружности касаются внешне");
		return;
	}
	if ((x == x1) && (y == y1) && (r == r1))
	{
		printf("Окружности совпадают");
		return;
	}
	if (((r > r1) && (L == r - r1)) || ((r1 > r) && (L == r1 - r)))
	{
		printf("Окружности внутр касаются");
		return;
	}
	if ((r > r1) && (L < (r - r1)))
	{
		printf("Окружность два входит в окружность один");
		return;
	}
	if ((r1 > r) && (L < (r1 - r)))
	{
		printf("Окружность один входит в окружность два");
		return;
	}
	printf("Окружности пересекаются");
}
