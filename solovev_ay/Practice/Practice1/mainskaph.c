#include <stdio.h>
#include <locale.h>
void main()
{
    float h, w, d, rodvp, rodsp, rodereva, m, mstenki, mbokovin, mkrishki, mdverei, mpolok;
    setlocale(LC_ALL, "Russian");
    printf("Вычисление массы двухдверного шкафа фирмы Умелые ручки\n");
    printf("Введите высоту и ширину задней стенки шкафа в метрах!\n");
    printf("Высота:");
    scanf("%f", &h);
    printf("%f", h);
    if ((h < 1.8) || (h > 2.2))
    {
        printf("Ошибка!\nВысота должна быть от 1,8 м до 2,2 м!");
        return;
    }
    printf("Ширина:");
    scanf("%f", &w);
    if ((w < 0.8) || (w > 1.2))
    {
        printf("Ошибка!\nШирина должна быть от 0,8 м до 1,2 м!\n");
        return;
    }
    printf("Параметры вашей задней накладной стенки шкафа:%.3f x%.3f\n", h, w);
    printf("Введите глубину боковин в метрах:");
    scanf("%f", &d);
    if ((d < 0.5) || (d > 0.9))
    {
        printf("Ошибка!\nГлубина должна быть от 0,5 до 0,9 м.");
        return;
    }
    printf("Параметры вашей боковины:%.3f x %.3f\n", h, d);
    printf("Параметры ваших нижней и верхней крышек:%.3f x %.3f\n", w, d);
    printf("Параметры вашей двери:%.3f x %.3f\n", h, w/2);
    printf("Введите плотность дерева в кг/м^3:");
    scanf("%f", &rodereva);
    printf("Введите плотность ДСП в кг/м^3:");
    scanf("%f", &rodsp);
    printf("Введите плотность ДВП в кг/м^3:");
    scanf("%f", &rodvp);
    mstenki = rodvp * h * w * 0.005;
    mbokovin = 2 * h * d * 0.015 * rodsp;
    mkrishki = 2 * w * d * 0.015 * rodsp;
    mdverei = 0.01 * h * w * rodereva;
    mpolok = rodsp * (h - 2 * 0.015) / (0.4 + 0.015) * (w - 2 * 0.015) * (d - 0.005) * 0.015;//объем полки это глубина без боковин
    m = mstenki + mbokovin + mkrishki + mdverei + mpolok;
    printf("Масса шкафа:=%.3f килограмм!\n", m);
    return;
}
