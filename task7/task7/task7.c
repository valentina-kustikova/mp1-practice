#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h> 
#include <math.h> 
#include <stdlib.h> 

#define MAX_LINE_LEN 100

typedef struct{

	double x;
	double y;

}Point;

typedef struct {
	Point A;
	Point B;
	Point C;

}Triangle;

typedef struct {
    Triangle* triangles;
    int count;
} TriangleLib;

//х1 y1; x2 y2; x3 y3

TriangleLib* file_open(const char* filename) { // TriangleLib*

    char line[MAX_LINE_LEN];
    int triangle_count;
    int i = 0;
   

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    fscanf(file, "%d\n", &triangle_count);

    TriangleLib* arr= malloc(sizeof(TriangleLib));

    arr->triangles = NULL;
    arr->count = 0;

    arr->triangles = malloc(sizeof(Triangle) * triangle_count);
    while (i < triangle_count && fgets(line, MAX_LINE_LEN, file) != NULL) {
        sscanf(line,
            "%lf %lf; %lf %lf; %lf %lf",
            &arr->triangles[i].A.x,
            &arr->triangles[i].A.y,
            &arr->triangles[i].B.x,
            &arr->triangles[i].B.y,
            &arr->triangles[i].C.x,
            &arr->triangles[i].C.y);
        i++;
    }

    fclose(file);
    arr->count = i;
    return arr;
}

void show_dots(Triangle* triangles, Triangle* count) {
    for (int i = 0; i < count; i++)
    {
        printf("%lf %lf; %lf %lf; %lf %lf",
            triangles[i].A.x,
            triangles[i].A.y,
            triangles[i].B.x,
            triangles[i].B.y,
            triangles[i].C.x,
            triangles[i].C.y);
        printf("\n");
    }
}

double dist(Point *p1, Point *p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

double perimetr(Triangle *t) { 

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    return a + b + c;
}

double area(Triangle *t) { //формула Герона

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

//h=2S/a 
void hights(Triangle *t, double* ha, double* hb, double* hc) {

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    double S = area(t);
    *ha = 2 * S / a;
    *hb = 2 * S / b;
    *hc = 2 * S / c;
}

void triangle_type(Triangle *t) {

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);
    

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)  //a=b=c
        printf("равносторонний треугольник, ");

    else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)  //a=b или a=c или b=c
        printf("равнобедренный треугольник, ");
    
    else 
        printf("разносторонний треугольник, ");

    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;

    double max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    if (fabs(max - a) < 1e-6) { //a=max
        if (a2 < b2 + c2)
            printf("остроугольный");
        else if (a2 > b2 + c2)
            printf("тупоугольный");
        else
            printf("прямоугольный");
    }

    else if (fabs(max - b) < 1e-6) {
        if (b2 < a2 + c2)
            printf("остроугольный");
        else if (b2 > a2 + c2)
            printf("тупоугольный");
        else
            printf("прямоугольный");
    }
    else {
        if (c2 < b2 + a2)
            printf("остроугольный");
        else if (c2 > b2 + a2)
            printf("тупоугольный");
        else
            printf("прямоугольный");
    }
    printf("\n");
}
void print_file(Triangle *t) {
    double ha, hb, hc;
    printf("периметр= %lf\n", perimetr(t));
    printf("площадь= %lf\n", area(t));

    hights(t, &ha, &hb, &hc);
    printf("высота: ha=%lf hb=%lf hc=%lf\n", ha, hb, hc);

    printf("тип: ");
    triangle_type(t);
    printf("\n");
}

int main() {

	char* filename = "triangle.txt";

    setlocale(LC_ALL, "Russian");
    TriangleLib* lib = file_open(filename);

    show_dots(lib->triangles, lib->count);

    for (int i = 0; i < lib->count; i++) {
      
        print_file(&lib->triangles[i]);
    }
   
    free(lib->triangles);
    free(lib);
    return 0;
}