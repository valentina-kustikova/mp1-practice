#include <stdio.h>
void main()
{
	double dsp, dvp, derevo, m, h, w, d, zs, bok, kr, dv, pol;
	printf("Vvedite plotnost DSP, kg/m^3");
	scanf("%lf", &dsp);
	printf("Vvedite plotnost DVP, kg/m^3");
	scanf("%lf", &dvp);
	printf("Vvedite plotnost dereva, kg/m^3");
	scanf("%lf", &derevo);
	printf("Vvedite h, sm");
	scanf("%lf", &h);
	if ((h < 180) || (h > 220))
	{
		printf("Nekorrektno vvedeni dannie");
		return;
	}
	printf("Vvedite w, sm");
	scanf("%lf", &w);
	if ((w < 20) || (w > 120))
	{
		printf("Nekorrektno vvedeni dannie");
		return;
	}
	printf("Vvedite d, sm");
	scanf("%lf", &d);
	if ((d < 50) || (d > 90))
	{
		printf("Nekorrektno vvedeni dannie");
		return;
	}
	h = h / 100;
	w = w / 100;
	d = d / 100;
	zs = h * w * 0.005 * dvp;
	bok = h * d * 0.015 * dsp;
	kr = w * d * 0.015 * dsp;
	dv = h * (w / 2) * 0.01 * derevo;
	pol = (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005) * dsp;
	m = zs + 2 * bok + 2 * kr + 2 * dv + 4 * pol;
	printf("Massa shkafa=%lf", m);
	return;
}
