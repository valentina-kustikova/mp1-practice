#include <stdio.h>
#include <math.h>
int main()
{
	float r1, r2, x1, x2, y1, y2, s = 0, a, b;
	int ymax, ymin, xmax, rmax, rmin, xmin;
	printf("Vvedite koordinats x, y b radius pervoy okruzhosti");
	scanf("%f %f %f", &x1, &y1, &r1);
	printf("Vvedite koordinats x, y b radius vtoroy okruzhosti");
	scanf("%f %f %f", &x2, &y2, &r2);
	rmin = fmin(r1, r2);
	rmax = fmax(r1, r2);
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("okruzhosti sovpadayut");
		return 0;
	}
	s = sqrt((x1 -x2)* (x1 - x2) + (y1 - y2)*(y1 - y2));
	if (s == (r1 + r2))
	{
		printf("okruzhnosti kasautsya snaruzhi");
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
			printf("okruzhnosti kasautsya vnutri");
			return 0;
		}
		if (rmax - s > rmin)
		{
			printf("okruzhnost soderzhitsya v drugoi");
			return 0;
		}
		printf("okruzhnosti peresekayutsya v dvuh tochkah");
	}
	return 0;
}