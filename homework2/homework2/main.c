#include <stdio.h>
#include <locale.h>

int main() {
    float h, w, d, pdvp = 900, pdsp = 600, pder = 650, tz = 0.005, tb = 0.015, tvn = 0.015, r = 0.4, td = 0.01, tp = 0.01, m = 0;
    int k;
    setlocale(LC_ALL, "RUS");

    printf("Введите высоту, ширину и глубину:\n");
    scanf_s("%f %f %f", &h, &w, &d);
    k = h / 40;
    if (!((h >= 180 && h <= 220) || (w >= 80 && w <= 120) || (d >= 50 && d <= 90))) {
        printf("Введены некорректные данные");
        return 1;
    }
    if ((h >= 180 && h <= 220) && (w >= 80 && w <= 120)) {
        m += (h * w * tz * pdvp);
    }
    if ((w >= 80 && w <= 120) && (d >= 50 && d <= 90)) {
        m += (2 * w * d * tvn * pdsp);
    }
    if ((h >= 180 && h <= 220) && (d >= 50 && d <= 90)) {
        m += (2 * h * d * tb * pdsp);
    }
    if ((h >= 180 && h <= 220) && (w >= 80 && w <= 120)) {
        m += (h * w * td * pder);
    }
    if ((d >= 50 && d <= 90) && (w >= 80 && w <= 120)) {
        m += (k * d * w * pdsp * tp);
    }
    printf("Масса шкафа равна:\n");
    printf("m = %f\n", m);
    return 0;
}