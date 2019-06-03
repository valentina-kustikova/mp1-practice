#include "Container.h"

using namespace std;

int main()
{
	Container<int> x;
	try
	{
		x.Add(1);
		x.Add(2);
		x.Add(3);
		x.Add(x.Find(2));
		x.Delete(2);
		x.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "Version 2:" << endl;
	Container<int*> x1;
	try
	{
		x1.Add(11);
		x1.Add(12);
		x1.Add(13);
		x1.Add(x1.Find(12));
		x1.Delete(12);
		x1.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}

	/////////////////ERRORS//////////////////

	cout << "Error test:" << endl;
	Container<int> a;
	try
	{
		a.Delete(2);
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Container<int> b;
	try
	{
		b.Add(1);
		b.Delete(1);
		b.Delete(b.Find(1));
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Container<int> c;
	try
	{
		c.Add(1);
		c.Delete(c.Find(2));
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Container<int> d;
	try
	{
		d.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	cout << "Error test 2:" << endl;
	Container<int*> a1;
	try
	{
		a1.Delete(2);
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Container<int*> b1;
	try
	{
		b1.Add(1);
		b1.Delete(1);
		b1.Delete(b1.Find(1));
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Container<int*> c1;
	try
	{
		c1.Add(1);
		c1.Delete(c1.Find(2));
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	Container<int*> d1;
	try
	{
		d1.print();
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
	system("pause");
	return 1;
}