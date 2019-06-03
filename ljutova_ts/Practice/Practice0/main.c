#include <stdio.h>
#include <math.h>

void main()
{
	double x1, y1, r1, x2, y2, r2, d; 
	printf("Enter r1:"); 
	scanf("%lf", &r1); 
	printf("Enter x1:"); 
	scanf("%lf", &x1); 
	printf("Enter y1:"); 
	scanf("%lf", &y1); 
	printf("Enter r2:"); 
	scanf("%lf", &r2); 
	printf("Enter x2:"); 
	scanf("%lf", &x2); 
	printf("Enter y2:"); 
	scanf("%lf", &y2); 
	d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); 
	if ((r1 < 0) || (r2 < 0)) 
	{ 
		printf("Circles do not exist"); 
		return; 
	} 
	if ((r1 == r2) && (x1 == x2) && (y1 == y2)) 
	{ 
	    printf("Circles match"); 
	    return; 
	} 
	if (d == (r1 + r2)) 
	{ 
	    printf("Circles intersect at one point, external touch"); 
	    return; 
	} 
	if (d > r1 + r2) 
	{ 
	    printf("Circles do not intersect"); 
	    return; 
	} 
	if (d > (r1 - r2) && d < (r1 + r2)) 
	{ 
	    printf("Circles intersect at two points"); 
	    return; 
	} 
	if (d < (r1 - r2) || d < (r2 - r1)) 
	{ 
	    printf("One circle is located on the other"); 
	    return; 
	} 
	if (d == (r1 - r2) || d == (r2 - r1)) 
	printf("One circle is located inside the other and has one point in common with it on the center line, internal touch"); 

}