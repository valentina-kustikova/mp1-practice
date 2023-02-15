#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {

	float x1, x2, y1, y2, r1, r2, dl;

	setlocale(LC_ALL, "rus");

	printf("Enter x1: ");
	scanf_s("%f", &x1);

	printf("Enter x2: ");
	scanf_s("%f", &x2);

	printf("Enter y1: ");
	scanf_s("%f", &y1);

	printf("Enter y2: ");
	scanf_s("%f", &y2);

	printf("Enter r1: ");
	scanf_s("%f", &r1);

	printf("Enter r2: ");
	scanf_s("%f", &r2);

	dl = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

	if (dl == r1 + r2)
	{
		printf("The circles touch each other (external touch)");
		return 0;
	}

	if (dl > r1 + r2)
	{
		printf("The circles do not touch each other ");
		return 0;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("The circles match");
		return 0;
	}

	if ((dl + r1 == r2) || (dl + r2 == r1))
	{
		printf("The circles touch each other (inner touch)");
		return 0;
	}

	if (abs(x1 - x2) < r1 || abs(x1 - x2) < r2)
	{
		printf("One circle inside another");
		return 0;
	}

	printf("Circles have two points in common");
	return 0;


}