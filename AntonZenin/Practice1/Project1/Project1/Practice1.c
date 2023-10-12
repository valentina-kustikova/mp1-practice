#include <stdio.h>
#include <math.h>
int main()
{
    double H, W, D, N, M, P1 = 550, P2 = 950, P3 = 490, S1 = 0.005, S2 = 0.015, S3 = 0.01; // P1 - плотность ДСП = 550 кг/м^3, P2 - плотность ДВП = 950 кг/м^3
    int X;
    // P3 - плотность дерева = 490 кг/м^3, S1, S2, S3 - толщины в метрах. 
    printf("Input the height H of the cupboard in metres in the range from 1.8 to 2.2\n");
    do {
        scanf("%lf", &H);
    } while ((H < 1.8) || (H > 2.2));
    printf("Input the width W of the cupboard in metres in the range from 0.8 to 1.2\n");
    do {
        scanf("%lf", &W);
    } while ((W < 0.8) || (W > 1.2));
    printf("Input the depth D of the cupboard in metres in the range from 0.5 to 0.9\n");
    do {
        scanf("%lf", &D);
    } while ((D < 0.5) || (D > 0.9));
    N = W / 2; // N - ширина двери, здесь ширина двери равна половине ширины шкафа.  
    X = (H / 0.4); // X - целое число полок
    M = (P2 * H * W * S1) + (2 * P1 * H * D * S2) + (2 * P1 * W * D * S2) + (2 * P3 * H * N * S3) + (X * P1 * S2 * D * (W - (2 * S2)));// (W - (2 * S2) - длина полки
    printf("The mass of the cupboard M in kilograms = %lf\n", M); // масса шкафа в килограммах
    return 0;
}