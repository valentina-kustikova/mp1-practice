#include<iostream>
#include"matrix.h"
#include<locale.h>
using namespace std;
void main() {
    int con;
    setlocale(LC_ALL, "Rus");
    matrix a, b, mat3;
    cin >> a;
    cin >> b;
    cout << "1ая матрица: " << endl;
    cout << a << endl;
    cout << "2ая матрица: " << endl;
    cout << b << endl;
    cout << "3ая матрица: " << endl;
    cout << mat3 << endl;
    //----------------------------------
    try {
        //a+b
        cout << "a+b: " << endl;
        mat3 = a + b;
        cout << mat3 << endl;
        //a-b
        cout << "a-b: " << endl;
        mat3 = a - b;
        cout << mat3 << endl;
        //a*b
        cout << "a*b: " << endl;
        mat3 = a * b;
        cout << mat3 << endl;
    }
    catch (matrixrazmer) {
        std::cout << "Неподходящий размер матрицы!\n";
    }
    //-----------------------------------
    try {
        cout << "Введите константу" << endl;
        cin >> con;
        //a+con
        cout << "a+con: " << endl;
        mat3 = a + con;
        cout << mat3 << endl;
        //a-con
        cout << "a-con: " << endl;
        mat3 = a - con;
        cout << mat3 << endl;
        //a*con
        cout << "a*con: " << endl;
        mat3 = a * con;
        cout << mat3 << endl;
    }
    catch (matrixrazmer) {
        std::cout << "Неподходящий размер матрицы!\n";
    }
    //-----------------------------------
    try {
        //a+=b
        cout << "a+=b: " << endl;
        mat3 = a;
        mat3 += b;
        cout << mat3 << endl;
        //a-b
        cout << "a-=b: " << endl;
        mat3 = a;
        mat3 -= b;
        cout << mat3 << endl;
    }
    catch (matrixrazmer) {
        std::cout << "Неподходящий размер матрицы!\n";
    }
    //-----------------------------------
    try {
        //a+=con
        cout << "a+con: " << endl;
        mat3 = a;
        mat3 += con;
        cout << mat3 << endl;
        //a-=con
        cout << "a-con: " << endl;
        mat3 = a;
        mat3 -= con;
        cout << mat3 << endl;
        //a*=con
        cout << "a*con: " << endl;
        mat3 = a;
        mat3 *= con;
        cout << mat3 << endl;
    }
    catch (matrixrazmer) {
        std::cout << "Неподходящий размер матрицы!\n";
    }
    try {
        cout << a[4] << endl;
        cout << a[-34];
    }
    catch (matrixrazmer) {
        std::cout << "Некорректно введенный индекс!\n";
    }
}