#pragma once
#include <iostream>
#include "Container1.h"
#include "Container2.h"
#define MAXSIZE 5
using namespace std;

void main()
{
	cout << "Container1:" << endl;
	int count;
	cout << "Count = ";
	cin >> count;
	Container1<int> Container_1(MAXSIZE);
	cout << "Container1 = " << endl;
    cin  >> Container_1;
	cout << "Container1(Fill) = " << Container_1 << endl;
	Container1<int> COPYContainer_1(Container_1);
	COPYContainer_1.Add(5);
	cout << "COPYContainer_1 = " << COPYContainer_1 << endl;	
	COPYContainer_1.Add(12);
	cout << "COPYContainer_1 = " << COPYContainer_1 << endl;
	cin  >> COPYContainer_1;
	COPYContainer_1.IsEmpty();
	try
	{ 
		COPYContainer_1.Delete(4);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}



	cout << "Container2" << endl;
	int count;
	cout << "Count = ";
	cin >> count;
	Container1<int*> Container_2(MAXSIZE);
	cout << "Container2 = " << endl;
	cin  >> Container_2;
	cout << Container_2 << endl;//OUTPUT
	Container1<int*> COPYContainer_2(Container_2);
	int a = 5;
	COPYContainer_2.Add(&a);
	cout << "COPYContainer_2 = " << COPYContainer_2 <<endl;
	int b = 12;
	COPYContainer_2.Add(&b);
	cout << "COPYContainer_2 = " << COPYContainer_2 <<endl;
	cin  >> COPYContainer_2;
	COPYContainer_2.IsEmpty();
	try
	{
		Container_2.Delete(4);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}

