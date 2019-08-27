#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <iostream>
#include <string>
#include <cstring>
class vector {
private:
    int n;//кол-во векторов
    double *x;//компоненты вектора
public:
    vector(int n);
    vector(vector& cop);
    ~vector();
    const vector& operator=(const vector& t);
    vector operator+(const vector& t);
    vector operator-(const vector& t);
    vector operator*(const vector& t);
    vector operator+(double con);
    vector operator-(double con);
    vector operator*(double con);
    vector& operator+=(const vector& t);
    vector& operator-=(const vector& t);
    vector& operator*=(const vector& t);
    vector& operator+=(double con);
    vector& operator-=(double con);
    vector& operator*=(double con);
    const double lenght();
    double& operator[](int i);
    const double& operator[](int i) const;
    friend ostream& operator<<(ostream& out, const vector& v) {
        out << "(" << v.x[0];
        for (int i = 1; i < v.n; i++)
            out << ", " << v.x[i];
        out << ")" << endl;
        return out;
    };
    friend istream& operator>>(istream& put, vector& v) {
        v.x = new double[v.n];
        cout << "¬ведите координаты вектора" << endl;
        for (int i = 0; i < v.n; i++)
            put >> v.x[i];
        return put;
    };
};

class vectorissue1 : std::exception{
    const std::string what_str = "НЕдопустимый индекс";
public:
    const char* what() const;
};
class vectorissue2 : std::exception{
    const std::string what_str = "Разные размерности!НЕдопустимо!";
public:
    const char* what() const;
};
#endif