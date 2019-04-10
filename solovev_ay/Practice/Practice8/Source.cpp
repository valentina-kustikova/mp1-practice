#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

int main() {
	double	m_a[6] = { 1, 1, 0, 2, -1, 2 },
			m_b[12] = { 2, 1, 0, 3, 1, 2, 4, -1, 3, 0, -2, 1 },
			m_c[4] = { 1, 2, -1, 3 },
			m_d[6] = { 0, 3, -1, 2, 4, -2 };

		try
		{
			// Объявление
			Matrix A(m_a, 2, 3), B(m_b, 3, 4), C(m_c, 2, 2), D(m_d, 2, 3);
			Matrix C_a(2, 2), A_a(2, 3);
			cout << "Matrix A :" << endl;
			A.PrintMatrix();
			cout << "Matrix B :" << endl;
			B.PrintMatrix();
			cout << "Matrix C :" << endl;
			C.PrintMatrix();
			cout << "Matrix D :" << endl;
			D.PrintMatrix();

			// Сложение и вычитание
			cout << "C + 5:" << endl;
			C_a = C + 5;
			C_a.PrintMatrix();
			cout << "A + D:" << endl;
			A + D;
			A.PrintMatrix();
			cout << "B - 3:" << endl;
			B - 3;
			B.PrintMatrix();
			cout << "A - D:" << endl;
			A - D;
			A.PrintMatrix();

			// Произведение
			cout << "C * 2:" << endl;
			C * 2;
			C.PrintMatrix();
			cout << "A * B:" << endl;
			A * B;

			// []
			cout << "Secound row of B: " << B[1] << endl;
		}
		catch (exeption& exp)
		{
			switch (exp.exp_type)
			{
			case Badparametrs:
				cout << "dlini ne sovpadayut" << endl;
				break;
			case BadIndex:
				cout << "ne tot index" << endl;
				break;
			}
		}
	
}