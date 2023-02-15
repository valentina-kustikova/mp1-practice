#include <stdio.h>
#include <math.h>

int main() {
    double h, w, d, m_dsp, m_dvp, m_wood, res_M;
    int num_of_shelves, GAP = 40; //gap - промежуток между полками
    double D_WOOD = 0.55, D_DSP = 0.65, D_DVP = 0.8; // Константы плотности в г/см^3

    printf("Enter every sizes in sm!!! in order: height, width, depth\n");
    scanf_s("%lf%lf%lf", &h, &w, &d);

    if (w > 120 || w < 80 || d > 90 || d < 50 || h > 220 || h < 180) {
        printf("Data is incorrect");
        return 1;
    }

    num_of_shelves = ceil(h / (double)GAP) - 1; // толщина полок не учитывается, считается = 0 
    // Если у верхней полки есть хоть какое-то расстояние до верхней крыжки - полку можно поставить

    // просчитаем массы частей в граммах!
    m_dsp = (2 * h * d * 1.5 + 2 * (w - 3) * d * 1.5 + num_of_shelves * 1.5 * d * (w - 3)) * D_DSP; // две боковины, верхняя и нижняя крышка, полки
    m_dvp = (h * w * 0.5) * D_DVP; // Задняя стенка
    m_wood = (h * w) * D_WOOD;

    // общая масса в КГ
    res_M = (m_dsp + m_dvp + m_wood) / 1000;
    printf("Your wardrobe weighs: %lf kg", res_M);

    return 0;
}