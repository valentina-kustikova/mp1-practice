#include <iostream>
#include <clocale> 
#include <cmath>
#include <fstream> 
#include <string>

using namespace std;
#include "funcs.h"

Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

Point::Point() {
  x = 0;
  y = 0;
}

double dist(const Point& p1, const Point& p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

Triangle::Triangle(): A(0,0), B(0,0), C(0,0) {
}

Triangle::Triangle(const Point& A, const Point& B, const Point& C): A(A), B(B), C(C) {
}

double Triangle:: perimetr() const{

    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(A, C);

    return a + b + c;
}
double Triangle::area() const{

    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(A, C);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::hights(double& ha, double& hb, double& hc) const{

    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(A, C);

    double S = area();
    ha = 2 * S / a;
    hb = 2 * S / b;
    hc = 2 * S / c;
}
SideType Triangle::side_type() const{

    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(A, C);

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)
        return EQUILATERAL;

    else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)
        return ISOSCELES;

    else
        return  SCALENE;
}

AngleType Triangle::angle_type() const {

    double a = dist(A, B);
    double b = dist(B, C);
    double c = dist(A, C);

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

void Triangle::print_side_type() const {
    SideType s = side_type();
    switch (s) {

    case EQUILATERAL:
        cout << "равносторонний, ";
        break;
    case ISOSCELES:
        cout << "равнобедренный, ";
        break;
    case SCALENE:
        cout << "разносторонний, ";
        break;
    }
    cout << endl;
}
void Triangle::print_angle_type() const {
    AngleType a = angle_type();
    switch (a) {

    case ACUTE:
        cout << "остроугольный ";
        break;
    case RIGHT:
        cout << "прямоугольный ";
        break;
    case OBTUSE:
        cout << "тупоугольный ";
        break;
    }
    cout << endl;
}


TriangleLib::TriangleLib() {
    triangles = nullptr;
    count = 0;
}
TriangleLib::~TriangleLib() {
    delete[] triangles;
}
void TriangleLib::file_open(const char* filename) {

    int triangle_count;
    int i = 0;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File not found\n";
        return;
    }

    file >> triangle_count;

    triangles = new Triangle[triangle_count];

    while (i < triangle_count) {
        char ch;

        file >> triangles[i].A.x >> triangles[i].A.y >> ch
            >> triangles[i].B.x >> triangles[i].B.y >> ch
            >> triangles[i].C.x >> triangles[i].C.y;

        i++;
    }
    count = i;
    file.close();
}

