#include <stdio.h>
#include <math.h>
int main()
{
	float r1, r2, x1, x2, y1, y2, s, a, b;
	int ymax, ymin, xmax, rmax, rmin, xmin;
	printf("Vvedite koordinats x, y b radius pervoy okruzhosti");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Vvedite koordinats x, y b radius vtoroy okruzhosti");
	scanf("%f %f %f", &x2, &y2, &r2);
	xmax = fmax(x1, x2);
	xmin = fmin(x1, x2);
	rmax = fmax(r1, r2);
	ymin = fmin(y1, y2);
	ymax = fmax(y1, y2);
	rmin = fmin(r1, r2);
	rmax = fmax(r1, r2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("okruzhosti sovpadayut");
		return 0;
	}
	if ((x1 == x2) && (y1 != y2))
	{
		if ((y1 > 0) && (y2 > 0))
		{
			s = abs(y1 - y2);
		}
		if ((y1 < 0) && (y2 > 0))
		{
			s = (y2 + abs(y1));
		}
		if ((y1 > 0) && (y2 < 0))
		{
			s = (y1 + abs(y2));
		}
		if ((y1 < 0) && (y2 < 0))
		{
			s = abs(abs(y1) - abs(y2));
		}
	}
	if ((y1 == y2) && (x1 != x2))
	{
		if ((x1 > 0) && (x2 > 0))
		{
			s = abs(x1 - x2);
		}
		if ((x1 < 0) && (x2 > 0))
		{
			s = (x2 + abs(x1));
		}
		if ((x1 > 0) && (x2 < 0))
		{
			s = (x1 + abs(x2));
		}
		if ((x1 < 0) && (x2 < 0))
		{
			s = abs(abs(x1) - abs(x2));
		}
	}
	if ((x1 != x2) && (y1 != y2))
	{
		if ((y1 > 0) && (y2 > 0))
		{
			b = ymax - ymin;
		}
		if ((y1 > 0) && (y2 < 0))
		{
			b = y1 + abs(y2);
		}
		if ((y1 < 0) && (y2 > 0))
		{
			b = y2 + abs(y1);
		}
		if ((y1 < 0) && (y2 < 0))
		{
			b = abs(ymin) - abs(ymax);
		}
		if ((x1 > 0) && (x2 > 0))
		{
			a = xmax - xmin;
		}
		if ((x1 < 0) && (x2 > 0))
		{
			a = x2 + abs(x1);
		}
		if ((x1 > 0) && (x2 < 0))
		{
			a = x1 + abs(x2);
		}
		if ((x1 < 0) && (x2 < 0))
		{
			a = abs(xmin) - abs(xmax);
		}
		s = sqrt((a * a) + (b * b));
	}
	if (s == (r1 + r2))
	{
		printf("okruzhnosti kasautsya");
		return 0;
	}
	if (s > (r1 + r2))
	{
		printf("okruzhnosti ne peresekautsya");
		return 0;
	}
	if (s < (r1 + r2))
	{
		if ((s == rmin) || (rmax - s == rmin))
		{
			printf("okruzhnosti kasautsya");
			return 0;
		}
		if (rmax - s > rmin)
		{
			printf("okruzhnost soderzhitsya v drugoi");
			return 0;
		}
		if ((rmax < s) || ((rmax > s) && (rmin > (rmax - s))))
		{
			printf("okruzhnosti peresekayutsya v dvuh tochkah");
			return 0;
		}
	}
	return 0;
}

		
	



