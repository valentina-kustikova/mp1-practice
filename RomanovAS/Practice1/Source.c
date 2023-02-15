#include <stdio.h>
int main()
{
	float h = 0, w = 0, d = 0, k, dsp = 650, dvp = 800, wood = 550, m1, m2, m3, m4, m5, m;
	int i = 0;
	do
	{
		printf("Vvedite visoty shkafa v sm");
		scanf("%f", &h);
		printf("Vvedite shiriny shkafa v sm");
		scanf("%f", &w);
		printf("Vvedite glybiny shkafa v sm");
		scanf("%f", &d);
	} while ((h < 180 && h > 220) && (w < 80 && w > 120) && (d < 50 && d > 90));
	printf("Dannye v poryadke  ");
	k = h - 3;
	h *= 0.01;
	w *= 0.01;
	d *= 0.01;
	m1 = h * w * 0.005 * dvp;
	m2 = w * d * 0.015 * 2 * dsp;
	m3 = (w - 0.03) * d * 0.015 * 2 * dsp;
	m4 = h * w * 0.01 * wood;
	while (k >= 40)
	{
		k -= 40;
		i++;
	}
	m5 = d * (w - 0.03) * 0.015 * i * dsp;
	m = m1 + m2 + m3 + m4 + m5;
	printf("Massa shkafa= %f kg", m);
	return 0;
}
