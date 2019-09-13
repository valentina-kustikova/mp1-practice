#pragma once
#include "vector.h"
#include <iostream>
#include <math.h>
using namespace std;

vect::vect()
{
    dim = 0;
    coord = nullptr;
}

vect::vect(int dim0)
{
    dim = dim0;
    coord = new double[dim0];
}

vect::vect(const vect& v)
{
    dim = v.dim;
    coord = new double[v.dim];
    for (int i = 0; i < dim; i++)
        coord [i] = v.coord[i];
}

vect::~vect()
{
    delete[] coord;
    dim = 0;
}

vect vect::operator+ (const vect & v) const
{
    if (dim != v.dim)
        throw "sum error: different dimensions";
    vect sum(v);
    for (int i = 0; i < dim; i++)
        sum.coord[i] += coord[i];
    return sum;
}

vect vect::operator- (const vect & v) const
{
    if (dim != v.dim)
        throw "difference error: different dimensions";
    vect sum(*this);
    for (int i = 0; i < dim; i++)
        sum.coord[i] = sum.coord[i] - v.coord[i];
    return sum;
}

double vect::operator* (const vect & v) const
{
    if (dim != v.dim)
        throw "scalar product error: different dimensions";
    double vect_scp = 0.0;
    for (int i = 0; i < dim; i++)
        vect_scp += coord[i] * v.coord[i];
    return  vect_scp;
}

vect vect::operator+ (double c) const
{
    vect sum_c(*this);
    for (int i = 0; i < dim; i++)
        sum_c.coord[i] += c;
    return sum_c;
}

vect vect::operator- (double c) const
{
    vect sum_c(*this);
    for (int i = 0; i < dim; i++)
        sum_c.coord[i] = sum_c.coord[i] - c;
    return sum_c;
}
vect vect::operator* (double c) const
{
    vect k_vect(*this);
    for (int i = 0; i < dim; i++)
        k_vect.coord[i] = k_vect.coord[i] * c;
    return k_vect;
}

const vect& vect::operator= (const vect & v)
{
    if (*this == v)
    {
        return *this;
    }
    
    delete[] coord;
    dim = v.dim;
    coord = new double[dim];
    for (int i = 0; i < dim; i++)
        coord[i] = v.coord[i];
    return *this;
}

double& vect::operator[] (int i)
{
    if ((i < 0) || (i >= dim))
        throw "[] error: wrong coordinate";
    return coord[i];
}

const double& vect::operator[] (int i) const
{
	if ((i < 0) || (i >= dim))
		throw "[] error: wrong coordinate";
	return coord[i];
}

double vect::vect_len() const
{
    double vect_len = 0.0;
    vect_len = sqrt((*this)*(*this));
    return vect_len;
}

vect& vect::operator+= (const vect & v)
{
    if (dim != v.dim)
        throw "+= error: different dimensions";
    (*this)=(*this)+v;
    return (*this);
}

vect& vect::operator-= (const vect & v)
{
    if (dim != v.dim)
        throw "-= error: different dimensions";
    (*this)=(*this)-v;
    return (*this);
}

vect& vect::operator+= (double c)
{
    (*this)=(*this)+c;
    return (*this);
}

vect& vect::operator-= (double c)
{
    (*this)=(*this)-c;
    return (*this);
}

vect& vect::operator*= (double c)
{
    (*this)=(*this)*c;
    return (*this);
}

void vect::vect_print() const
{
    for (int i = 0; i < dim; i++)
        cout << coord[i] << " ";
    cout << endl << endl;
}

void vect::vect_read()
{
    if (dim <= 0)
        throw "reading error: wrong dimension";

    for (int i = 0; i < dim; i++)
        cin >> coord[i];
}

int vect::operator==(const vect & v) const
{
    if (dim != v.dim) return 0;
    int check = 0;
    for (int i = 0; i < dim; i++)
    {
        if (coord[i] != v.coord[i]) check = 1;
        if (check == 1) return 0;
    }
    return 1;
}

istream& operator>>(istream &in, vect &v)
{
    for (int i = 0; i < v.dim; i++)
        in >> v.coord [i];
    return in;
}

ostream& operator<<(ostream &out, const vect& v)
{
    for (int i = 0; i < v.dim; i++)
        out << v.coord[i] << " ";
    return out;
}