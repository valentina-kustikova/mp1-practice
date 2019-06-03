#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int k;
	int p1 = 950, p2 = 800, p3 = 540;
	float h, w, d, m1, m2, m3, m4, m5, x1 = 0.005, x2 = 0.015, x3 = 0.01;
	printf("Vvedite visoty, dliny, shiriny");
	scanf("%f%f%f", &h, &d, &w);
	if ((1.8 <= h) && (h <= 2.2) && (0.5 <= d) && (d <= 0.9) && (0.8 <= w) && (w <= 1.2))
	{
		if ((1.8 <= h) && (h <= 2))
		{
			k = 4;
		}
		if ((2 <= h) && (2.2 <= h))
		{
			k = 5;
		}
		m1 = p1 * h * w * x1;
		m2 = 2 * p2 * h * d * x2;
		m3 = 2 * p2 * w * d *x2;
		m4 = 2 * p3 * h * w * x3;
		m5 = k * p2 * w * d * x2;
		printf("%f", m1 + m2 + m3 + m4 + m5);
	}
	else
	{
		printf("Oshibka");
	}
}