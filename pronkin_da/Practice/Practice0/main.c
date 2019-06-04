#include <stdio.h>
#include <math.h>

void main() {
    float x1, x2, y1, y2, r1, r2, rc;
    printf("Vvedite x u y centri okryznosti u r radius okryznosti");
    scanf("%f %f %f", &x1, &y1, &r1);
    scanf("%f %f %f", &x2, &y2, &r2);
    rc = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (rc > fabs(r1 - r2) && rc < r1 + r2)
    {
        printf("Okryznosti peresekaytsi");
        return;
    }
    if (rc < fabs(r1 - r2))
    {
        printf("Odna okryznost lezit vnytri drygoy");
        return;
    }
    if (rc > r1 + r2)
    {
        printf("Okryznosti lezat na rasstoinii dryg ot dryga u ne peresekaytsi");
        return;
    }
    if (rc == r1 + r2)
    {
        printf("Okryznosti kasaytsi vneshnim obrazom");
        return;
    }
    if (rc == fabs(r1 - r2))
    {
        printf("Okryznosti kasaytsi vnytrennim obrazom");
        return;
    }
}
