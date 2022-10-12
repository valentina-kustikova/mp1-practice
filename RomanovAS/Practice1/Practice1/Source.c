#include <stdio.h>
int main()
{
	int h, H, w, d, k, dsp = 650, dvp = 800, vood = 550;
	float m1, m2, m3, m4, m5, m;
	printf("Vvedite visoty shkafa v sm");
	scanf("%d", &H);
	printf("Vvedite shiriny shkafa v sm");
	scanf("%d", &w);
	printf("Vvedite glybiny shkafa v sm");
	scanf("%d", &d);
	if ((H >= 180 && H <= 220) && (w >= 80 && w <= 120) && (d >= 50 && d <= 90))
	{
		printf("Dannye v poryadke");
	}
	else
	{
		printf("Dannye neverny");
		return 1;
	}
	h = H - 3;
	if (h % 40 == 0)
	{
		k = (h / 40) - 1;
	}
	else
	{
		k = h / 40;
	}
	m1 = ((H * w * 0.5) / 1000000) * dvp;
	m2 = ((d * h * 1.5) / 1000000) * dsp * 2;
	m3 = ((w * d * 1.5) / 1000000) * dsp * 2;
	m4 = ((w * h) / 1000000) * vood;
	m5 = ((w * d * 1.5) / 1000000) * dsp * k;
	m = m1 + m2 + m3 + m4 + m5;
	printf("Massa shkafa= %f kg", m);
}