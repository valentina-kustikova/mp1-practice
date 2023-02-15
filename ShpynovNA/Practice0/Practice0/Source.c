#include <stdio.h>
#include <math.h>
int main()
{
	float x1, x2, y1, y2, r1, r2, s, br, smr;
	do {
		scanf("%f %f %f", &x1, &y1, &r1);
		scanf("%f %f %f", &x2, &y2, &r2);
		if ((r1 < 0) || (r2 < 0)) {
			printf("something went wrong");
			return 1;
		}
		s = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		br = r1;
		if (r2 > br) { br = r2; smr = r1; }
		else smr = r2;
		if ((x1 == x2) && (y1 == y2) && (r1 == r2))
		{
			printf("circumferences are the same");
			return 0;
		}
		if (r1 + r2 < s)
		{
			printf("circumferences doesn't intersect");
		}
		if (r1 + r2 == s)
		{
			printf("circumferences touch");
		}
		if ((r1 + r2 > s) && (s >= br))
		{
			printf("circumferences intersect");
		}
		if ((s < br) && (smr < (br - s)))
		{
			printf("one circumference is inside another");
		}
		if ((s < br) && (smr == (br - s)))
		{
			printf("one circumference is inside another and they touch");
		}
	} while (2);
	return 0;
}