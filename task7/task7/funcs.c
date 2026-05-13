#include <stdio.h>
#include <locale.h> 
#include <math.h> 
#include <stdlib.h> 

#define MAX_LINE_LEN 100
#include "funcs.h"

TriangleLib* file_open(const char* filename) {

    char line[MAX_LINE_LEN];
    int triangle_count;
    int i = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        return NULL;
    }

    fscanf(file, "%d\n", &triangle_count);

    TriangleLib* arr = malloc(sizeof(TriangleLib));

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

void show_dots(Triangle* t, Triangle* count) {
    for (int i = 0; i < count; i++)
    {
        printf("%lf %lf; %lf %lf; %lf %lf",
            t[i].A.x,
            t[i].A.y,
            t[i].B.x,
            t[i].B.y,
            t[i].C.x,
            t[i].C.y);
        printf("\n");
    }
}

double dist(Point* p1, Point* p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

double perimetr(Triangle* t) {

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    return a + b + c;
}

double area(Triangle* t) { //формула Герона

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

//h=2S/a 
void hights(Triangle* t, double* ha, double* hb, double* hc) {

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    double S = area(t);
    *ha = 2 * S / a;
    *hb = 2 * S / b;
    *hc = 2 * S / c;
}

SideType side_type(Triangle* t) {

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)  //a=b=c
        return EQUILATERAL;

    else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)  //a=b или a=c или b=c
        return ISOSCELES;

    else
        return  SCALENE;
}

AngleType angle_type(Triangle* t) {

    double a = dist(&t->A, &t->B);
    double b = dist(&t->B, &t->C);
    double c = dist(&t->A, &t->C);

    double a2 = a * a;
    double b2 = b * b;
    double c2 = c * c;

    double max = a2;
    double sum;

    if (b2 > max)
        max = b2;
    if (c2 > max)
        max = c2;

    if (fabs(max - a2) < 1e-6)
        sum = b2 + c2;
    else if (fabs(max - b2) < 1e-6)
        sum = a2 + c2;
    else
        sum = a2 + b2;

    if (fabs(max - sum) < 1e-6)
        return RIGHT;

    if (max < sum)
        return ACUTE;

    return OBTUSE;
}

void print_side_type(SideType type) {
    switch (type) {

    case EQUILATERAL:
        printf("равносторонний ");
        break;
    case ISOSCELES:
        printf("равнобедренный ");
        break;
    case SCALENE:
        printf("разносторонний ");
        break;
    }
}

void print_angle_type(AngleType type) {
    switch (type) {

    case ACUTE:
        printf("остроугольный ");
        break;
    case RIGHT:
        printf("прямоугольный ");
        break;
    case OBTUSE:
        printf("тупоугольный ");
        break;
    }
}

void print_file(Triangle* t) {
    double ha, hb, hc;
    printf("периметр= %lf\n", perimetr(t));
    printf("площадь= %lf\n", area(t));

    hights(t, &ha, &hb, &hc);
    printf("высота: ha=%lf hb=%lf hc=%lf\n", ha, hb, hc);

    printf("тип: ");
    print_side_type(side_type(t));
    printf(",");
    print_angle_type(angle_type(t));

    printf("\n");
}