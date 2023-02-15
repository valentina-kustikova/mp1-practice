#include <stdio.h>
#include <math.h>
int main()
{
	float r1, r2, x1, y1, x2, y2;
	float rasti;
	float summa_between_radius, difference_between_radius;
	printf("Enter x1 y1\n");
	scanf("%f %f", &x1, &y1);
	printf("Enter x2 y2\n");
	scanf("%f %f", &x2, &y2);
	printf("Enter r1 r2\n");
	scanf("%f %f", &r1, &r2);
	rasti = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	difference_between_radius = abs(r2 - r1);
	summa_between_radius = (r1 + r2);
	if (rasti > summa_between_radius)
	{
		printf("No matul points");
		return 0;
	}
	if (rasti == summa_between_radius)
	{
		printf("External Tangency of circles");
		return 0;
	}
	if ((rasti > difference_between_radius) && (summa_between_radius > rasti))
	{
		printf("circles intersect");
		return 0;
	}
	if ((rasti >= 0) && (difference_between_radius > rasti))
	{
		printf("No matual points.One cercle in incribed in another");
		return 0;
	}
	if ((r1 == r2) && (x1 == x2) && (y1 == y2))
	{
		printf("Circles Coincide");
		return 0;
	}
	if (rasti == difference_between_radius)
	{
		printf("Internal Tangency of circles");
		return 0;
	}

}