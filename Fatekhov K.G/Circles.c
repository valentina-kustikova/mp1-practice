#include <stdio.h>
#include <math.h>
int main()
{
	int x1, x2, y1, y2, r1, r2,d;
	printf("Input x1,y1,r1\t");
	scanf_s("%d%d%d", &x1, &y1, &r1);
	printf("Input x2,y2,r2\t");
	scanf_s("%d%d%d", &x2, &y2, &r2);
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	if (d > r1 + r2 || 0<d<abs(r1-r2))
	{
		printf("There are no common points");
		return;
	}
	if (y1 == y2 && x1 == x2 && r1 == r2)
		printf("The circles match");
	else
	if (d == r1 + r2 || d == r1 - r2)
	{
		printf("There is one common point");
		return;
	}
	if (d > r1 - r2 && d < r1 + r2)
	{
		printf("There are two common points");
	}
	
	
	system("pause\t\t");
	




}