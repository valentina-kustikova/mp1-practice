#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

int main() {
	double d;
	int rofl;
	int menu = 100;
	cout << "vvedi const ";
	cin >> d;
	cout << "vvod matrix 1";
	Matrix m1;
	m1.Inputmatrix();
	m1.PrintMatrix();
	cout << "vvod matrix 2";
	Matrix m2;
	m2.Inputmatrix();
	m2.PrintMatrix();
	Matrix m3;
	cout << "1)1+2\n2)m1+d\n3)m1-m2\n4)m1-d\n5)m1*m2" << endl;
	do {
		cin >> menu;
		try
		{
			switch (menu)
			{
			case 1:
				m3 = m1 + m2;
				m3.PrintMatrix();
				break;
			case 2:
				m3 = m1 + d;
				m3.PrintMatrix();
				break;
			case 3:
				m3 = m1 - m2;
				m3.PrintMatrix();
				break;
			case 4:
				m3 = m1 - d;
				m3.PrintMatrix();
				break;
			case 5:
				m3 = m1 * m2;
				m3.PrintMatrix();
				break;
				}
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
	} while (menu != 12);
}