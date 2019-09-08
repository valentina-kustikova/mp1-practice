#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "rofl.h"
using namespace std;

int main() {
	Vector a, b, c;
	int menu, index;
	int rofl;
	double m;
	cout << "vvedi vector a" << endl;
	a.Input();
	cout << "vvedi vector b" << endl;
	b.Input();
	cout << "Vvedi const m" << endl;
	cin >> m;
	cout << "Vvedi nomer elementa" << endl;
	cin >> index;
	cout << "1)a+b\n2)a+m\n3)a+=6\n4)a-b\n5)a-m\n6)a-=6\n7)a*b\n8)a*m\n9)*m\n10)nuzhniy element\n11)dlina vectora" << endl;
	do {
		cin >> menu;
		try
		{
			switch (menu)
			{
			case 1:
				c = a + b;
				cout << c << endl;
				break;
			case 2:
				c = a + m;
				cout << c << endl;
				break;
			case 3:
				a += 6;
				cout << a << endl;
				break;
			case 4:
				c = a - b;
				cout << c << endl;
				break;
			case 5:
				c = a - m;
				cout << c << endl;
				break;
			case 6:
				a -= 6;
				cout << a << endl;
				break;
			case 7:
				a * b;
				cout << a << endl;
				break;
			case 8:
				c = a * m;
				cout << c << endl;
				break;
			case 9:
				c *= m;
				cout << c << endl;
				break;
			case 10:
				cout << "1)vector a\n2)vector b" << endl;
				cin >> rofl;
				switch (rofl)
				{
				case 1: cout << a[index] << endl;
					break;
				case 2: cout << b[index] << endl;
					break;
				}
			case 11:
				cout << "1)vector a\n2)vector b" << endl;
				cin >> rofl;
				switch (rofl)
				{
				case 1: cout << a.Length() << endl;
					break;
				case 2: cout << b.Length() << endl;
					break;
				}
			}
		}
		catch (exeption& exp)
		{
			switch (exp.exp_type)
			{
			case BadLength:
				cout << "dlini ne sovpadayut" << endl;
				break;
			case BadIndex:
				cout << "ne tot index" << endl;
				break;
			}
		}
	} while (menu != 12);
}
