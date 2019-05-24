#pragma once
#include <iostream>
#include "Header_Matrix.h"
using namespace std;

int main()
{
	int i;
    Matrix m1;
    Matrix m2(2, 2);
    m2.Input();
	m2.Output();
    Matrix m3(2, 3);
	m3.Input();
	m3.Output();
    try
    {
        m1 = m3 + m2;
        cout << "Operator + : m1 = m2 + m1" << endl;
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
		m1.Output();
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
		m2.Output();
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
		m3.Output();
    }
    catch (const char* a)
    {
        cout << a << endl;
    }


    try
    {
        m1 = m3 - m2;
        cout << "Operator - :m1 = m2 - m1" << endl;
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
		m1.Output();
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
        m1 = m3 * m2;
        cout << "Operator * :m1 = m2 * m1" << endl;
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
		m1.Output();
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    m1 = m3 + 2.0;
    cout << "m1 = m3 + 2.0" << endl;
    try
    {
        m1.Output();
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    try
    {
        cout << "m2[1] = " << *m2[1] << endl;
        *m2[1] = 2.0;
        cout << "m2[1] = 1 = " << *m2[1] << endl;
    }
    catch (const char* a)
    {
        cout << a << endl;
    }

    cin >> i;
    return 0;
} 