#include <iostream>
#include "vector.h"
#include "locale.h"
#include "Exception.h"
using namespace std;
void main() {
	try {
		int n, i;
		double con, len;
		setlocale(LC_ALL, "Rus");
		cout << "Введите размерность векторов" << endl;
		cin >> n;
		vector a(n), b(n), c(n);
		a.Input();
		b.Input();
		cout << "Координаты вектора a: ";
		a.Output();
		cout << "Координаты вектора b: ";
		b.Output();
		cout << "Координаты вектора c: ";
		c.Output();
		//----------------------------------
		//a+b
		cout << "a+b: " << endl;
		c = a + b;
		c.Output();
		//a-b
		cout << "a-b: " << endl;
		c = a - b;
		c.Output();
		//скалярное произведение a*b
		cout << "a*b: " << endl;
		c = a * b;
		c.Output();
		//-----------------------------------
		cout << "Введите константу" << endl;
		cin >> con;
		//a+con
		cout << "a+con: " << endl;
		c = a + con;
		c.Output();
		//a-con
		cout << "a-con: " << endl;
		c = a - con;
		c.Output();
		//a*con
		cout << "a*con: " << endl;
		c = a * con;
		c.Output();
		//-----------------------------------
		//a+=b
		cout << "a+=b: " << endl;
		c = a;
		c += b;
		c.Output();
		//a-b
		cout << "a-=b: " << endl;
		c = a;
		c -= b;
		c.Output();
		//скалярное произведение a*=b
		cout << "a*=b: " << endl;
		c = a;
		c *= b;
		c.Output();
		//-----------------------------------
		//a+=con
		cout << "a+con: " << endl;
		c = a;
		c += con;
		c.Output();
		//a-=con
		cout << "a-con: " << endl;
		c = a;
		c -= con;
		c.Output();
		//a*=con
		cout << "a*con: " << endl;
		c = a;
		c *= con;
		c.Output();
		//------------------------------------------
		len = a.lenght();
		cout << "Длинна вектора a: " << len << endl;
		len = b.lenght();
		cout << "Длинна вектора b: " << len << endl;
		//------------------------------------------
		cout << "Какую координату в векторе a Вы хотите вывести?" << endl;
		cin >> i;
		cout << a[i] << endl;
	}
	catch (Exception ex)
	{
		ex.Print();
	}
}
