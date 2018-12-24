#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
	setlocale(LC_ALL, "Rus");
	float x1, x2, y1, y2, r1, r2, d;
	scanf("%f%f%f%f%f%f", &x1, &x2, &y1, &y2, &r1, &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if ((r1 <= 0) || (r2 <= 0))
	{
		printf("окружность не существует");
		return;
	}
	if ((d == 0) && (r1 == r2))
	{
		printf("окружности совпадают");
		return;
	}
	if (abs(r1 - r2) > d)
	{
		printf("одна из окружностей находится полностью внутри другой");
		return;
	}
	if (abs(r1 - r2) == d)
	{
		printf("окружности имеют внутреннее касание");
		return;
	}
	if (r1 + r2 == d)
	{
		printf("окружности имеют внешнее касание");
		return;
	}
	if (r1 + r2 < d)
	{
		printf("каждая из окружностей лежит вне другой");
		return;
	}
	printf("окружности пересекаются");
}
	
