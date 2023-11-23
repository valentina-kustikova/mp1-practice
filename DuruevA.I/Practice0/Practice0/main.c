#include<stdio.h>
#include<math.h>
int main(void)
{
	float x1, x2, y1, y2, r1, r2, d;
	printf("input x1,x2,y1,y2,r1,r2\n");
	scanf("%f,%f,%f,%f,%f,%f", &x1, &x2, &y1, &y2, &r1, &r2);
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 == 0 || r2 == 0) {
		printf("error");
	}
	else if (d == 0) {
		printf("circles match");
	}
	else if (d > r1 + r2) {
		printf("circles do not intersect");
	}
	else if (d == r1 + r2) {
		printf("circles touch from the outside");
	}
	else if (r1 < r2 && d + r1 < r2) {
		printf("one circle is inside the other");
	}
	else if (r1 > r2 && d + r2 < r1) {
		printf("one circle is inside the other");
	}
	else if (r1 > r2 && d + r1 == r2) {
		printf("circles touch inside");
	}
	else if (r2 > r1 && d + r1 == r2) {
		printf("circles touch inside");
	}
	else   {
		printf("circles intersect");
	}
	return 0;

}
