#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <conio.h>


int main()
{
	float xc1, yc1, xc2, yc2,r1,r2,sc,d;
	printf("Enter the coordinates of the center of the first circle: ");
	scanf("%f %f", &xc1, &yc1);
	printf("Enter the coordinates of the center of the second circle: ");
	scanf("%f %f", &xc2, &yc2);
	printf("Enter the radius of the first circle: ");
	scanf("%f", &r1);
	printf("Enter the radius of the second circle: ");
	scanf("%f", &r2);
	sc = sqrt(((xc2 - xc1)*(xc2-xc1)) + ((yc2 - yc1)*(yc2 - yc1)));
	d = sc - (r1 + r2);

	if (sc == 0 && r1 == r2)
	{
		printf("the circles are congruent\n");
	}

	else if (d== 0)
	{
		printf("the circles are touching\n");
	}

	else if (d > 0)
	{
		printf("The circles are distant from each other\n");
	}

	else if (sc < abs(r1 - r2))
	{
		printf("One circle inside another\n");
	}

	else if (sc == abs(r1-r2))
	{
		printf("The circles have one common point\n");
	}
	else 
	{
		printf("The circles intersect at two points\n");
	}
	getchar();
	return 0;
}