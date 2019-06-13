#pragma once
#include <math.h>
#include <iostream>
using namespace std;

enum exeption_type {BadLength, BadIndex};

struct exeption
{
    exeption_type exp_type;

    exeption(exeption_type type)
    {
        exp_type = type;
    }
};

struct vector
{
    double* array;
    int size;

	vector();
	vector(int _size);
	vector(double* _array, int _size);
	vector(vector& temp);
	~vector();

    //Присваивание
    const vector& operator=(const vector& temp);

    void* operator new(size_t _size);
	void* operator new[](size_t _size);

    void operator delete(void* temp);
	void operator delete[](void* temp);

    //Индексация
    double& operator[](int index);
	double operator[](int index) const;

    //Складывание векторов и присваивание
    const vector& operator+=( const vector& temp);

    //Складывание вектора с числом и присваивание
    const vector& operator+=( const double temp);

    //Разность векторов и присваивание
    const vector& operator-=(const vector& temp);

    //Разность вектора с числом и присваивание
    const vector& operator-=(const double temp);

    //Умножение вектора на число и присваивание
    const vector& operator*=(const double m);

    //Получение длинны вектора
    double length() const;

    //Ввод - Вывод вектора
	void input();

	friend std::istream& operator>> (std::istream& in, vector& temp);

	friend std::ostream& operator<< (std::ostream& out, const vector& temp);

	//Складывание векторов
	vector& operator+(const vector& temp) const;

	//Складывание вектора с числом
	vector& operator+(const double temp) const;

	//Разность векторов
	vector& operator-(const vector& temp) const;

	//Разность вектора с числом
	vector& operator-(const double temp) const;

	//Скалярное произведение
	double& operator*(const vector& temp) const;

	//Умножение вектора на число
	vector& operator*(const double temp) const;

	//Сравнение векторов
	bool operator>(const vector& temp) const;
	bool operator<(const vector& temp) const;
	bool operator==(const vector& temp) const;
	bool operator!=(const vector& temp) const;
};
