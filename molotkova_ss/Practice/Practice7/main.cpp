#pragma once
#include <iostream>
#include "Zag.h"
using namespace std;

void main()
{
	Vector a(3);//создать с параметрами
	a.Input();
	cout << " a output";
	a.Output();
	Vector b;
	b = a;//приравнять
	cout << " b = a" << " " << " b output";
	b.Output();
	Vector c;
	c = a + b;//сложение
	cout << " c = a + b";
	c.Output();
	Vector d;
	d = a - b;//сложение
	cout << " d = a - b";
	d.Output();
	double scal;
	scal = a * b;//скаляр
	cout << " scal" << scal;
	double leng = d.Length();
	cout << "lengths" << leng;
	*(a[2]) = 5;
	cout << " измененная третья координата";
	a.Output();
}