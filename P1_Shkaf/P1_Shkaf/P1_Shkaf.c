#include <stdio.h>

#define dcp 0.0008
#define dvp 0.0007
#define wood 0.00065

void main() {
	float h, b, d, m, m_backwall, m_sidewall, m_topwall, m_doors, m_shelfs;
	int k;

	do { 
		printf("\n\tEnter the height(180-220cm), width(80-120cm), deepth(50-90cm)\n"); 
		scanf_s("%f%f%f", &h, &b, &d);
	} while ((h < 180) || (h > 220) || (b < 80) || (b > 120) || (d < 50) || (d > 90));

	if (h <= 200) k = 4;
	else k = 5;

	m_backwall = dvp * h * b * 0.5;
	m_sidewall = dcp * h * d * 1.5;
	m_topwall = dcp * b * d * 1.5;
	m_doors = wood * b * h;
	m_shelfs = k * dcp * b * d;
	m = m_backwall + 2 * m_sidewall + 2 * m_topwall + m_doors + m_shelfs;

	printf("Weight is %.0f ", m);
	printf("kg\n");

	system("pause");
}

