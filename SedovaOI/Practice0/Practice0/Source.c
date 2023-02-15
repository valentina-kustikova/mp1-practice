#include <stdio.h>
#include <math.h>
int main()
{
	float x1, x2, y1, y2, r1, r2, s, big_r, small_r;
	printf("Vvedite znachenie koordinate x1:");
	scanf("%f", &x1);
	printf("Vvedite znachenie koordinate y1:");
	scanf("%f", &y1);
	printf("Vvedite znachenie koordinate x2:");
	scanf("%f", &x2);
	printf("Vvedite znachenie koordinate y2:");
	scanf("%f", &y2);
	printf("Vvedite znachenie radiys1:");
	scanf("%f", &r1);
	printf("Vvedite znachenie radiys2:");
	scanf("%f", &r2);

	s = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	big_r = r1;
	if (r2 > big_r)
	{
		big_r = r2;
		small_r = r1;
	}
	else small_r = r2;
	if ((x1 == x2) && (y1 == y2) && (r1 == r2))
	{
		printf("okrygnosti sovpadaut");
		return 0;
	}
	if ((s<r1 + r2) && (s>big_r-small_r))
	{
		printf("peresechenie v dvyx tochkax");
	}
	if (s == r1 + r2)
	{
		printf("vneshnee kasanie");
	}
	if (s == big_r - small_r)
	{
		printf("vnytrennee kasanie");
	}
	if (s > r1 + r2)
	{
		printf("odna legit vne drygoi");
	}
	if (s < big_r - small_r)
	{
		printf("odna legit vnytri drygoi");
	}
	return 0;
}








