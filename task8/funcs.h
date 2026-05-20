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

  Triangle() {
  }

  Triangle(Point A, Point B, Point C) {
    this->A = A;
    this->B = B;
    this->C = C;
  }
  double dist(Point* p1, Point* p2) {
    return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
  }
  double perimetr() {

    double a = dist(&A, &B);
    double b = dist(&B, &C);
    double c = dist(&A, &C);

    return a + b + c;
  }

  double area() { 

    double a = dist(&A, &B);
    double b = dist(&B, &C);
    double c = dist(&A, &C);

    double p = (a + b + c) / 2.0;

    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  void hights(double* ha, double* hb, double* hc) {

    double a = dist(&A, &B);
    double b = dist(&B, &C);
    double c = dist(&A, &C);

    double S = area();
    *ha = 2 * S / a;
    *hb = 2 * S / b;
    *hc = 2 * S / c;
  }
  SideType side_type() {

    double a = dist(&A, &B);
    double b = dist(&B, &C);
    double c = dist(&A, &C);

    if (fabs(a - b) < 1e-6 && fabs(b - c) < 1e-6)  
      return EQUILATERAL;

    else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)  
      return ISOSCELES;

    else
      return  SCALENE;
  }

  AngleType angle_type() {

    double a = dist(&A, &B);
    double b = dist(&B, &C);
    double c = dist(&A, &C);

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
  void print_side_type() {
    SideType s = side_type();
    switch (s) {

    case EQUILATERAL:
      cout<<"равносторонний, ";
      break;
    case ISOSCELES:
      cout<<"равнобедренный, ";
      break;
    case SCALENE:
      cout<<"разносторонний, ";
      break;
    }
    cout << endl;
  }

  void print_angle_type() {
    AngleType a = angle_type();
    switch (a) {

    case ACUTE:
      cout<<"остроугольный ";
      break;
    case RIGHT:
      cout<<"прямоугольный ";
      break;
    case OBTUSE:
      cout<<"тупоугольный ";
      break;
    }
    cout << endl;
  }


  void print() {

    double ha, hb, hc;

    /*cout << A.x << " " << A.y << ";"
      << B.x << " " << B.y << ";"
      << C.x << " " << C.y << ";" << endl;*/
    cout << "периметр= " << perimetr() << endl;
    cout << "площадь= " << area() << endl;

    hights(&ha, &hb, &hc);
    cout << "высота ha= " << ha
      << "высота hb= " << hb
      << "высота hc= " << hc << endl;

    cout << "тип по стороне: ";
    print_side_type();
    cout << endl;

    cout << "тип по углу: ";
    print_angle_type();
    cout << endl;
  }
};

struct TriangleLib {
  Triangle* triangles;
  int count;

  TriangleLib() {
    triangles = nullptr;
    count = 0;
  }

  ~TriangleLib() {
    delete[] triangles;
  }
  void file_open(const char* filename) {

    int triangle_count;
    int i = 0;

    ifstream file(filename); 

    if (!file.is_open()) {
      cout<<"File not found\n";
      return;
    }

    file >> triangle_count; 

    triangles =new Triangle[triangle_count];

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

  void show_dots() {
    for (int i = 0; i < count; i++) {
      triangles[i].print();
    }
  }
};

#endif