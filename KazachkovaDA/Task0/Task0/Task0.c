#include <stdio.h>
#include <math.h>
int main() {
	float r1, r2, x1, x2, y1, y2;
	scanf_s("%f %f %f %f %f %f", &r1, &r2, &x1, &x2, &y1, &y2);

	if (r1 <= 0 || r2 <= 0) 
	{
		printf("The radius must be >0");
		return 1;
	}

	if (x1 == x1 && y1 == y2 && r1 == r2) 
	{
		printf("Okruzhnosti sovpadaut");
		return 0;
	}

	if ((abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - 22)) > (r1 + r2)* (r1 + r2)) 
	{
		printf("Okruzhnosti ne peresekautsya");
		return 0;
	}

	if ((abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - 22)) == (r1 + r2)* (r1 + r2))
	{
		printf("Okruzhnosti kasautsya");
		return 0;
	}

	if ((abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - 22)) < (r1 + r2)* (r1 + r2))
	{
		printf("Okruzhnosti peresekautsya v dvuh tochkah");
		return 0;
	}
}