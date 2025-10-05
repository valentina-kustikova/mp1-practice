#include <stdio.h>

// плотность дсп 650
// плотность двп 800 
// плотность сосны 500 

int main() {
    int h, w, d;
    float dsp, dvp, wood, s1 = 0.005, s2 = 0.015, s3 = 0.01;
    scanf_s("%f %f %f ", &dsp, &dvp, &wood);
    do {
        scanf_s("%d %d %d", &h, &w, &d);
    } while (h <= 180 || h >= 220 || w <= 80 || w >= 120 || d <= 50 || d >= 90);
    // перевод в метры
    float h_m = h / 100.0;
    float w_m = w / 100.0;
    float d_m = d / 100.0;

    float wall_dvp = h_m * w_m * s1; // задняя стенка
    float mass_wall = wall_dvp * dvp;

    float sidewall_dsp = h_m * d_m * s2; // 2 боковины
    float mass_sidewalls = 2 * sidewall_dsp * dsp;

    float cap_dsp = w_m * d_m * s2; // 2 крышки
    float mass_caps = 2 * cap_dsp * dsp;

    float door_wood = h_m * (w_m / 2) * s3; // 2 двери 
    float mass_doors = 2 * door_wood * wood;

    int count_shelf_dsp = (int)(h_m * 100) / 40; // полки
    float shelf_dsp = w_m * d_m * s2;
    float mass_shelves = count_shelf_dsp * shelf_dsp * dsp;

    float total_mass = mass_wall + mass_sidewalls + mass_caps + mass_doors + mass_shelves;
    printf("%f", total_mass);
    return 0;
}