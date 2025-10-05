#include <stdio.h>
#include <math.h>

int main() {
    int dsp = 670, dvp = 820, der = 600;
    float h, w, d;
    float m, m_nakl, m_2bokovin, m_krshk, m_dver2, m_polk;
    float t_dsp = 0.015, t_dvp = 0.005, t_dver = 0.01;
    do {
        printf("Enter h ot 1.8 do 2.2, w ot 0.8 do 1.2, d ot 0.5 do 0.9, vse v metrax\n");
        scanf_s("%f %f %f", &h, &w, &d);
    } while ((1.8 > h)|| (h > 2.2) || (0.8 > w) ||  (w > 1.2)||  (0.5 > d) || (d > 0.9));
    m_nakl = h * w * t_dvp * dvp;
    m_2bokovin = 2 * h * d * t_dsp * dsp;
    m_krshk = 2 * w * d * t_dsp * dsp;
    m_dver2 = 2 * h * (w / 2) * t_dver * der;
    m_polk = floor((h - t_dsp * 2) * 100 / 40) * w * d * t_dsp * dsp;
    m = m_nakl + m_2bokovin + m_krshk + m_dver2 + m_polk;
    printf("massa = %f", m);
    return 0;
}