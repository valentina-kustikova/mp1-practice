#include "ToDoList.h"
#include <iostream>
using namespace std;

void main()
{
	ToDoList list;
	char adr[50];
	cin >> adr;
	try
	{
		list.Read(adr);
	}
	catch (const char* A)
	{
		cout << A << endl;
	}
	int y, m, d;
	cout << "Date: " << endl << "Day: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	Date date = Date(y, m, d);
	list.Vivod(date);
}