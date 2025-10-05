#include <stdio.h>

// ��������� ��� 650
// ��������� ��� 800 
// ��������� ����� 500 

int main() {
    int h, w, d;
    float dsp, dvp, wood, s1 = 0.005, s2 = 0.015, s3 = 0.01;
    scanf_s("%f %f %f ", &dsp, &dvp, &wood);
    do {
        scanf_s("%d %d %d", &h, &w, &d);
    } while (h <= 180 || h >= 220 || w <= 80 || w >= 120 || d <= 50 || d >= 90);
    // ������� � �����
    float h_m = h / 100.0;
    float w_m = w / 100.0;
    float d_m = d / 100.0;

    float wall_dvp = h_m * w_m * s1; // ������ ������
    float mass_wall = wall_dvp * dvp;

    float sidewall_dsp = h_m * d_m * s2; // 2 ��������
    float mass_sidewalls = 2 * sidewall_dsp * dsp;

    float cap_dsp = w_m * d_m * s2; // 2 ������
    float mass_caps = 2 * cap_dsp * dsp;

    float door_wood = h_m * (w_m / 2) * s3; // 2 ����� 
    float mass_doors = 2 * door_wood * wood;

    int count_shelf_dsp = (int)(h_m * 100) / 40; // �����
    float shelf_dsp = w_m * d_m * s2;
    float mass_shelves = count_shelf_dsp * shelf_dsp * dsp;

    float total_mass = mass_wall + mass_sidewalls + mass_caps + mass_doors + mass_shelves;
    printf("%f", total_mass);
    return 0;
}