#include <stdio.h> 
#include <math.h> 
#include <locale.h> 
int main()
{ 
    float x, X, y, Y, r, R, d; //d-расстояние между центрами окружности 
    setlocale(LC_ALL, "Russian"); 

    printf("Введите координаты первой окружности и ее радиус\n"); 
    scanf("%f %f %f", &x, &y, &r); 
    printf("Введите координаты второй окружности и ее радиус\n"); 
    scanf("%f %f %f", &X, &Y, &R); 
    d = sqrt((x - X)*(x - X) + (y - Y)*(y - Y)); 
    if (d > (r + R)) 
    { 
        printf("Окружности не пересекаются, ни одна окружность не находится в другой"); 
        return; 
    } 
    if (d == (r + R)) 
    { 
        printf("Окружности касаются внешним образом в одной точке"); 
        return; 
    } 
  
    if (d == abs(r - R)) 
    { 
         printf("Внутреннее касание"); 
         return; 
    } 
    if ((d > 0) && (d < abs(r - R)))
    { 
        printf("Одна окружность находится в другой"); 
        return; 
    }
    printf("Окружности пересекаются в двух точках");
}

