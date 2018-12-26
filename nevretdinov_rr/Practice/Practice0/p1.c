#include <stdio.h>
#include <math.h>
void main()
{
	float x, y, R, a, b, r, max, min, cc;
	printf("Vvedite koordinati i radius pervogo kruga   ");
	scanf("%f%f%f", &x, &y, &R);
	printf("Vvedite koordinati i radius vtorogo kruga   ");
	scanf("%f%f%f", &a, &b, &r);
	cc = sqrt((x - a)*(x - a) + (y - b)*(y - b));
	if (r > R)
	{
		max = r;
		min = R;
	}
	else
	{
		max = R;
		min = r;

	}
	if (R == 0)
	{
		printf("radius pervogo kruga ne vveden  ");
		return;
	}
	if (r == 0)
	{
		printf("radius vtorogo kruga ne vveden   ");
		return;
	}

	if (cc > (R + r))
	{
		printf("Krugi ne peresekautsya   ");
		return;
	}
	if ((x == a) && (y == b) && (r == R))
	{
		printf("krugi sovpadayut   ");
		return;
	}
	if (cc <= (abs(max - (min + min)))&&(r != R))
	{
		if (max==R)
		{
			printf("krugi ne peresekautsya, vtoroy krug vnutri pervogo   ");
		}
		if (max==r)
		{
			printf("krugi ne peresekautsya, perviy krug vnutri vtorogo   ");
		}
		return;
	}

	if (cc == (r + R))
	{
		printf("peresekayutsa v odnoy tochke   ");
		return;
	}
	if ((cc-(min))==(max-(min+min))&&(max != min))
	{
		if (max==R)
		{
			printf("peresekaetsya v odnoy tochke, vtoroy vnutri pervogo    ");
		}
		if (max == r)
		{
			printf("peresekaetsya v odnoy tochke, perviy vnutri vtorogo    ");
		}
		return;
	}
	printf("peresekaetsya v dvuh tochkah   ");
}