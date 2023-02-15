#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main() {
	float h, w, d, t_zad, t_side, t_top_bottom, t_door, t_shelf, m_zad, m_side, m_top_bottom, m_door, m_shelf, distance_shelf, m_cabinet, count_shelf;
	int count;
	float density_dsp = 800;
	float density_dvp = 750;
	float density_tree = 640;
	printf("Enter the height of the cabinet (from 180 to 220 cm): ");
	scanf("%f", &h);
	if ((h < 180) || (h > 220))
	{
		printf("You entered incorrect data (from 180 to 220 cm).");
		return 0;
	}
	h = h / 100;
	printf("Enter the width of the cabinet: (from 80 to 120 cm): ");
	scanf("%f", &w);
	if ((w < 80) || (w > 120))
	{
		printf("You entered incorrect data (from 80 to 120 cm).");
		return 0;
	}
	w = w / 100;
	printf("Enter the depth of the cabinet: (from 50 to 90 cm): ");
	scanf("%f", &d);
	if ((d < 50) || (d > 90))
	{
		printf("You entered incorrect data (from 50 to 90 cm).");
		return 0;
	}
	d = d / 100;
	t_zad = 0.005;
	t_side = 0.015;
	t_top_bottom = 0.015;
	t_door = 0.01;
	t_shelf = 0.015;
	distance_shelf = 0.4;
	m_zad = density_dvp * h * w * t_zad;
	m_side = 2 * density_dsp * h * d * t_side;
	m_top_bottom = 2 * density_dsp * (w-0.03) * d * t_top_bottom;
	m_door = density_tree * h * w * t_door;
	count_shelf = h / 0.415 - 1.015;
	count = (int)count_shelf;
	m_shelf = count * density_dsp * (w-0.03) * d * t_shelf;
    m_cabinet = m_zad + m_side + m_top_bottom + m_door + m_shelf;
	printf("Cabinet weight : %f", m_cabinet);
	return 0;
}