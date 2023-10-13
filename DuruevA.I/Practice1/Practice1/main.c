#include<stdio.h>
#include<math.h>

int main(void)
{
    float k, Tdvp, Tdsp, Td, m1, h, w, Pdvp, Pdsp, Pd, d;

    Pdvp = 950;                    // ��������� ���
    Pdsp = 650;                   // ��������� ���
    Pd = 660;                    // ��������� ������
    Tdvp = 0.005;                // ������� ���
    Tdsp = 0.015;              // ������� ���
    Td = 0.01;                // ������� ������
    k = 0;                   // �������

    printf("Input h,w,d \n");
    scanf("%f,%f,%f", &h, &w, &d);
    while ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90)) {
        printf("Input h,w,d \n");
        scanf("%f,%f,%f", &h, &w, &d);
    }
    h = h * 0.01;
    w = w * 0.01;
    d = d * 0.01;
    m1 = (h * w * Tdvp * Pdvp) + (2 * h * d * Tdsp * Pdsp) + (2 * w * d * Tdsp * Pdsp) + (Td * h * w * Pd);
    h = h - 2 * Tdsp;
    while (h > 0.4) {
        h = h - 0.4;
        k = k + 1;
    }
    m1 = m1 + k * ((w- 2 * Tdsp) * d * Tdsp * Pdsp);
    printf("Cabinet Weight = ");
    printf("%f", m1);
    return 0;
}
