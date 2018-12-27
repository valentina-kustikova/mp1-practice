#include <math.h>
#include <stdio.h>
void main()
{
	float h, w, d, n, c, m1, m2, m3, m4, m5, M, p1, p2, p3;
    scanf("%f %f %f %d %f %f %f %f %f %f %f %d %d %d" &h, &w, &d, &n, &c, &m1, &m2, &m3, &m4, &m5, &M, &p1, &p2, &p3);
	int M = m1 + m2 + m3 + m4 + m5;
	int p1 = 850, p2 = 800, p3 = 540;
	if (1, 8 <= h <= 2, 2)
	if(0, 5 <= d <= 0, 9);
	{
		if (c == 0, 005)
		{
			printf(m1 = h * w * c * p1); /*масса задней стенки*/
			return;
		}
		if (c == 0, 015)
		{
			printf(m2 = 2 * h * d * c * p2); /*масса боковин*/
			printf(m3 = w * d*p2 * 2 * c); /*масса верхней и нижней крышек*/
			return;
		}
		if (c == 0, 01)
		{
			print(m4 = h * w*c*p3); /*Масса двух накладных дверей*/
			return;
		}
		if (c == 0, 05)
		{
			if (n == 3) 
			{
				print(m5 = 3 * w*d*c*p2); /*масса трёх полок*/
				return;
			}
			if (n == 4)
			{ if (h <= 2,2)
			{
				printf ("условие не выполняется");
				return;
			}
				if h==2,2
				{
					printf(d * w * c * 4 * p2); /*масса четырёх полок*/
					return;
				}
			}
		}
	}
	printf(M = m1 + m2 + m3 + m4 + m5); /*масса шкафа*/
}