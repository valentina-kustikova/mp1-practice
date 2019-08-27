#include<iostream>
#include"matrix.h"
#include<locale.h>
using namespace std;
//--------------конструкторы, деструкторы------------------
matrix::matrix() {
    columns = 2;
    rows = 3;
    mat = new int[columns*rows];
    for (int i = 0; i < columns*rows; i++)
        mat[i] = 0;
};
matrix::matrix(int c, int r) {
    if ((c <= 0) || (r <= 0))
        throw matrixrazmer();
    columns = c;
    rows = r;
    mat = new int[columns*rows];
    for (int i = 0; i < columns*rows; i++)
        mat[i] = 0;
};
matrix::matrix(matrix& m) {
    columns = m.columns;
    rows = m.rows;
    mat = new int[columns*rows];
    for (int i = 0; i < columns*rows; i++)
        mat[i]=m.mat[i];
};
matrix::~matrix() {
    columns = 0;
    rows = 0;
    delete[] mat;
};
//-------------перегрузки операций-------------------
const matrix& matrix::operator=(const matrix& m) {
    if (this == &m)
        return *this;
    columns = m.columns;
    rows = m.rows;
    delete[] mat;
    mat = new int[columns*rows];
    for (int i = 0; i < columns*rows; i++)
        mat[i] = m.mat[i];
    return *this;
}
//--------------обычные операции с матрицами-------------------
matrix matrix::operator+(const matrix& m) {
    if ((rows != m.rows) || (columns != m.columns))
        throw matrixrazmer();
    matrix result(m.columns, m.rows);
    for (int i = 0; i < columns*rows; i++)
        result.mat[i] = m.mat[i]+mat[i];
    return result;
};
matrix matrix::operator-(const matrix& m) {
    if ((rows != m.rows) || (columns != m.columns))
        throw matrixrazmer();
    matrix result(m.columns, m.rows);
    for (int i = 0; i < columns*rows; i++)
        result.mat[i] =  mat[i]-m.mat[i];
    return result;
};
matrix matrix::operator*(const matrix& m) {
    if (columns != m.rows)
        throw matrixrazmer();
    matrix result(m.columns, rows);
    int c=0, r=0;
    for (int i = 0; i < rows; i++) 
        for(int j = 0; j < m.columns; j++)
            for (int f = 0; f < columns; f++) 
                result.mat[i * m.columns + j] += mat[i * columns + f] * m.mat[f * m.columns + j];
    return result;
};
//----------обычные операции с константами------------

matrix matrix::operator+(int con) {
    for (int i = 0; i < columns*rows; i++)
        mat[i] = con  + mat[i];
    return *this;
};
matrix matrix::operator-(int con) {
    for (int i = 0; i < columns*rows; i++)
        mat[i] =  mat[i]-con;
    return *this;
};
matrix matrix::operator*(int con) {
    for (int i = 0; i < columns*rows; i++)
        mat[i] = mat[i] * con;
    return *this;
};
//----------операции типа += с матрицами------------
matrix& matrix::operator+=(const matrix& m) {
    if ((rows != m.rows) || (columns != m.columns))
        throw matrixrazmer();
    for (int i = 0; i < columns*rows; i++)
        mat[i] += m.mat[i];
    return *this;
}
matrix& matrix::operator-=(const matrix& m) {
    if ((rows != m.rows) || (columns != m.columns))
        throw matrixrazmer();
    for (int i = 0; i < columns*rows; i++)
        mat[i] -= m.mat[i];
    return *this;
}
//----------операции типа += с константами------------
matrix& matrix::operator+=(int con) {
    for (int i = 0; i < columns*rows; i++)
        mat[i] += con;
    return *this;
}
matrix& matrix::operator-=(int con) {
    for (int i = 0; i < columns*rows; i++)
        mat[i] -= con;
    return *this;
}
matrix& matrix::operator*=(int con) {
    for (int i = 0; i < columns*rows; i++)
        mat[i] *= con;
    return *this;
}
//--------------остальные функции и перегрузки----------------
float* matrix::operator[](int index) {
    if ((index < 0) || (index >= rows))
        throw matrixindex();
    return(mat + columns * index);
}
const float* matrix::operator[](int index) const{
    if ((index < 0) || (index >= rows))
        throw matrixindex();
    return(mat + columns * index);
}

//-----------------------исключения-----------------------
const char* matrixrazmer::what() const {
    return what_str.c_str();
}
const char* matrixindex::what() const {
    return what_str.c_str();
}