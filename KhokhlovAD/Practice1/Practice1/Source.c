#include<stdio.h>

int main()
{
	const float dsp = 1.5f;         // mm
	const float dvp = 0.5f;         // mm
	const float drv = 1.0f;         // mm
	const float plt_drv = 1.5f;     //  g/cm^3
	const float plt_dsp = 0.7f;     //  g/cm^3
	const float plt_dvp = 0.9f;     //  g/cm^3
	int h, w, d;
	float mass, polka, back_stenka, bokovina, krishka, dveri;
	printf("h=");
	scanf_s("%d", &h);
	printf("w=");
	scanf_s("%d", &w);
	printf("d=");
	scanf_s("%d", &d);
	if ((h<180)||(h>220)||(w<80)||(w>120)||(d<50)||(d>90)) //if h<200 4 polki, else 5
	{
		printf("input error");
		return 0;
	}
	back_stenka = h * w * dvp;
	bokovina = h * d * dsp;
	krishka = dsp * (w - dsp * 2) * (d - dvp);
	dveri = h * w * drv;
	polka = dsp * (w - dsp * 2) * (d - dvp);
	if (h < 200) 
	{
		mass = (back_stenka * plt_dvp + 2 * bokovina * plt_dsp + 2 * krishka * plt_dsp + dveri * plt_drv + 4 * polka * plt_dsp)/1000;
	}
	else
	{
		mass = (back_stenka * plt_dvp + 2 * bokovina * plt_dsp + 2 * krishka * plt_dsp + dveri * plt_drv + 5 * polka * plt_dsp)/1000;
	}
	printf("%f", mass);
	return 0;
}