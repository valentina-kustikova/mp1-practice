#include <stdio.h>

void main()
{
	float p_Tree = 900.0, p_DVP = 800.0, p_DSP = 800.0;
	float th_Tree = 0.01, th_DVP = 0.005, th_DSP = 0.015;
	float h, w, d, m_z, m_b, m_k, m_d, m_p, weight_carcas;
	int n;
	printf("Enter the height of the wardrobe ");
	scanf_s("%f", &h);
	printf("Enter the width of the wardrobe ");
	scanf_s("%f", &w);
	printf("Enter the lenght of the wardrobe ");
	scanf_s("%f", &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
	{
		printf("Size input error");
		return 1;
	}
	else
	{
		h = h / 100;
		w = w / 100;
		d = d / 100;
		n = h / 0.4;

		m_z = h * (w - 2 * th_DSP) * th_DVP * p_DVP;
		m_b = h * d * th_DSP * p_DSP * 2;
		m_k = (w - 2 * th_DSP) * (d - th_DVP) * th_DSP * p_DSP * 2;
		m_d = h * w * th_Tree * p_Tree;
		m_p = (w - 2 * th_DSP) * (d - th_DVP) * th_DSP * p_DSP * n;
		weight_carcas = m_z + m_b + m_k + m_d + m_p;

		printf("Weight of wardrobe %f", weight_carcas);
	}		
}