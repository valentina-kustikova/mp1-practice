#include <stdio.h>
#include <math.h>

void main()
{
    float x1, y1, r1, x2, y2, r2, rt, dist;
    scanf("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
    dist = sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    rt = r1 + r2;
    if ((r1 <= 0) || (r2 <= 0))
    {
        printf("Ne suschestvujet\n");
        return;
    }
    if (x1 == x2 && y1 == y2 && r1 == r2)
    {
        printf("Sovpadajut\n");
        return;
    }
    if (dist > rt)
    {
        printf("Ne peresekajutsja\n");
        return;
    }
    if (dist == rt)
    {
        printf("Kasajutsja\n");
        return;
    }
    if ((dist + r2) < r1 || (dist + r1) < r2)
    {
        printf("Vkljuchena\n");
        return;
    }
    if ((r1 > dist && (dist + r2) == r1) ||
        (r2 > dist && (dist + r1) == r2))
    {
        printf("Kasajutsja iznutri\n");
        return;
    }
    printf("Peresekajutsja\n");
}