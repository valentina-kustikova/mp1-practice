#include <math.h>
#include <stdio.h>

void main()
{
    double r1, r2, x1, x2, y1, y2;
    double R;   //Radius mejdu centrami okrujnostey. Vichislyaem ego po T.Pifagora
    printf("Vvedite: r1 (r1 > 0), r2 (r2 > 0), x1, x2, y1, y2\n");
    scanf("%lf %lf %lf %lf %lf %lf", &r1, &r2, &x1, &x2, &y1, &y2);
    R = sqrt(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));

    if ((r1 <= 0) || (r2 <= 0))
    {
        printf("Neverni vvod(okrujnost(i) ne sushestvuyt)\n");
        return;
    }

    if (R > (r1 + r2))
    {
        printf("Ne imeut obshih tochek\n");
        return;
    }

    if (R == (r1 + r2))
    {
        printf("Okrujnosti kasautcya, odna okr. ne vnutri drugoy\n");
        return;
    }

    if (R == fabs(r1 - r2))
    {
        printf("Okrujnosti kasautcya, odna okr. vnutri drugoy\n");
        return;
    }

    if (R < fabs(r1 - r2))
    {
        printf("Net obshih tochek, odna okr. vnutri drugoy\n");
        return;
    }

    if ((r1 == r2) && (x1 == x2) && (y1 == y2))
    {
        printf("Okrujnosti sovpadaut, y nih beskonechno mnogo obshih tochek\n");
        return;
    }

    else
    {
        printf("Peresecautcya v 2-uh obshih tochkah\n");
        return;
    }
}