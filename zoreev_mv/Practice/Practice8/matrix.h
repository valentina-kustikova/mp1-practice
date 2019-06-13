#pragma once
#include <iostream>
using namespace std;

enum exeption_type { BadSize, BadIndex };

struct exeption
{
    exeption_type exp_type;

    exeption(exeption_type type)
    {
        exp_type = type;
    }
};

class matrix
{
    unsigned int m; //Строки
    unsigned int n; //Столбцы
    double* array;
public:
    matrix();
    matrix(unsigned int _m, unsigned int _n);
    matrix(unsigned int _m, unsigned int _n, double* _array);
    matrix(const matrix& temp);
    ~matrix();

    void print();
    void input();

    const matrix& operator=(const matrix& temp);
    matrix operator+(const matrix& temp);
    matrix operator+(double temp);
    matrix operator-(const matrix& temp);
    matrix operator-(double temp);
    matrix operator*(const matrix& temp);
    matrix operator*(double temp);
    double* operator[](unsigned index);
};