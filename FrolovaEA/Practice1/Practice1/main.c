#include<stdio.h>
#include<math.h>

int main()
{
	double h, w, d, q_dsp = 725, q_dvp = 850, q_wood = 700, k,
		t_dsp = 0.015, t_dvp = 0.005, t_wood = 0.01,
		v1, v2, v3, v4, v5, v_dsp, m_dvp, m_dsp, m_wood, m;


	printf("Enter the height of the cabinet in meters: ");
	scanf_s("%lf", &h);

	printf("\nEnter the width of the cabinet in meters: ");
	scanf_s("%lf", &w);

	printf("\nEnter the depth of the cabinet in meters: ");
	scanf_s("%lf", &d);


	if ((h < 1.8) || (h > 2.2))
	{
		printf("Incorrect height, 1.8<=height>=2.2");
		return 1;
	}

	if ((w < 0.8) || (w > 1.2))
	{
		printf("Incorrect width, 0.8<=width>=1.2");
		return 1;
	}

	if ((d < 0.5) || (d > 0.9))
	{
		printf("Incorrect depth, 0.5<=depth>=0.9");
		return 1;
	}

	k = (int)(h / 0.4);
	v1 = h * w * t_dvp;
	v2 = 2 * h * d * t_dsp;
	v3 = 2 * (w - 2 * t_dsp) * d * t_dsp;
	v4 = w * h * t_wood;
	v5 = k * (w - 2 * t_dsp) * d * t_dsp;
	v_dsp = v2 + v3 + v5;
	m_dvp = v1 * q_dvp;
	m_dsp = (v2 + v3 + v5) * q_dsp;
	m_wood = v4 * q_wood;
	m = m_dvp + m_dsp + m_wood;

	printf("%f", m);

	return 0;
}