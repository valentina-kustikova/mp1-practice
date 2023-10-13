#include <stdio.h>

int main () {
    double h, h1 = 0, w, d, m_back, m_sides, m_topbottom, m_doors, c_shelves = 0, m_shelves, summ;
    double th_dvp = 5 * 0.001, th_dsp = 15 * 0.001, th_redtree = 10 * 0.001;
    int p_dvp = 820, p_dsp = 700, p_redtree = 660;
    printf ("Enter the height, width and depth of the wardrobe: ");
    scanf ("%lf %lf %lf", &h, &w, &d);

    if (h > 220 || h < 180) {
        do {
            printf("The height should be from 180 to 220 centimeters. Enter the height again: ");
            scanf("%lf", &h);
        } while (h > 220 || h < 180);
    }
    if (w > 120 || w < 80) {
        do {
            printf("The width should be from 80 to 120 centimeters. Enter the height again: ");
            scanf("%lf", &w);
        } while (w > 120 || w < 80);
    }
    if (d > 90 || d < 50) {
        do {
            printf("The depth should be from 50 to 90 centimeters. Enter the height again: ");
            scanf("%lf", &d);
        } while (d > 90 || d < 50);
    }

    h /= 100; /// перевод в си
    w /= 100; 
    d /= 100;

    m_back = h * w * th_dvp * p_dvp;
    m_sides = 2 * h * d * th_dsp * p_dsp;
    m_topbottom = 2 * w * d * th_dsp * p_dsp;
    m_doors = h * w * th_redtree * p_redtree;

    while (h1 < (h*100 - 41.5)) {
        h1 += 41.5;
        c_shelves += 1;
    }

    m_shelves = c_shelves * (w - 2 * th_dsp) * d * p_dsp * th_dsp;

    summ = m_back + m_sides + m_topbottom + m_doors + m_shelves;
    // printf ("c_shelves = %lf m_back = %lf m_sides = %lf m_topbottom = %lf m_doors = %lf m_shelves = %lf \n", c_shelves, m_back, m_sides, m_topbottom, m_doors ,m_shelves);
    printf ("Total weight of the wardrobe = %lf kg.", summ);
    return 0;
}