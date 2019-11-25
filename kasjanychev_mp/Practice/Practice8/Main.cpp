#include "Matrix.h"
#include <iostream>
using namespace std;

void main()
{
	int m, n;
	cout << "Vvedite razmernost";
	cin >> n >> m;
	Matrix a = Matrix(n, m);
	a.ScMat();
	a.PrMat();
	cout << "Vvedite razmernost";
	cin >> n >> m;
	Matrix b = Matrix(n, m);
	b.ScMat();
	b.PrMat();
	Matrix c;

	cout << "a + b" << endl;
	try
	{
		c = a + b;
	}
	catch (char* er)
	{
		cout << er;
	}
	c.PrMat();

	cout << "a - b" << endl;
	try
	{
		c = a - b;
	}
	catch (char* er)
	{
		cout << er;
	}
	c.PrMat();

	cout << "a * b" << endl;
	try
	{
		c = a * b;
	}
	catch (char* er)
	{
		cout << er;
	}
	c.PrMat();

	cout << "a + 5";
	c = a + 5;
	c.PrMat();

	cout << "a - 3";
	c = a - 3;
	c.PrMat();

	cout << "a * 1.5";
	c = a * 1.5;
	c.PrMat();

	try
	{
		cout << "c[0] = " << *c[0];
	}
	catch (char* er)
	{
		cout << er;
	}

	try
	{
		*c[0] = 10;
		cout << "c[0] = 10 = " << *c[0];
	}
	catch (char* er)
	{
		cout << er;
	} cin >> n;
}