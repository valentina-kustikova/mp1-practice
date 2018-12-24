#include <stdio.h>
#include <math.h>

void main()
{
	float x1, x2, y1, y2, r1, r2, d;
	scanf("%f %f %f %f %f %f", &x1, &x2, &y1, &y2, &r1, &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (d == r1 + r2)
	{
		printf("Circles have one common point");
		return;
	}
	if (d > r1 + r2)
	{
		printf("Circles haven't common points");
		return;
	}
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("Circles coincide");
		return;
	}
	if ((d < r1 - r2) || (d < r2 - r1))
	{
		printf("One circle is inside the other");
		return;
	}
	if ((d == r1 - r2) || (d == r2 - r1))
	{
		printf("Circles touch inside");
		return;
	}
	printf("Circles have two common points");
}