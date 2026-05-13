#ifndef FUNCS_H
#define FUNCS_H

typedef struct {
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

typedef enum {
    EQUILATERAL, //равносторонний
    ISOSCELES, //равнобедренный 
    SCALENE //разносторонний
}SideType;

typedef enum {
    ACUTE, //остроугольный 
    RIGHT, //прямоугольный
    OBTUSE //тупоугольный
}AngleType;

TriangleLib* file_open(const char* filename);
void show_dots(Triangle* triangles, Triangle* count);
double dist(Point* p1, Point* p2);
double perimetr(Triangle* t);
double area(Triangle* t);
void hights(Triangle* t, double* ha, double* hb, double* hc);
SideType side_type(Triangle* t);
AngleType angle_type(Triangle* t);
void print_side_type(SideType type);
void print_angle_type(AngleType type);
void print_file(Triangle* t);

#endif