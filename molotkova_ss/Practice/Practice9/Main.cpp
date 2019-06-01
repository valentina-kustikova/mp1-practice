#include <iostream>
#include"Date.h"
#include"Time.h"
#include"ToDoList.h"
#include"TaskTypes.h"
#include <fstream>
#include <string>
using namespace std;

void main()
{
	ToDoList list;
	char path[50];
	cin >> path;
	try
	{
		list.Read(path);
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
	int d, m, y;
	cout << "Day:";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	Date date = Date(d, m, y);
	list.Print(date);
}