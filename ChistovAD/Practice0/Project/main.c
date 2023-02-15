#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double r1, r2, x1, x2, y1, y2, d;
	printf("Characteristics of the first cicrle: ");
	scanf("%lf%lf%lf", &x1, &y1, &r1);
	printf("Characteristics of the second cicrle: ");
	scanf("%lf%lf%lf", &x2, &y2, &r2);
	d = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y1 * y2 + y1 * y1);
	if ((r1 == r2) && (x1 == x2) && (y1 == y2))
	{
		printf("circles are equal.");
		return 0;
	}
	if (d > (r1 + r2))
	{
		printf("Circles do not intersect.");
		return 0;

	}
	if (d < fabs(r1 - r2))
	{
		printf("One circle is located inside the other one");
		return 0;
	}
	if (d == (r1 + r2))
	{
		printf("circles are intersect externally.");
		return 0;
	}
	if (d == fabs(r1 - r2))
	{
		printf("circles are intersect intermally.");
		return 0;
	}
	if ((d > 0) && (d < fabs(r1 - r2)))
	{
		printf("circles do not intersect.");
		return 0;
	}
	if ((d > fabs(r1 - r2)) && (d < (r1 + r2)))
	{
		printf("circles have two points of intersection.");
		return 0;
	}
	return 0;
}