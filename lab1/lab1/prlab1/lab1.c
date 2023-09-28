#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void main()
{
	int x1, x2, y1, y2, r1, r2;
	double d;
	printf("Input x1, y1, x2, y2, r1, r2\n");
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &r1, &r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (x1 == x2 && y1 == y2 && r1 == r2)
	{
		printf("the circles are equal");
	}
	else if (r1 + r2 < d)
	{
		printf("the circles do not intersect");
	}
	else if (d < abs(r1 - r2))
	{
		printf("circles are nested");
	}
	else if (d == r1 + r2)
	{
		printf("the circles touch externally");
	}
	else if (d == r1 - r2)
	{
		printf("the circles touch internally");
	}
	else
	{
		printf("the circles intersect");
	}

}