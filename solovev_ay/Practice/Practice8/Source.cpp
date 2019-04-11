#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

int main() {
	try
	{
		double d = 0.0f;
		std::cout << "Enter number: d=";
		std::cin >> d;
		std::cout << "---------------- MATRIX 1\n";
		Matrix m1;
		m1.Inputmatrix();
		m1.PrintMatrix();

		std::cout << "---------------- MATRIX 2\n";
		Matrix m2;
		m2.Inputmatrix();
		m2.PrintMatrix();

		Matrix m3;
		m3 = m1 * m2;
		m3.PrintMatrix();
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
	system("pause");
}