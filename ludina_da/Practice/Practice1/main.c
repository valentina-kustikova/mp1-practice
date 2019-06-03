#include <stdio.h>
#include <locale.h>

void main()
{
    int p1, p2, p3;
    float h, w, d, m1, m2, m3, m4, m5, M, a1 = 0.005f, a2 = 0.015f, a3 = 0.01f;
    int n;
    setlocale(LC_ALL, "Rus");
    printf("Введите высоту шкафа, см:");
    scanf("%f", &h);
    printf("Введите ширину шкафа, см:");
    scanf("%f", &w);
    printf("Введите глубину шкафа, см:");
    scanf("%f", &d);
    printf("Введите плотность ДВП: ");
    scanf("%d", &p1);
    printf("Введите плотность ДСП: ");
    scanf("%d", &p2);
    printf("Введите плотность дерева: ");
    scanf("%d", &p3);
    h /= 100.0f;
    w /= 100.0f;
    d /= 100.0f;
    if ((h >= 1.8f) && (h <= 2.0f))
    {
        n = 4;
    }
    else
    {
        n = 5;
    }
    if (((h >= 1.8f) && (h <= 2.2f)) && ((w >= 0.8f) && (w <= 1.2f)) && ((d >= 0.5f) && (d <= 0.9f)))
    {
        m1 = p1 * h * w * a1;
        m2 = 2 * p2 * h * d * a2;
        m3 = 2 * p2 * w * d * a2;
        m4 = 2 * p3 * h * w * a3;
        m5 = n * p2 * (d - a1) * (w - 2 * a2) * a2;
        M = m1 + m2 + m3 + m4 + m5;
        printf("Масса шкафа (кг) = %.2f\n", M);
    }
    else
    {
        printf("Введены неверные данные\n");
    }
}
