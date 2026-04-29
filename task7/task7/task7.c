#define _CRT_SECURE_NO_WARNINGS
#define MAX_LINE_LEN 100
#include <stdio.h>
#include <locale.h> 
#include <math.h> 
#include <stdlib.h> 

typedef struct{

	double x;
	double y;

}Point;

typedef struct {
	Point A;
	Point B;
	Point C;

}Triangle;

//х1 y1; x2 y2; x3 y3

Triangle* file_open(const char* filename, int* n) {

    Triangle* triangles;
    char line[MAX_LINE_LEN];
    int i = 0;
    int triangle_count;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    fscanf(file, "%d\n", &triangle_count);

    triangles = (Triangle*)malloc(sizeof(Triangle) * triangle_count);

    while (i < triangle_count && fgets(line, MAX_LINE_LEN, file) != NULL) {
        sscanf(line,
            "%lf %lf; %lf %lf; %lf %lf",
            &triangles[i].A.x,
            &triangles[i].A.y,
            &triangles[i].B.x,
            &triangles[i].B.y,
            &triangles[i].C.x,
            &triangles[i].C.y);
        i++;
    }

    fclose(file);

    *n = i;
    return triangles;
}

void show_dots(Triangle* triangles, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%lf %lf; %lf %lf; %lf %lf",
            &triangles[i].A.x,
            &triangles[i].A.y,
            &triangles[i].B.x,
            &triangles[i].B.y,
            &triangles[i].C.x,
            &triangles[i].C.y);
    }
    printf("\n");
}

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double perimetr(Triangle t) { 

    double a = dist(t.A, t.B);
    double b = dist(t.B, t.C);
    double c = dist(t.A, t.C);

    return a + b + c;
}

double area(Triangle t) { //формула Герона

    double a = dist(t.A, t.B);
    double b = dist(t.B, t.C);
    double c = dist(t.A, t.C);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

//h=2S/a a-сторона к которой проведена высота 
void hights(Triangle t, double* ha, double* hb, double* hc) {

    double a = dist(t.A, t.B);
    double b = dist(t.B, t.C);
    double c = dist(t.A, t.C);

    double S = area(t);
    *ha = 2 * S / a;
    *hb = 2 * S / b;
    *hc = 2 * S / c;
}

void triangle_type(Triangle t) {

    double a = dist(t.A, t.B);
    double b = dist(t.B, t.C);
    double c = dist(t.A, t.C);

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)  //a=b=c
        printf("равносторонний треугольник, ");

    else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)  //a=b или a=c или b=c
        printf("равнобедренный треугольник, ");
    
    else 
        printf("разносторонний треугоник, ");

    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;

    if (c2 < a2 + b2)
        printf("остроугольный");

    else if (c2 > a2 + b2)
        printf("тупоугольный");

    else
        printf("прямоугольный");
}

void print(Triangle triangles) {
    double ha, hb, hc;

    printf("периметр= %lf\n", perimetr(triangles));
    printf("площадь= %lf\n", area(triangles));


}

int main() {

    int n;
	char* filename = "triangle.txt";

    setlocale(LC_ALL, "Russian");
    Triangle* triangles = file_open(filename, &n);

    show_dots(triangles, n);
    free(triangles);
    return 0;
}