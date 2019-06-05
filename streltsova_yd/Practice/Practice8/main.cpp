#include "Matrix.h"
#include <iostream>
using namespace std;
void main()
{
    Matrix A(3, 3), B(3, 3), C(3, 2), E(2, 3);
    cout << "Enter matrix A (3 x 3)" << endl;
    cin >> A;
    cout << "Enter matrix B (3 x 3)" << endl;
    cin >> B;
    cout << "Enter matrix C (3 x 2)" << endl;
    cin >> C;
    cout << "Enter matrix E (2 x 3)" << endl;
    cin >> E;
    cout << "A + B = " << endl;
    try
    {
        Matrix D = A + B;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A + C = " << endl;
    try
    {
        Matrix D = A + C;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A - B = " << endl;
    try
    {
        Matrix D = A - B;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A - C = " << endl;
    try
    {
        Matrix D = A - C;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A * B = " << endl;
    try
    {
        Matrix D = A * B;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A * C = " << endl;
    try
    {
        Matrix D = A * C;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A * E = " << endl;
    try
    {
        Matrix D = A * E;
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    double a = 5;
    cout << "A + 5 = " << endl;
    Matrix D = A + 5;
    try
    {
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A - 5 = " << endl;
    D = A - 5;
    try
    {
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
    cout << "A * 5 = " << endl;
    D = A * 5;
    try
    {
        cout << D;
    }
    catch (const char* a)
    {
        cout << a << endl << endl;
    }
}