#include <iostream>
#include "vector.h"
#include <locale.h>
#include "exception.h"
using namespace std;
void main() {
    
    int n, i;
    double con, len;
    setlocale(LC_ALL, "Rus");
    cout << "Введите размерность векторов" << endl;
    cin >> n;
    vector a(n), b(n), c(n), d(n-1);
    cin >> a;
    cin >> b;
    cout << "Координаты вектора a: ";
    cout << a;
    cout << "Координаты вектора b: ";
    cout << b;
    cout << "Координаты вектора c: ";
    cout << c;
    cout << "Координаты вектора d: ";
    cout << d;
    //----------------------------------
    try {
        //a+b
        cout << "a+b: " << endl;
        c = a + b;
        cout << c;
        //a-b
        cout << "a-b: " << endl;
        c = a - b;
        cout << c;
        //скалярное произведение a*b
        cout << "a*b: " << endl;
        c = a * b;
        cout << c;
        //a+d(исключение, разные размерности)
        cout << "a+d: " << endl;
        c = a + d;
        cout << c;
    }
		catch (vectorissue2) {
			std::cout << "Разные размерности!НЕдопустимо!\n";
    }
    //-----------------------------------
    try {//без исключений
        cout << "Введите константу" << endl;
        cin >> con;
        //a+con
        cout << "a+con: " << endl;
        c = a + con;
        cout << c;
        //a-con
        cout << "a-con: " << endl;
        c = a - con;
        cout << c;
        //a*con
        cout << "a*con: " << endl;
        c = a * con;
        cout << c;
    }
		catch (vectorissue2) {
			std::cout << "Разные размерности!НЕдопустимо!\n";
    }
    //-----------------------------------
    try {
        //a+=b
        cout << "a+=b: " << endl;
        c = a;
        c += b;
        cout << c;
        //a-=b
        cout << "a-=b: " << endl;
        c = a;
        c -= b;
        cout << c;
        //скалярное произведение a*=b
        cout << "a*=b: " << endl;
        c = a;
        c *= b;
        cout << c;
        //скалярное произведение a*=d(исключение)
        cout << "a*=d: " << endl;
        c = a;
        c *= d;
        cout << c;
    }
		catch (vectorissue2) {
			std::cout << "Разные размерности!НЕдопустимо!\n";
    }
    //-----------------------------------
    try {//без исключений
        //a+=con
        cout << "a+con: " << endl;
        c = a;
        c += con;
        cout << c;
        //a-=con
        cout << "a-con: " << endl;
        c = a;
        c -= con;
        cout << c;
        //a*=con
        cout << "a*con: " << endl;
        c = a;
        c *= con;
        cout << c;
    }
    catch (vectorissue2) {
			std::cout << "Разные размерности!НЕдопустимо!\n";
    }
    //------------------------------------------
    len = a.lenght();
    cout << "Длинна вектора a: " << len << endl;
    len = b.lenght();
    cout << "Длинна вектора b: " << len << endl;
    //------------------------------------------
    try {
        cout << "Какую координату в векторе a Вы хотите вывести?" << endl;
        cin >> i;
        cout << a[i] << endl;
        cout << a[-1] << endl;//исключение из-за несуществующего исключения
    }
    catch (vectorissue1) {
			std::cout << "НЕдопустимый индекс\n";
    }
    
}
