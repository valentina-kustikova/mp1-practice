#define _CRT_SECURE_NO_WARNINGS // not to use scanf_s
#include <stdio.h>
#include <math.h>


void main()
{
    double r1, r2, c1x, c1y, c2x, c2y, dist;
    r1 = 0; r2 = 0; c1x = 0; c2x = 0; c1y = 0; c2y = 0; dist = 0;

    while ((r1 <= 0) || (r2 <= 0))
    {
        printf("enter r1 and r2 for circles \n");
        scanf("%lf%lf", &r1, &r2);
    }

    printf("enter X and Y of 1 center \n");
    scanf("%lf%lf", &c1x, &c1y);

    printf("enter X and Y of 2 center \n");
    scanf("%lf%lf", &c2x, &c2y);
    
    dist = sqrt((c1x - c2x) * (c1x - c2x) + (c1y - c2y) * (c1y - c2y));
    printf("Distance between centers = %lf\n", dist);


    // match
    if ((c1x == c2x) && (c1y == c2y) && (r1 = r2)) 
    {
        printf("circles match \n");
    }
    else
    // no common dots
        //outside
        if (dist > r1 + r2)
        {
            printf("no common dots \n");
            printf("one outside another \n");
        }
        else
        //inside
            if (dist < abs(r1 - r2))
            {
                printf("no common dots \n");
                printf("one inside another \n");
                if (dist == 0) printf("concentric circles \n");
            }
            else
            // touching
                // inside
                if (dist == abs(r1 - r2))
                {
                    printf("one touches another internally \n");
                }
                else
                //outside
                    if (dist == r1 + r2)
                    {
                    printf("one touches another externally \n");
                    }
                    else
                        // intersect
                        if (dist > abs(r1 - r2) && dist < (r1 + r2))
                            printf("two common dots \n");
                        else
                        // any other case is error
                            printf("error \n");
}
