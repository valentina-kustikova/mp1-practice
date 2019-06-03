#include <stdio.h>
#include <math.h>

void main()
{
    double x1, x2, y1, y2, r1, r2, d;

    printf("Vvedite koordinati i radius pervoi ocrujnosti \n");
    scanf("%lf %lf %lf", &x1, &y1, &r1);

    if (r1 <= 0)
    {
        printf("Ne correctnie dannie");
        return;
    }

    printf("Vvedite koordinati i radius vtoroi ocrujnosti \n");
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    if (r2 <= 0)
    {
        printf("Ne correctnie dannie");
        return;
    }

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if ((d == 0) && (r1 == r2))
    {
        printf("Ocrujnosti sovpadaut \n");
        return;
    }

    if (d > (r1 + r2))
    {
        printf("Obshie tochki otsutstvuut - odna ocrujnost lejit vne drugoi \n");
        return;
    }

    if (d == (r1 + r2))
    {
        printf("Vneshnee kasanie \n");
        return;
    }

    if ((d == (fabs(r1 - r2))) && (r1 != r2))
    {
        printf("Vnutrenee kasanie \n");
        return;
    }

    if (d < fabs(r1 - r2))
    {
        printf("Obshie tochki otsutstvuut - odna ocrujnost lejit v drugoi \n");
        return;
    }

    printf("Ocrujnosti imeut 2 obshie tochki \n");
    return;
}
