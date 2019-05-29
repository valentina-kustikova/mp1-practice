#include "Vector.h"
#include <iostream>
#include <math.h>
using namespace std;

Vector::Vector()
{
    dim = 0;
    x = NULL;
}

Vector::Vector(int _dim)
{
    dim = _dim;
    x = new double[dim];
}

Vector::Vector(const Vector& v)
{
    dim = v.dim;
    x = new double[v.dim];
    for (int i = 0; i < dim; i++)
        x[i] = v.x[i];
}

Vector::~Vector()
{
    dim = 0;
    delete[] x;
}

Vector& Vector::operator= (const Vector& v)
{
    if (this != &v)
    {
        dim = v.dim;
        delete[] x;
        x = new double[dim];
        for (int i = 0; i < dim; i++)
            x[i] = v.x[i];
    }
    return *this;
}

Vector Vector::operator+ (const Vector& v)
{
    Vector tmp(*this);
    for (int i = 0; i < dim; i++)
        tmp.x[i] += v.x[i];
    return tmp;
}

Vector Vector::operator- (const Vector& v) 
{
    Vector tmp(*this);
    for (int i = 0; i < dim; i++)
        tmp.x[i] -= v.x[i];
    return tmp;
}

double Vector::operator* (const Vector& v)
{
    double scal = 0;
    for (int i = 0; i < dim; i++)
        scal += x[i] * v.x[i];
    return scal;
}

Vector Vector::operator+ (double dig)
{
    Vector v(*this);
    for (int i = 0; i < dim; i++)
        v.x[i] = x[i] + dig;
    return v;
}

Vector Vector::operator- (double dig)
{
    Vector v(*this);
    for (int i = 0; i < dim; i++)
        v.x[i] = x[i] - dig;
    return v;
}

Vector Vector::operator* (double dig)
{
    Vector v(*this);
    for (int i = 0; i < dim; i++)
        v.x[i] = x[i] * dig;
    return v;
}

Vector& Vector::operator+= (const Vector & v)
{
    for (int i = 0; i < dim; i++)
        x[i] += v.x[i];
    return *this;
}

Vector& Vector::operator-= (const Vector & v)
{
    for (int i = 0; i < dim; i++)
        x[i] -= v.x[i];
    return *this;
}

Vector& Vector::operator*= (const Vector & v)
{
    for (int i = 0; i < dim; i++)
        x[i] *= v.x[i];
    return *this;
}

Vector& Vector::operator+= (double dig)
{
    for (int i = 0; i < dim; i++)
        x[i] += dig;
    return *this;
}

Vector& Vector::operator-= (double dig)
{
    for (int i = 0; i < dim; i++)
        x[i] -= dig;
    return *this;
}

Vector& Vector::operator*= (double dig)
{
    for (int i = 0; i < dim; i++)
        x[i] *= dig;
    return *this;
}

double& Vector::operator[] (int idx)
{
    if ((idx < 0) || (idx >= dim))
        cout << "Нет такого индекса. Попробуйте ввести индекс ещё раз.";
    return x[idx];
}

const double& Vector::operator[] (int idx)const
{
    do {
        if ((idx < 0) || (idx >= dim))
            cout << "Нет такого индекса. Попробуйте ввести индекс ещё раз.";
    } while ((idx < 0) || (idx >= dim));
    return x[idx];
}

void Vector::Length()
{
    double len = 0;
    for (int i = 0; i < dim; i++)
        len += x[i] * x[i];
    len = sqrt(len);
    cout << fixed;
    cout.precision(3);
    cout << len << endl << endl;
}

void Vector::Fill()
{
    for (int i = 0; i < dim; i++) {
        cin >> x[i];
    }
}

void  Vector::Print()
{
    for (int i = 0; i < dim; i++)
        cout << x[i] << " ";
}

void Menu()
{
    cout << "Для того чтобы выбрать операцию, которую вы хотите провести над векторами" << endl;
    cout << "введите соответвсвующий номер операции из указанных ниже:" << endl;
    cout << "1 - v = v1 + v2" << endl;
    cout << "2 - v = v1 - v2" << endl;
    cout << "3 - scal = (v1, v2)" << endl;
    cout << "4 - v = v1 + dig" << endl;
    cout << "5 - v = v1 - dig" << endl;
    cout << "6 - v = v1 * dig" << endl;
    cout << "7 - v1 += v2" << endl;
    cout << "8 - v1 -= v2" << endl;
    cout << "9 - v1 *= v2" << endl;
    cout << "10 - v1 += dig" << endl;
    cout << "11 - v1 -= dig" << endl;
    cout << "12 - v1 *= dig" << endl;
    cout << "13 - v1[i] = dig" << endl;
}

double Digital()
{
    double d;
    cout << "Введите число" << endl;
    cin >> d;
    return d;
}