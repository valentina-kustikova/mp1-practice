#include <locale.h>
#include <math.h>
#include <stdio.h>

void main() 
{
    float h, w, d, VZad, VBok, VKrish, VDver, VPolk, Massa, pDSP, pDVP, pDer;
    setlocale(LC_ALL, "Russian");
    printf("Добро пожаловать в РасчетчикМассы v1.0.\n Надеемся, что Вы ознакомились с предельными значениями размеров габаритов Вашего будущего шкафа.\n");
    printf("Введите высоту шкафа в cм\n");
    scanf("%f", &h);
    if ((h < 180) || (h > 220)) 
    {
        printf("Введена неверная высота");
        return;
    }
    printf("Введите ширину шкафа в cм\n");
    scanf("%f", &w);
    if ((w < 80) || (w > 120)) 
    {
        printf("Введена неверная ширина");
        return;
    }
    printf("Введите глубину шкафа в cм\n");
    scanf("%f", &d);
    if ((d < 50) || (d > 90)) 
    {
        printf("Введена неверная глубина");
        return;
    }
    printf("Введите плотности ДСП, ДВП и дерева по очереди через пробел(в кг/м^3)\n");
    scanf("%f %f %f", &pDSP, &pDVP, &pDer);
    if ((pDSP <= 0) || (pDVP <= 0) || (pDer <= 0)) 
    {
        printf("Одно из введенных значений плотности неверно. Повторите ввод данных");
        return;
    }
    VZad = w / 100 * h / 100 * 0.005;
    VBok = 2.0f * h / 100 * d / 100 * 0.015;
    VKrish = 2.0f * w / 100 * d / 100 * 0.015;
    VDver = w / 100 * h / 100 * 1.0f;
    VPolk = floor((h / 100 - 2 * 0.015) / (0.4 + 0.015)) * (w / 100 - 2.0f * 0.015) * (d / 100 - 0.005);
    Massa = VZad * pDVP + VBok * pDSP + VKrish * pDSP + VDver * pDer + VPolk * pDSP;
    printf("Масса вашего шкафа равна %.2f кг\n", Massa);
}