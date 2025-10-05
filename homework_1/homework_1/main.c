#include <stdio.h>

int main() {
    int dvp = 800, dsp = 650, wood = 700;
    float h, w, d, weight_1, weight_2, weight_3, weight_4, weight_5, weight;
    do {
        printf("Enter h, w, d\n");
        scanf_s("%f %f %f", &h, &w, &d);
    } while ((1.8 > h) || (h > 2.2) || (0.8 > w) || (w > 1.2) || (0.5 > d) || (d > 0.9));
    weight_1 = h * w * 0.005 * dvp;
    weight_2 = 2 * (h * d * 0.015 * dsp);
    weight_3 = 2 * (w * d * 0.015 * dsp);
    weight_4 = h * w * 0.01 * wood;
    if (2 <= h) {
        weight_5 = (w * d * 0.01 * dsp) * 5;
    }
    else {
        weight_5 = (w * d * 0.01 * dsp) * 4;
    }
    weight = weight_1 + weight_2 + weight_3 + weight_4 + weight_5;
    printf("weight = %f kg", weight);
    return 0;
}

