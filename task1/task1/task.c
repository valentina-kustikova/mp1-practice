#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    float h, w, d, d_dsp, d_dvp, d_wood, Weight, cnt_shelf = 4, W_wall, W_2side, W_2roof, W_door, W_shelf, t_dsp = 1.5, t_dvp = 0.5, t_wood = 1.0;

    do {
        printf("Введите высоту (180-220 см), ширину (80-120 см) и глубину (50-90 см):\n ");
        scanf_s("%f%f%f", &h, &w, &d);

        printf("Введите плотность ДСП, ДВП и дерева: \n");
        scanf_s("%f%f%f", &d_dsp, &d_dvp, &d_wood);

    } while ((h < 180 || h > 220) || (w < 80 || w > 120) || (d < 50 || d > 90) || (d_dsp <= 0) || (d_dvp <= 0) || (d_wood <= 0));

    W_wall = (h / 100) * (w / 100) * (t_dvp / 100) * d_dvp;
    W_2side = 2 * (h / 100) * (d / 100) * (t_dsp / 100) * d_dsp;
    W_2roof = 2 * (w / 100) * (d / 100) * (t_dsp / 100) * d_dsp;
    W_door = 2 * (h / 100) * (w / 100) * (t_wood / 100) * d_wood;
    if (h >= 200) {
        cnt_shelf += 1;
    }
    W_shelf = cnt_shelf * (w / 100) * (d / 100) * (t_dsp / 100) * d_dsp;
    Weight = W_wall + W_2side + W_2roof + W_door + W_shelf;
    printf("Общая масса шкафа = %f кг", Weight);
    return 0;
}
