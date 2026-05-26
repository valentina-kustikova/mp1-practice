#ifndef FUNCS_H
#define FUNCS_H

typedef enum {
  EQUILATERAL,
  ISOSCELES,
  SCALENE
}SideType;

typedef enum {
  ACUTE,
  RIGHT,
  OBTUSE
}AngleType;

struct Point{
  double x;
  double y;

  Point();
  Point(double, double);
};

struct Triangle{
  Point A;
  Point B;
  Point C;

  Triangle();
  Triangle(Point, Point, Point);
  double dist(Point* , Point* );
  double perimetr();
  double area();
  void hights(double*, double* , double* );
  SideType side_type();
  AngleType angle_type();
  void print_side_type();
  void print_angle_type();
  void print();
};

struct TriangleLib {
  Triangle* triangles;
  int count;

  TriangleLib();
  ~TriangleLib();
  void file_open(const char*);
  void show_dots();
};

#endif