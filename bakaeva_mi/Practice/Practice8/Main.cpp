#include "Matrix.h"
#include <iostream>
#include "conio.h"
using namespace std;

void main()
{
    double con = 5;
    float a[6] = { 1.32, 5.2, 6.12, 8.03, 3.3, 7.3 };
    float b[6] = { 1.03, 5.43, 6.28, 1.62, 6.55, 5.97 };
    float c[6] = { 9.82, 0.95, 5.09, 6.78, 8.98, 6.22 };
    Matrix    A(a, 3, 2), B(b, 2, 3), C(c, 3, 2), Res(3, 2);

    cout << "         MATRIX TEST\n" << endl;
    cout << "  Matrix #1\n" << endl;
    A.Output();
    cout << "  Matrix #2\n" << endl;
    B.Output();
    cout << "  Matrix #3\n" << endl;
    C.Output();
    cout << "  --------------------------------------  " << endl;
    try
    {
        cout << "  M1 + M3\n" << endl;
        cout << A + C;
        cout << "  M1 + M2 = ";
        cout << A + B << endl;
    }
    catch (Exception_sizes& e)
    {
        cerr << e.what() << endl;
    }
    cout << "  --------------------------------------  " << endl;
    try
    {
        cout << "  M1 * M2\n" << endl;
        Res = (A * B);
        Res.Output();

        cout << "  M1 - M3\n" << endl;
        Res = (A - C);
        Res.Output();

        cout << "  M1 * M3 = ";
        Res = (A * C);
        Res.Output();
    }
    catch (Exception_sizes& e)
    {
        cerr << e.what() << endl;
    }
    cout << "  --------------------------------------  " << endl;
    cout << "  M1 * 5\n" << endl;
    Res = (A * con);
    Res.Output();
    cout << "  M1 + 5\n" << endl;
    Res = (A + con);
    Res.Output();
    cout << "  M2 - 5\n\n" << (B - con);
    cout << "  --------------------------------------  " << endl;
    try
    {
        cout << "  3 Line address:  " << A[3] << endl;
        cout << "  M2[2][2] =  " << B[1][1] << endl;
        cout << "  M2[4][5] =  ";
        cout << B[4][5] << "\n" << endl;
    }
    catch(Exception_ind& e)
    {
        cerr << e.what() << endl;
    }
}