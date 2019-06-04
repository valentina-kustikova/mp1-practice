#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Header.h"

void main ()
{
	int nn, vybor;
	double len1, len2, u;
	Vector *v, *vv, *s, *ss;
	printf("Vvedi dlinu vectorov\n");
	scanf("%d", &nn);
	printf("Dlina vectorov %d \n", nn);
	printf("Vector v\n");
	v = Add(nn);
	Fill(v);
	Print(v);
	printf("Vector vv\n");
	vv = Add(nn);
	Fill(vv);
	Print(v);
	do
	{
		printf("\n 1) Slozhit vectory\n 2) Vychest vectory\n 3) Skalyarnoe proizvedenie\n ");
		printf("4) Rasschitat dlinu vectora\n 5) Rasschitat ugol mezhdu vectorami\n 6) Udalit vectory\n 7) Zakonchit\n");
		scanf("%d", &vybor);
		switch(vybor)
		{
			case 1:
				printf("v + vv \n");
				s = Add(nn);
				Sum(v, vv, s);
				break;
			case 2:
				printf("v - vv \n");
				ss = Add(nn);
				Sub(v, vv, ss);
				break;
			case 3:
				Com(v, vv);
				break;
			case 4:
				len1 = Length(v);
				printf("Length v is %lf\n", len1);
				len2 = Length(vv);
				printf("Length vv is %lf\n", len2);
				break;
			case 5:
				u = Angle(v, vv);
				printf("Angle is %lf", u);
				break;
			case 6:
				Delete(v);
				Delete(vv);
				break;
		}
	}
	while (vybor != 7);

	free(v);
	free(vv);
	free(s);
	free(ss);
}
