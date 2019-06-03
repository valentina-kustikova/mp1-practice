#include <stdio.h>

int main() {
    float DensityDVP = 0, DensityDSP = 0, DensityWood = 0; //  kg/m3
    float h, w, d, result;
    int NumberOfShelves;
    float Zadnya, Bokovina, Krishka, Dveri, Polki;
    printf("Enter the density of DVP ");
    scanf("%f", &DensityDVP);
    printf("\n");
    printf("Enter the density of DSP ");
    scanf("%f", &DensityDSP);
    printf("\n");
    printf("Enter the density of wood ");
    scanf("%f", &DensityWood);
    printf("\n");
    printf("Enter the height of the wardrobe (from 180 to 220 cm) ");
    scanf("%f", &h);
    printf("\n");
    if (h < 180 || h > 220) return;
    printf("Enter the width of the wardrobe (from 80 to 120 cm) ");
    scanf("%f", &w);
    printf("\n");
    if (w < 80 || w > 120) return;
    printf("Enter the depth of the wardrobe (from 50 to 90 cm) ");
    scanf("%f", &d);
    printf("\n");
    if (d < 50 || d > 90) return;
    h /= 100;
    w /= 100;
    d /= 100;
    NumberOfShelves = (h - 2 * 0.015) / (0.4 + 0.015);
    Zadnya = h * w * 0.005 * DensityDVP;
    Bokovina = h * d * 0.015 * DensityDSP;
    Krishka = w * d * 0.015 * DensityDSP;
    Dveri = h * w * 0.01 * DensityWood;
    Polki = NumberOfShelves * (w - 2 * 0.015) * (d - 0.005) * 0.015 * DensityDSP;
    result = Zadnya + 2 * Bokovina + 2 * Krishka + Dveri + Polki;
    printf("Weight of the wardrobe is %f kg \n", result);
    return 0;
}