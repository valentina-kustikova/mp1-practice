#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <math.h>

class Vector
{
    int size;
    double* elements;
public:
    Vector(const Vector&);
    Vector(int);
    ~Vector();

    void Input();

    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    bool operator==(const Vector&) const;
    const Vector& operator=(const Vector&);
    Vector operator+(double);
    Vector operator-(double);
    double& operator[](int a);
    const double& operator[](int a) const;
    Vector operator*(double);
    double operator*(const Vector&) const;
    Vector& operator+=(const Vector&);
    Vector& operator-=(const Vector&);
    Vector& operator+=(const double);
    Vector& operator-=(const double);
    double Lenght(const Vector&) const;

    friend std::ostream& operator<<(std::ostream &, const Vector &);
    friend std::istream& operator>>(std::istream &, const Vector &);
};
    class Vector1 : std::exception
    {
        const std::string what_str = "Different size";
    public:
        const char* what() const;
    };

    class Vector2 : std::exception
    {
        const std::string what_str = "Out of bounds";
    public:
        const char* what() const;
    };

#endif