#include <stdio.h>

#define dcp 800
#define dvp 700
#define wood 650

void main() {
	float h, w, d, t_dsp = 0.0015, t_dvp = 0.005, t_wood = 0.01, v1, v2, v3, v4, v5, v_dsp, m_dvp, m_dsp, m_wood, m;
	int k;
	do { 
		printf("\n\tEnter the height(1.80-2.20m), width(0.80-1.20m), deepth(0.50-0.90m)\n"); 
		scanf_s("%f%f%f", &h, &w, &d);
	} while ((h < 1.8) || (h > 2.2) || (w < 0.8) || (w > 1.2) || (d < 0.5) || (d > 0.9));

	if (h <= 2) k = 4;
	else k = 5;

	v1 = h * w * t_dvp;
	v2 = 2 * h * d * t_dsp;
	v3 = 2 * ( w - 2 * t_dsp ) * d * t_dsp;
	v4 = 2 * w * h * t_wood;
	v5 = k * ( w - 2 * t_dsp ) * d * t_dsp;
	v_dsp = v2 + v3 + v5;
	m_dvp = v1 * dvp;
	m_dsp =(v2 + v3 + v5 ) * dcp;
	m_wood = v4 * wood;
	m = m_dvp + m_dsp + m_wood;


	printf("Weight is %.0f ", m);
	printf("kg\n");

	system("pause");
}

