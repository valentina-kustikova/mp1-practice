#include <stdio.h>
#include <math.h>
void main()
{
	double h, w, d, pder, pdvp, pdsp, mzst, mbok, mvn, md, mp, M;
	printf ("Vvedite h, w, d");
	scanf ("%lf %lf %lf", &h, &w, &d);
	printf ("Vvedite znacheniya plotnostey dereva, DVP i DSP"); 
	scanf ("%lf %lf %lf", &pder, &pdvp, &pdsp);
	{
		if ((h >= 1.8) && (h <= 2.2) && (w >= 0.8) && (w <= 1.2) && (d >= 0.5) && (d <= 0.9))
		{
			mzst = (h * w * 0.005 * pdvp);
			mbok = (h * d * 0.015 * pdsp);
			mvn = (w * d * 0.015 * pdsp);
			md = (h * w * 0.01 * pder);
			mp = (floor((h - 2 * 0.015) / (0.4 + 0.015)) * (w - 2 * 0.015) * (d - 0.005) * 0.015 * pdsp);
			M = (mzst + mbok + mvn + md + mp);
	                printf ("Massa shkapha %lf kg", M);
		}
		else 
		{
			printf("Vvedennye dannye ne korrektny");
		}
	}
}
