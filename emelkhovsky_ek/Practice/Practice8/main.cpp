#include"iostream"
#include"matrix.h"
#include"locale.h"
#include "Exception.h"
using namespace std;
void main() {
	try {
	int con;
	setlocale(LC_ALL, "Rus");
	matrix a, b, mat3;
	a.input();
	b.input();
	cout << "1а€ матрица: " << endl;
	a.output();
	cout << "2а€ матрица: " << endl;
	b.output();
	cout << "3а€ матрица: " << endl;
	mat3.output();
	//----------------------------------
	//a+b
	cout << "a+b: " << endl;
	mat3 = a + b;
	mat3.output();
	//a-b
	cout << "a-b: " << endl;
	mat3 = a - b;
	mat3.output();
	//a*b
	cout << "a*b: " << endl;
	mat3 = a * b;
	mat3.output();
	//-----------------------------------
	cout << "¬ведите константу" << endl;
	cin >> con;
	//a+con
	cout << "a+con: " << endl;
	mat3 = a + con;
	mat3.output();
	//a-con
	cout << "a-con: " << endl;
	mat3 = a - con;
	mat3.output();
	//a*con
	cout << "a*con: " << endl;
	mat3 = a * con;
	mat3.output();
	//-----------------------------------
	//a+=b
	cout << "a+=b: " << endl;
	mat3 = a;
	mat3 += b;
	mat3.output();
	//a-b
	cout << "a-=b: " << endl;
	mat3 = a;
	mat3 -= b;
	mat3.output();
	//-----------------------------------
	//a+=con
	cout << "a+con: " << endl;
	mat3 = a;
	mat3 += con;
	mat3.output();
	//a-=con
	cout << "a-con: " << endl;
	mat3 = a;
	mat3 -= con;
	mat3.output();
	//a*=con
	cout << "a*con: " << endl;
	mat3 = a;
	mat3 *= con;
	mat3.output();
}
catch (Exception ex)
{
	ex.Print();
}
}