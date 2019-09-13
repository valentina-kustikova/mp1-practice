#pragma once
#include "mat.h"
#include <math.h>

mat::mat(int _dx, int _dy)
{
    dx = _dx;
	dy = _dy;
	int tmpsize = dx * dy;
    mp = new double[_dx*_dy];
	for (int i = 0; i < tmpsize; i++)
		mp[i] = 0;
}

mat::mat(const mat& m)
{
	int tmpsize = m.dx * m.dy;
    dx = m.dx;
	dy = m.dy;
    mp = new double[tmpsize];
    for (int i = 0; i < tmpsize; i++)
		mp[i]=m.mp[i];
}

mat::~mat()
{
    delete[] mp;
    dx = 0;
	dy = 0;
}

mat mat::operator+ (const mat& m) const
{
    if ((dx != m.dx) || (dy != m.dy))
        throw "error: different dimensions";
    mat tmp (m);
    for (int i = 0; i < dx*dy; i++)
        tmp.mp[i] += mp[i];
    return tmp;
}

mat mat::operator- (const mat& m) const
{
    if ((dx != m.dx) || (dy != m.dy))
        throw "error: different dimensions";
    mat tmp (*this);
    for (int i = 0; i < dx*dy; i++)
        tmp.mp[i] -= m.mp[i];
    return tmp;
}

mat mat::operator* (const mat & m) const
{
    if ((dx != m.dx) || (dy != m.dy))
        throw "error: different dimensions";
	mat tmp (dx, m.dy);
    for (int i = 0; i < dx; i++)
        for (int j = 0; j < m.dy; j++)
        {
            tmp.mp[i * m.dy + j] = 0.0;
            for (int k = 0; k < dy; k++)
                tmp.mp[i * m.dy + j] += mp[i * dy + k] * m.mp[k * m.dy + i];
        }
    return tmp;
}

mat mat::operator+ (double c) const
{
    mat tmp (*this);
    for (int i = 0; i < dx*dy; i++)
        tmp.mp[i] += c;
    return tmp;
}

mat mat::operator- (double c) const
{
    mat tmp (*this);
    for (int i = 0; i < dx*dy; i++)
        tmp.mp[i] -= c;
    return tmp;
}

mat mat::operator* (double c) const
{
    mat tmp (*this);
    for (int i = 0; i < dx*dy; i++)
        tmp.mp[i] *= c;
    return tmp;
}

double* mat::operator[] (int i)
{
	if ((i < 0) || (i >= dx))
		throw "[] error: outofrange";
	return mp + dy * i;
}

const double* mat::operator[] (int i) const
{
    if ((i < 0) || (i >= dx))
        throw "[] error: outofrange";
    return mp + dy * i;
}

const mat& mat::operator= (const mat & m)
{
    if (*this == m)
    {
        return *this;
    }
    
    delete[] mp;
    dx = m.dx;
	dy = m.dy;
	int tmpsize = dx*dy;
    mp = new double[tmpsize];
    for (int i = 0; i < tmpsize; i++)
        mp[i]=m.mp[i];
    return *this;
}

mat& mat::operator+= (const mat & m)
{
    if ((dx != m.dx) || (dy != m.dy))
        throw "+= error: different dimensions";
    (*this)=(*this)+m;
    return (*this);
}

mat& mat::operator-= (const mat & m)
{
    if ((dx != m.dx) || (dy != m.dy))
        throw "+= error: different dimensions";
    (*this)=(*this)-m;
    return (*this);
}

mat& mat::operator+= (double c)
{
    (*this)=(*this)+c;
    return (*this);
}

mat& mat::operator-= (double c)
{
    (*this)=(*this)-c;
    return (*this);
}

mat& mat::operator*= (double c)
{
    (*this)=(*this)*c;
    return (*this);
}

bool mat::operator== (const mat& m) const
{
    if ((dx != m.dx) || (dy != m.dy))
		return false;
    for (int i = 0; i < dx*dy; i++)
    {
        if (mp[i] != m.mp[i]) 
			return false;
    }
    return true;
}

istream& operator>>(istream& in, mat& m)
{
    for (int i = 0; i < (m.dx * m.dy); i++)
        in >> m.mp[i];
    return in;
}

ostream& operator<<(ostream &out, const mat& m)
{
    for (int i = 0; i < (m.dx * m.dy); i++)
    {
        out << m.mp[i] << " ";
        if ((i % m.dy) == (m.dy - 1))
            out << endl;
    }
    return out;
}