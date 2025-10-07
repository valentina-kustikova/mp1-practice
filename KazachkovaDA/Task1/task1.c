//190 80 50 - 62.434998
//195 100 70 - 96.000
//200 90 55 - 80.381256
#include <stdio.h>
int main() {
    float m_zadn, m_bok, m_crysh, m_dver, m_polki, Ro_DVP, Ro_DSP, Ro_der, t_DVP, t_DSP, t_der;
    int h, w, d;
    t_DVP = 0.5f;
    t_DSP = 1.5f;
    t_der = 1;
    Ro_DVP = 0.00085f;
    Ro_DSP = 0.00075f;
    Ro_der = 0.0005f;

    do
    {
        printf_s("Vvedite vysotu h d cm ");
        scanf_s("%d", &h);
    } while (h > 200 || h < 180);

    do   
    {   
        printf_s("Vvedite shirinu w v cm ");
        scanf_s("%d", &w);
    } while (w > 120 || w < 80);

    do
    {
        printf_s("VVedite glubinu d v cm ");
        scanf_s("%d", &d);
    } while (d > 90 || d < 50);
    
    m_zadn = h * w * t_DVP * Ro_DVP;
    m_bok = h * d * t_DSP * 2 * Ro_DSP;
    m_crysh = w * d * t_DSP * 2 * Ro_DSP;
    m_dver = h * w * t_der * Ro_der;
    m_polki = t_DSP * w * d * (h / 40) * Ro_DSP;

    printf_s("Massa shkafa = %f", m_zadn + m_bok + m_crysh + m_dver + m_polki);
    return 0;
}