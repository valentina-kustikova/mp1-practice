#include "Matrix.h"

using namespace std;

int main()
{
	Matrix A(4, 4), B(4, 4), C(3, 3), D, F;
	A.RandomInput();
	B.RandomInput();
	C.RandomInput();
	cout << "Matrix A: ";
	A.Output();
	cout << "Matrix B: ";
	B.Output();
	cout << "Matrix C: ";
	C.Output();

	cout << "B[1][1] = ";
	try
	{
		cout << B[1][1] << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}

	cout << "A[5][3] = ";
	try
	{
		cout << A[5][3] << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}

	cout << "A + B = ";
	try
	{
		D = A + B;
		D.Output();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}

	cout << "A + C = ";
	try
	{
		D = A + C;
		D.Output();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "A - B = ";
	try
	{
		D = A - B;
		D.Output();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "A - C = ";
	try
	{
		D = A - C;
		D.Output();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "A * B = ";
	try
	{
		D = A * B;
		D.Output();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "A * C = ";
	try
	{
		D = A * C;
		D.Output();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	double x;
	cout << "Enter a number: ";
	cin >> x;
	cout << "A + " << x << " = ";
	D = A + x;
	D.Output();
	cout << "A - " << x << " = ";
	D = A - x;
	C.Output();
	cout << "A * " << x << " = ";
	D = A * x;
	D.Output();
	cout << "A * B = " << endl;
	int sdsf;
	std::cin >> sdsf;
}