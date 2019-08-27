#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <iostream>
using namespace std;
class matrix {
private:
    int *mat;
    int columns;
    int rows;
public:
    matrix();
    matrix(int c, int r);
    matrix(matrix& mat);
    ~matrix();
    const matrix& operator=(const matrix& m);
    matrix operator+(const matrix& m);
    matrix operator-(const matrix& m);
    matrix operator*(const matrix& m);
    matrix operator+(int con);
    matrix operator-(int con);    
    matrix operator*(int con);
    matrix& operator+=(const matrix& m);
    matrix& operator-=(const matrix& m);
    matrix& operator+=(int con);
    matrix& operator-=(int con);
    matrix& operator*=(int con);
    float* operator[](int index);
    const float* operator[](int index) const;
    friend ostream& operator<<(ostream& out, const matrix& m) {
        out << "(";
        int t = 0;
        for (int i = 0; i < m.columns * m.rows; i++) {
            out << m.mat[i];
            t++;
            if (t == m.columns) {
                out << ")" << endl;
                out << "(";
                t = 0;
            }
            else
                out << " ";
        }
        return out;
    };
    friend istream& operator>>(istream& put, matrix& m) {
        cout << "Введите кол-во столбцов и строк матрицы " << endl;
        put >> m.columns;
        cin >> m.rows;
        if ((m.columns <= 0) || (m.rows <= 0))
            throw exception("Невозможный размер матрирцы!");
        cout << "Введите элементы матрицы(построчно)" << endl;
        m.mat = new int[m.columns * m.rows];
        for (int i = 0; i < m.columns * m.rows; i++)
            put >> m.mat[i];
        return put;
    };
};
class matrixrazmer : std::exception {
    const std::string what_str = "Неподходящий размер матрицы!";
public:
    const char* what() const;
};
class matrixindex : std::exception {
    const std::string what_str = "Некорректно введенный индекс!";
public:
    const char* what() const;
};
#endif