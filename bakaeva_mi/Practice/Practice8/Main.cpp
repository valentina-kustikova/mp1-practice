#include "Matrix.h"
#include "Exception.h"
#include <iostream>
#include "conio.h"
using namespace std;

void main()
{
    double con = 5;
    int a[6] = { 1, 5, 6, 8, 3, 7 };
    Matrix    A(a, 3, 2), B(2, 3), C(3, 2), Res(3, 2);

    cout << "         MATRIX TEST\n" << endl;
    try
    {
        cout << "  Matrix #1\n" << endl;
        A.Output();
        cout << "  Matrix #2\n" << endl;
        B.Output();
        cout << "  Matrix #3\n" << endl;
        C.Output();

        cout << "  M1 + M3\n" << endl;
        Res = (A + C);
        Res.Output();

        cout << "  M1 * M2\n" << endl;
        Res = (A * B);
        Res.Output();

        cout << "  M1 - M3\n" << endl;
        Res = (A - C);
        Res.Output();

        cout << "  M1 * 5\n" << endl;
        Res = (A * con);
        Res.Output();
        cout << "  M2 * 5\n" << endl;
        Res = (B * con);
        Res.Output();
        cout << "  M3 * 5\n" << endl;
        Res = (C * con);
        Res.Output();

        cout << "  M1 + 5\n" << endl;
        Res = (A + con);
        Res.Output();
        cout << "  M2 - 5\n\n" << (B - con) << endl;

        cout << "  3 Line address:  " << A[3] << endl;
        cout << "  M2[2][2] =  " << B[1][1] << "\n" << endl;

        cout << "  M1 + M3" << endl;
        cout << A + B << endl;
    }
    catch (Exception exp)
    {
        exp.Print();
    }
}