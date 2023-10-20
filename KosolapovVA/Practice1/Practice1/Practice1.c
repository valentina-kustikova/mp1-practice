#include <stdio.h>

int main()
{
    double h, w, d, m_closet, m_wardrobe,m_sidewalls,m_covers,m_doors,m_shelfs,i;
    double k = 0;
    do
    {
        printf("Input height:");
        scanf("%lf", &h);
    } while ((h < 180) || (h > 220));
    do
    {
        printf("Input width:");
        scanf("%lf", &w);
    } while ((w < 80) || (w > 120));
    do
    {
        printf("Input depth:");
        scanf("%lf", &d);
    } while ((d < 50) || (d > 90));
    double pDSP = 650, pDVP = 950, pTr = 660;
    m_wardrobe = ((h * w * 0.5)/1000000)*pDVP;
    m_sidewalls = (((h * d * 1.5)*2) / 1000000) * pDSP;
    m_covers = (((d * w * 1.5)*2) / 1000000) * pDSP;
    m_doors = ((h * w * 1) / 1000000) * pTr;
    i = h;
    while (i >= 40)
    {
        k++;
        i = i - (40 + 1.5);
    }
    m_shelfs = ((k * ((w - 3) * d * 1.5)) / 1000000) * pDSP;
    m_closet = m_wardrobe + m_sidewalls + m_covers + m_doors + m_shelfs;
    printf("m = %lf", m_closet);
    return 0;
}