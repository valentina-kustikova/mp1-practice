#include <stdio.h>
void main() 
{
    double V1, V2, V3, V4, V5, m1, m2, m3, m4, m5, M;
    int f;
    double l1 = 0.005, l2 = 0.015, l3 = 0.01; //толщина в метрах
    double h, w, d, p1, p2, p3;
    printf("Enter h (From 1.8 to 2):");
    scanf("%lf", &h);
    printf("Enter w (From 0.8 to 1.2):");
    scanf("%lf", &w);
    printf("Enter d (From 0.5 to 0.9):");
    scanf("%lf", &d);
    printf("Enter density of DSP p1:");
    scanf("%lf", &p1);
    printf("Enter density of DVP p2:");
    scanf("%lf", &p2);
    printf("Enter density of wood p3:");
    scanf("%lf", &p3);
    { 
	    f = h / 0.4;
	    V1 = h * w * l1;
	    V2 = 2 * h * d * l2;
	    V3 = 2 * w * d * l2;
	    V4 = h * w * l3;
	    V5 = ((int)((h - 2 * l2) / (0.4 + l2))) * (w - 2 * l2) * (d - l1) * l2;
	    m1 = V1 * p2;
	    m2 = V2 * p1;
	    m3 = V3 * p1;
	    m4 = V4 * p3;
	    m5 = V5 * p1;
	    M = m1 + m2 + m3 + m4 + m5;
	    printf("M=%.2f", M);
    }
}
