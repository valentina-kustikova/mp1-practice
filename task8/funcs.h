#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>

typedef enum {
  EQUILATERAL,
  ISOSCELES,
  SCALENE
} SideType;

typedef enum {
  ACUTE,
  RIGHT,
  OBTUSE
} AngleType;

struct Point{
  double x;
  double y;

  Point();
  Point(double, double);
};

double dist(const Point&, const Point&);

struct Triangle{
  Point A;
  Point B;
  Point C;

  Triangle();
  Triangle(const Point&, const Point&, const Point&);
  
  double perimetr() const;
  double area() const;
  void hights(double&, double&, double&) const;
  SideType side_type() const;
  AngleType angle_type() const;
  void print_side_type() const;
  void print_angle_type() const;
  friend std::ostream& operator <<(std::ostream& out, const Triangle& t)
  {
    double ha, hb, hc;
    out << t.A.x << " " << t.A.y << ";"
      << t.B.x << " " << t.B.y << ";"
      << t.C.x << " " << t.C.y << "\n";

    out << "периметр= " << t.perimetr() << "\n";
    out << "площадь= " << t.area() << "\n";

    t.hights(ha, hb, hc);
    out << "высота ha= " << ha << ","
      << "высота hb= " << hb << ","
      << "высота hc= " << hc << "\n";

    out << "тип по стороне: ";
    t.print_side_type();

    out << "тип по углу: ";
    t.print_angle_type();
    out << "\n";
    return out;
  };
};

struct TriangleLib {
  Triangle* triangles;
  int count;

  TriangleLib();
  ~TriangleLib();
  void file_open(const char*);
  friend std::ostream& operator <<(std::ostream& out, const TriangleLib& tt) {
    for (int i = 0; i < tt.count; i++) {
      out << tt.triangles[i] << "\n";
    }
    return out;
  };
};

#endif