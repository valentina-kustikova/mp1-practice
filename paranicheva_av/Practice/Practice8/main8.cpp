#include <iostream>
#include "Head.h"
using namespace std;

void main()
{
	int cols1, cols2, rows1, rows2;

	cout << "Enter the number of rows of the matrix a" << endl;
	cin >> rows1;
	cout << "Enter the number of cols of the matrix a" << endl;
	cin >> cols1;
	cout << "Enter the number of rows of the matrix b" << endl;
	cin >> rows2;
	cout << "Enter the number of cols of the matrix b" << endl;
	cin >> cols2;

	Matrix a(rows1, cols1), b(rows2, cols2), c;
	cin >> a;
	cout << a;
	cin >> b;
	cout << b;
	int k, i;
	do
	{
		double num;
		cout << "1) a + b   2) a - b   3) a * b \n4) c = a " << endl;
		cout << "5) a + num\n  6) a - num  7) a * num 8) a[1] \n" << endl;
		cin >> k;
		switch(k)
		{
			case 1:
				try
				{
					c = a + b;
					cout >> c;
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 2:
				try
				{
					c = a - b;
					cout >> c;
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 3:
				try
				{
					c = a * b; 
					cout >> c;
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 4:
				c = a;
				cout >> c;
				break;
			case 5:
				cout << "Insert the number " << endl;
				cin >> num;
				c = a + num;
				cout >> c;
				break;
			case 6:
				cout << "Insert the number " << endl;
				cin >> num;
				c = a - num;
				cout >> c;
				break;
			case 7:
				cout << "Insert the number " << endl;
				cin >> num;
				c = a * num;
				cout >> c;
				break;
			case 8:
				try
				{
					cout << *a[1] << endl;
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
		}
	}
	while(k != 9);
}
