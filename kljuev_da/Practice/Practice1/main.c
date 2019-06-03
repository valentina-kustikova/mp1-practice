#include <stdio.h>
#include <locale.h>

void main()
{
    float w, h, d, dvp, dsp, wood;
    float rp, side, lid, door, shelf, tm;
    setlocale(LC_ALL, "Rus");
    printf("Для расчёта массы шкафа введите:\nВысота (180 – 220 см), "
      "ширина (80 – 120 см), глубина (50 – 90 см)\n");
    scanf("%f %f %f", &h, &w, &d);
    if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90)
    {
        printf("Неверные данные\n");
        return;
    }
    printf("Введите плотности ДВП, ДСП, дерева (кг/м^3)\n\n");
    scanf("%f %f %f", &dvp, &dsp, &wood);
    if (dvp < 0 || dsp < 0 || wood < 0)
    {
        printf("Неверные данные\n");
        return;
    }
    h /= 100.f;
    w /= 100.f;
    d /= 100.f;
    rp = (h - 2 * 0.015f) * (w - 2 * 0.015f) * 0.005f * dvp;
    side = 2.f * (h - 2 * 0.015f) * (d - 0.005f) * 0.015f * dsp;
    lid = 2.f * w * d * 0.015f * dsp;
    door = w * h * 0.01f * wood;
    shelf = (int)((h - 2 * 0.015f) / (0.4 + 0.015f)) *
      (w - 2 * 0.015f) * (d - 0.005f) * 0.015f;
    tm = rp + side + lid + door + shelf;
    printf("\nПолная масса шкафа равна %.1f кг\n\n", tm);
}