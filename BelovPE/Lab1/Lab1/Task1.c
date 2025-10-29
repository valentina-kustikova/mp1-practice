#include <stdio.h>
#include <locale.h>

#define p_dvp 735 //плотность ДВП
#define p_dcp 800 //плотность ДСП
#define p_tree 700 //плотность дерева(дуб)

int main(void) {
	double h, w, d;
	setlocale(LC_ALL, "");
	printf("Введите высоту, ширину и глубину шкафа в см в отдельных строках:\n");
	do {
		scanf_s("%lf", &h);
	} while (h < 180 || h > 220);

	do {
		scanf_s("%lf", &w);
	} while (w < 80 || w > 120);

	do {
		scanf_s("%lf", &d);
	} while (d < 50 || d > 90);

	double Mback_wall, Mrl_wall, Mhl_wall, Mdoors, Mshelves;
	Mback_wall = (((h * w) / 10000) * 0.005) * p_dvp;
	Mrl_wall = (((h * d) / 10000) * 0.015) * p_dcp;
	Mhl_wall = ((((w * d) / 10000) * 0.015)) * p_dcp;
	Mdoors = (((h * w) / 10000) * 0.01) * p_tree;
	Mshelves = ((((w * d) / 10000) * 0.015)) * p_dcp * ((h / 40) - 1);

	printf("Масса шкафа: %.3lf", Mback_wall + Mrl_wall + Mhl_wall + Mdoors + Mshelves);

	return 0;
}