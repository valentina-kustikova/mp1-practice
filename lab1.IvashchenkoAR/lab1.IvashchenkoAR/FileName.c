#include <stdio.h>

int main()
{
	float a = 0.5f, b = 1.5f, c = 1.5f, x = 1.0f;
	float po_dsp = 620.0f, po_dvp = 850.0f, po_dereva = 720.0f;
	float M1 = 0.0f, M2 = 0.0f;
	float  h, w, d;

	scanf_s("%f %f %f %f %f %f %f %f %f %f %f %f", &h, &w, &d, &M1, &M2, &a, &b, &c, &x, &po_dsp, &po_dvp, &po_dereva);


	if (h < 180 || h > 220)
	{
		printf("Nekkoriktniy vvod znacheniy");

			return 1;
	}
	if (w < 80 || w > 120)
	{
		printf("Nekkoriktniy vvod znacheniy");

		return 1;
	}
	if (d < 50 || d > 90)
	{
		printf("Nekkoriktniy vvod znacheniy");

		return 1;
	}

	float m_back_wall = h * w * a * po_dvp;

	float m_side_wall = h * d * b * po_dsp;

	float m_up_cap = w * d * c * po_dsp;

	float m_down_cap = w * d * c * po_dsp;

	float m_door = h * w * x * po_dereva;

	float m_inner_shelf = w * d * c * po_dsp;
	M1 = m_back_wall + 2 * m_side_wall + m_up_cap + m_down_cap + 2 * m_door + 5 * m_inner_shelf;
	M2 = m_back_wall + 2 * m_side_wall + m_up_cap + m_down_cap + 2 * m_door + 4 * m_inner_shelf;

	if (h >= 200)
	{
		printf("M1 = %f", M1);
		return 0;
	}
	if (h < 200)
	{
		printf("M2 = %f", M2);
		return 0;
	}
	return 0;
	
}