#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double h, w, d, back_wall, side_wall, upper_n_lower_wall, shelves, doors, q, k = 0, M;
	printf("Enter cabinet height in cm ");
	scanf("%lf", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Cabinet height value out of range");
		return 1;
	}
	printf("Enter cabinet width in cm ");
	scanf("%lf", &w);
	if ((w < 80) || (w > 120))
	{
		printf("Cabinet width is out of range ");
		return 1;
	}
	printf("Enter cabinet depth in m ");
	scanf("%lf", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Cabinet depth value out of range");
		return 1;
	}
	q = h - 2;	//k=(int)(h/40.);
	while (q > 40)
	{
		q -= 40;
		k++;
	}
	back_wall = h * w * 0.005 * 800;
	side_wall = (h - 3) * d * 0.015 * 650 * 2;
	upper_n_lower_wall = w * d * 0.015 * 650 * 2;
	shelves = d * (w - 3) * 0.015 * 650 * k;
	doors = h * w * 0.01 * 550;
	M = back_wall + side_wall + upper_n_lower_wall + shelves + doors;
	printf("The weight of the cabinet is: %.3lf  kg", M / 10000);
	return 0;
}