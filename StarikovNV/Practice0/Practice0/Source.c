#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	//2 окружности задаются координатами центров и радиусов. Определите взаимное положение этих окружностей.
	float r1, r2, x1, x2, y1, y2, d;
	printf("Enter x1, y1\n");
	scanf("%f %f", &x1, &y1);
	printf("Enter x2, y2\n");
	scanf("%f %f", &x2, &y2);
	printf("Enter r1,r2\n");
	scanf("%f %f", &r1, &r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("Circles coincide");
		return 0;
	}
	if (d > r1 + r2)
	{
		printf("No common points");
		return 0;
	}
	if (d == r1 + r2)
	{
		printf("External touch");
		return 0;
	}
	if ((d > r1 - r2) && (d < r1 + r2))
	{
		printf("Two common points(circles intersect)");
		return 0;
	}
	if ((d >= 0) && (d < r1 - r2))
	{
		printf("One circle is inscribed in another");
		return 0;
	}
	if (d == r1 - r2)
	{
		printf("Inner touch");
		return 0;
	}
	return 0;
}