#include <stdio.h>
#include <math.h>

void main()
{

    float x1, y1, r1, x2, y2, r2, d; // d-rasstoyanie mezhdu ñentrami okruzhnostej
    printf("Vvedite koordinaty pervoj okruzhnosti (x1, y1) i ee radius (r1): \n");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Vvedite koordinaty vtoroj okruzhnosti (x2, y2) i ee radius (r2): \n");
    scanf("%f %f %f", &x2, &y2, &r2);
    d = sqrtf(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

    if ((x1 == x2) && (y1 == y2) && (r1 == r2))
    {
        printf("Okruzhnosti polnost'yu ravny \n");
        return;
    }

    if (d + r1 < r2)
    {
        printf("Pervaya okruzhnost' lezhit vo vtoroj \n");
        return;
    }

    if (d + r2 < r1)
    {
        printf("Vtoraya okruzhnost' lezhit v pervoj \n");
        return;
    }

    if (d == (r1 + r2))
    {
        printf("Peresekayutsa vneshne v odnoy tochke \n");
        return;
    }

    if ((d + r2) == r1)
    {
        printf("Peresekaetsya v odnoy tochke, vtoroy vnutri pervogo \n");
        return;
    }

    if ((d + r1) == r2)
    {
        printf("Peresekaetsya v odnoy tochke, perviy vnutri vtorogo \n");
        return;
    }

    if (d > (r1 + r2))
    {
        printf("Okruzhnosti ne peresekayutsya i ne kasayutsya \n");
        return;
    }

    printf("Okruzhnosti peresekayutsya i imeyut dve obshie tochki \n");
}
