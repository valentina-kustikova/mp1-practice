#include <stdio.h>
#include <math.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Rus");
    int dvp = 950, dsp = 650, wood = 660;
    float m; // m  - масса
    float h, w, d, m1, m2, m3, m4, m5;
    float w_polok, m_polok; // ширина и масса полок

    printf("Введите высоту, ширину и глубину(высота от 180 до 220 см, ширина от 80 до 120 см, глубина от 50 до 90 см):\n");
    scanf("%f %f %f", &h, &w, &d);
    while (h < 180 || h>220 || w < 80 || w>120 || d < 50 || d>90) {
        printf("Неверные данные. Попробуйте снова:\n");
        scanf("%f %f %f", &h, &w, &d);
    }
    //переводим в метры
    h /= 100; 
    w /= 100;
    d /= 100; 

    m1 = dvp * h * w * 0.005; // масса задней стенки
    m2 = 2 * dsp * h * d * 0.015; // масса двух боковин
    m3 = 2 * dsp * d * w * 0.015; // масса верхней и нижней крышки
    m4 = wood * h * 0.01 * w; // масса двух дверей
    w_polok = w - 0.015 * 2; // считаем толщину полки
    m5 = dsp * d * w_polok * 0.015; // масса одной полки

    int k_polok = 0;
    while (h > 0.415) {
        h = h - 0.4 - 0.015;
        k_polok++;
    }
    m_polok = m5 * k_polok;

    m = m1 + m2 + m3 + m4 + m_polok;

    printf("Масса шкафа %f кг", m);

    return 0;
}
