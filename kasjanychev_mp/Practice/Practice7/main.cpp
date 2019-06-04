#pragma once
#include "vectors.h"
#include <iostream>
using namespace std;
void main()
{
    int n;
    cout << "Vvedite kol-vo koordinat ";
    cin >> n;
    Vectors a = Vectors(n);

    try
    {
        a.ScVec();
    }
    catch (char* er)
    {
        cout << er;
    }
    a.PrVec();

    cout << "Vvedite kol-vo koordinat ";
    cin >> n;
    Vectors b = Vectors(n);

    try
    {
        b.ScVec();
    }
    catch (char* er)
    {
        cout << er;
    }
    b.PrVec();

    Vectors c;
    cout << "c = a + b";
	try
	{
		c = a + b;
	}
	catch (char* er)
	{
		cout << er;
	}
    c.PrVec();
    cout << "c = a - b";
	try
	{
		c = a - b;
	}
	catch (char* er)
	{
		cout << er;
	}
    c.PrVec();
    cout << "c += 5";
    c = c + 5;
    c.PrVec();
    cout << "c -= 3";
    c = c - 3;
    c.PrVec();
    cout << "c *= 1.5";
    c *= 1.5;
    c.PrVec();

    double x;
    try
    {
        x = a * b;
    }
    catch (char* er)
    {
        cout << er;
    }
    cout << "a * b = " << x;

    try
    {
        x = c.Lenght();
    }
    catch (char* er)
    {
        cout << er;
    }
    cout << "c.len = " << x;

    try
    {
        cout << "c[0] = " << c[0];
    }
    catch (char* er)
    {
        cout << er;
    }

    try
    {
        c[0] = 10;
        cout << "c[0] = 10 = " << c[0];
    }
	catch (char* er)
	{
		cout << er;
	}
}