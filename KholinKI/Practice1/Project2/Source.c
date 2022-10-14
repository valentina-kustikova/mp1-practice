#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main() {
	float h, w, d, d_dvp = 850, d_dsp = 550, d_tree = 650;
	float m, m1, m2, m3, m4, m5;
	float tn1 = 5, tn2 = 15, tn3 = 10;
	int n;
	printf("Input values h,w,d "); /*dlina, shirina, glubina*/
	scanf("%f %f %f", &h, &w, &d);
	if (h < 180 || h > 220 || w > 120 | w < 80 || d < 50 || d > 90)
	{
		printf("Incorrect data");
		return 1;
	}
	else
	{					/*perevod v sistemu CI*/
		n = h / 40;
		h = h / 100;
		w = w / 100;
		d = d / 100;
		tn1 = tn1 / 1000; /*tolshina1*/
		tn2 = tn2 / 1000;  /*tolshina2*/
		tn3 = tn3 / 1000;  /*tolshina3*/

						/*PODSCHOT CHASTEY*/
		m1 = h * w * tn1 * d_dvp;
		m2 = 2 * (h * d * tn2 * d_dsp);
		m3 = 2 * (tn2 * w * d * d_dsp);
		m4 = 2 * (h * w * tn3 * d_tree);
		m5 = n * (d * w * tn2 * d_dsp);


						/*RESULTAT*/
		m = m1 + m2 + m3 + m4 + m5;
		printf("Mass of wardrobe= %f", m);
		getchar();
		return 0;
	}



}