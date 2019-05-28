#include <stdio.h>
#include <math.h>
#include <locale.h>
void main() {
    float pDVP, pDSP, pDER, h, w, d, tDVP, tDSP, tDER;//исходные данные: плотности, высота, ширина, глубина, толщины
    float v1, v2, v3, v4, v5, m;//полученные объёмы и массы 
    int kol;//kol-количество полок
    setlocale(LC_ALL, "Rus");
    printf("введите высоту задней стенки(боковин,дверей)\n");
    scanf("%f", &h);
    h=h*0.01;//перевожу в систему си
    printf("введите ширину задней стенки(верхней,нижней крышки,дверей,полок)\n");
    scanf("%f", &w);
    w=w*0.01;
    printf("введите глубину боковин(крышек,полок)\n");
    scanf("%f", &d);
    d=d*0.01;
    printf("введите плотность ДВП,ДСП и дерева\n");
    scanf("%f %f %f", &pDVP, &pDSP, &pDER);
    tDVP=0.005;//милиметры перевожу в м
    tDSP=0.015;
    tDER=0.01;//см перевожу в м
    m = 0;
    v1 = h * w * tDVP;//объём задней стенки
    m = m + v1 * pDVP;
    v2 = h * d * tDSP;//объём 1ой боковины
    m = m + 2 * v2 * pDSP;
    v3 = w * d * tDSP;//объем 1ой крышкки
    m = m + 2 * v3 * pDSP;
    v4 = h * w * tDER;//обём 1ой дверцы
    m = m + v4 * pDER;
    v5 = (h - 2 * tDSP) / (0.4 + tDSP) * (w - 2 * tDSP) * (d - tDVP);//объём всех полок
    m = m + v5 * pDSP;
    printf("масса шкафа %f\n", m,"\n");

}