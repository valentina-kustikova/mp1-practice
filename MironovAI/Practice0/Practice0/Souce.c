#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	float x1, dl, x2, y1, y2, r1, r2;

	setlocale(LC_ALL, "Russian");
	printf("Input x1: ");
	scanf_s("%f", &x1);

	printf("Input y1: ");
	scanf_s("%f", &y1);

	printf("Input r1: ");
	scanf_s("%f", &r1);

	printf("Input x2: ");
	scanf_s("%f", &x2);

	printf("Input y2: ");
	scanf_s("%f", &y2);

	printf("Input r2: ");
	scanf_s("%f", &r2);


	dl = sqrt(abs((x1 - x2)) * abs((x1 - x2)) + abs((y1 - y2)) * abs((y1 - y2)));

	if (dl == r1 + r2)
	{
		printf("Окружности касаются");
		return;
	}

	if (dl >= r1 + r2)
	{
		printf("Окружности не имеют общих точек");
		return;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Окружности совпадают");
		return;
	}

	if (dl == abs(r1 - r2))
	{
		printf("Окружности касаются внутри");
		return;
	}



	if (r1 > r2)
	{
		if (abs(x1 - x2) + r2 <= r1)
		{
			printf("Одна окружность внутри другой");
			return;
		}
	}

	if (r1 < r2)
	{
		if (abs(x1 - x2) + r1 <= r2)
		{
			printf("Одна окружность внутри другой");
			return;
		}
	}





	printf("Окружности имеют 2 точки пресечения");
	return 0;
}