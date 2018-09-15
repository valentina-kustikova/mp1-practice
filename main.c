#include <math.h>
#include <stdio.h>

int main()
{
    float a=0.0, b=0.0, c=0.0, p=0.0, s=0.0;
    scanf_s("%f %f %f", &a, &b, &c);
    p = ((a + b + c) / 2);
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("S=%.03f \n", s);
    getch();
    return 0;
}
