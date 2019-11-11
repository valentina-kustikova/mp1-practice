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

    vector() {
        size = 0;
        array = nullptr;
    }
    vector(int _size) {
        size = _size;
        array = new double [size];
        for (int i = 0; i < size; i++)
        {
            array[i] = 0;
        }
    }
    vector(double* _array, int _size)
    {
        size = _size;
        array = new double[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = _array[i];
        }
    }
    /*Привет я конструктор копирования, забавный факт обо мне:
    может покзаться что я бесполезен, но это не так, я нужен
    для передачи локальных переменных функции в другую функцию,
    но об этом разумеется никто не рассказывал, зато вы теперь об
    этом знаете :D Удачи!*/
    vector(vector& temp) {
        size = temp.size;
        array = new double[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = temp.array[i];
        }
    }
    ~vector() {
        size = 0;
        if (array != nullptr)
        {
            delete[] array;
        }
    }

    //Присваивание
    vector& operator=(const vector& temp);

    /* А что им тут вообще делать? 
    void* operator new(size_t _size);

    void operator delete(void* temp);
    */

    //Индексация
    double& operator[](int index);

    //Складывание векторов и присваивание
    vector operator+=( const vector& temp);

    //Складывание вектора с числом и присваивание
    vector operator+=( const double temp);

    //Разность векторов и присваивание
    vector operator-=(const vector& temp);

    //Разность вектора с числом и присваивание
    vector operator-=(const double temp);

    //Умножение вектора на число и присваивание
    vector operator*=(const double m);

    //Получение длинны вектора
    double length();

    //Печать вектора
    void print();

    //Ввод вектора
    void input();
};

//Складывание векторов
vector operator+(const vector& a, const vector& b);

//Складывание вектора с числом
vector operator+(const vector& a, const double b);

//Разность векторов
vector operator-(const vector& a, const vector& b);

//Разность вектора с числом
vector operator-(const vector& a, const double b);

//Скалярное произведение
double operator*(const vector& a, const vector& b);

//Умножение вектора на число
vector operator*(const vector& a, const double m);