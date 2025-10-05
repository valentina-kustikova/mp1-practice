#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	float h, w, d;
	setlocale(LC_ALL, "RUS");
	do {
		scanf_s("%f %f %f", &h, &w, &d);
	} while ((h > 220 | h < 180) | (w > 120 | w < 80) | (d > 90 | d < 50));
	
	const float p_dsp = 735;
	const float p_dvp = 800;
	const float p_der = 700;
	const float tol_5 = 0.005;
	const float tol_15 = 0.015;
	const float tol_10 = 0.01;

	int kol_pol;
	if (fmod(h, 40) == 0) {
		kol_pol = (h / 40) - 1;
	}
	else {
		kol_pol = floor(h / 40);
	}

	h = h / 100.0;
	w = w / 100.0;
	d = d / 100.0;
	
	float V_zs = h * w * tol_5;
	float V_bok = 2 * (h * d * tol_15);
	float V_kr = 2 * (w * d * tol_15);
	float V_dv = h * w * tol_10;
	float V_pol = kol_pol * (w * d * tol_15);
    
	float massa = (V_zs * p_dvp) + (V_bok * p_dsp) + (V_kr * p_dsp) + (V_dv * p_der) + (V_pol * p_dsp);

	printf("Масса шкафа = %f", massa);

	return 0;
}