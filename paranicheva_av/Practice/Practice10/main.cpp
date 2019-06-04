#include <iostream>
#include "Container.h"
#include "ContainerA.h"
using namespace std;

void main()
{
	int _size;
	const int _maxsize  = 20;
	cout << "Enter array size" << endl;
	cin >> _size;
	int n;
	Container<int, _maxsize> A(10);

	try
	{
		cin >> A;
		cout << A;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to find" << endl;
		cin >> n;
		cout << A.Find(n) << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter a new array element" << endl;
		cin >> n;
		A.Add(n);
		cout << A;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to delete" << endl;
		cin >> n;
		A.Delete(n);
		cout << A;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		int i;
		cout << "Enter index" << endl;
		cin >> i;
		cout << A[i] << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	////////////
	int _s;
	_s = _size;
	int nn;
	Container<int*, _maxsize> B(10);

	try
	{
		cin >> B;
		cout << B;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to find" << endl;
		cin >> nn;
		cout << B.Find(nn) << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter a new array element" << endl;
		cin >> nn;
		B.Add(nn);
		cout << B;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to delete" << endl;
		cin >> nn;
		B.Delete(nn);
		cout << B;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		int i;
		cout << "Enter index" << endl;
		cin >> i;
		cout << B[i] << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

}
