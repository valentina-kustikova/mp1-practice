#include<stdio.h>
#include<math.h>
void main()
{
	double r1, r2, x1, x2, y1, y2, r_megdu_centrami;
	printf("Vvedite: r1 (r1 > 0), r2 (r2 > 0), x1, x2, y1, y2\n");
	scanf_s("%lf %lf %lf %lf %lf %lf", &r1, &r2, &x1, &x2, &y1, &y2);
	r_megdu_centrami = sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
	if ((r1 <= 0) || (r2 <= 0))
	{
		printf("Ne sushestvuet(-ut)\n");
		return;
	}

	if ((x1 == x2) && (y1 == y2) && (r1 == r2)) 
	{
		printf("Sovpadaut (beskonechno mnogo obshih tochek)\n");
		return;
	}

	if (r_megdu_centrami > (r1 + r2))
	{
		printf("Ne imeut nichego obshego (0 obshih tochek)\n");
		return;
	}

	if (r_megdu_centrami == (r1 - r2))
	{
		printf("Kasautsya i odna vnutry drugoy (1 obshaya tochka)\n");
		return;
	}

	if (r_megdu_centrami == (r1 + r2))
	{
		printf("Kasautsya i odna ne vnutry drugoy (1 obshaya tochka)\n");
		return;
	}

	if (r_megdu_centrami < (r1 - r2))
	{
		printf("Odna vnutry drugoy i ne kasautsya (0 obshih tochek)\n");
	}
	else printf("Peresekautsya (2 obshie tochki)\n");
}