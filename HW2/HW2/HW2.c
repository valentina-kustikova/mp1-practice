#include <stdio.h>
#include <math.h>


double DENSITY_DSP = 650.0;   // ДСП
double DENSITY_DVP = 800.0;   // ДВП
double DENSITY_WOOD = 500.0;  // Дерево

double THICKNESS_DSP = 0.015;
double THICKNESS_DVP = 0.005;
double THICKNESS_DOOR = 0.01;


double calculate_mass(double height, double width, double thickness, double density) {
    return height * width * thickness * density;
}

int main() {
    double h, w, d;

    printf(" h (180-220 Cm): ");
    scanf_s("%lf", &h);
    printf(" w (80-120 cm): ");
    scanf_s("%lf", &w);
    printf(" d (50-90 cm): ");
    scanf_s("%lf", &d);

    
    h /= 100.0;
    w /= 100.0;
    d /= 100.0;

   
    if (h < 1.8 || h > 2.2 || w < 0.8 || w > 1.2 || d < 0.5 || d > 0.9) {
        printf("Incorrect \n");
        return 1;
    }

    double tm = 0.0;

    
    tm += calculate_mass(h, w, THICKNESS_DVP, DENSITY_DVP);

    
    tm += 2 * calculate_mass(h, d, THICKNESS_DSP, DENSITY_DSP);

    
    tm += 2 * calculate_mass(w, d, THICKNESS_DSP, DENSITY_DSP);

   
    tm += 2 * calculate_mass(h, w / 2, THICKNESS_DOOR, DENSITY_WOOD);

   
    int shelf_count = (int)(h / 0.4) - 1; 
    if (shelf_count < 0) shelf_count = 0;

    
    double shelf_width = w - 2 * THICKNESS_DSP;
    double shelf_depth = d - THICKNESS_DVP;

    tm += shelf_count * calculate_mass(shelf_width, shelf_depth, THICKNESS_DSP, DENSITY_DSP);

   
    
    printf("Massa: %.2f kg\n", tm);

    return 0;
}