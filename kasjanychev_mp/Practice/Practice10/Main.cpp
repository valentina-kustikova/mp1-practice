#include "Container1.h"
#include "Container2.h"
#include <iostream>
using namespace std;

void main()
{
	Container<int> C1(10);
    cout << "Size = ";
    int size;
    cin >> size;
	try
	{
		C1.Fill(size);
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	try
	{
		C1.Add(5);
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	C1.Print();
	try
	{
		C1.Remove(1);
	}
	catch (char* er)
	{
		cout << er << endl;
	}
	C1.Print();
    try 
    {
       cout << "c1[0] = " << C1[0];
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    try
    {
        C1[0] = 5;
        cout << "c1[0] = 5" << C1[0];
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    C1.Print();

    Container<int*> C2(10);
    cout << "Size = ";
    cin >> size;
    try
    {
        C2.Fill(size);
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    try
    {
        C2.Add(5);
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    C2.Print();
    try
    {
        C2.Remove(1);
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    C2.Print();
    try
    {
        cout << "c2[0] = " << C2[0];
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    try
    {
        C2[0] = 5;
        cout << "c[0] = 5" << C2[0];
    }
    catch (char* er)
    {
        cout << er << endl;
    }
    C2.Print();
}