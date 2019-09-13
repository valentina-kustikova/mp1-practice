#include "Header.h"
void main()
{
	cout << "Hello" << endl;
	double mas[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double mas1[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double mas2[] = { 1, 2, 3, 4 };
	Matrix A(3, 3, mas);
	Matrix B(3, 3, mas1);

	cout << "A+5=" << A + 5 << endl;

	try {
		cout << "A+B=" << A + B << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}

	cout << "A-5=" << A - 5 << endl;

	try {
		cout << "A-B=" << A - B << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}

	cout << "A*5=" << A * 5 << endl;

	try {
		cout << "A*B=" << A * B << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	system("pause");

}