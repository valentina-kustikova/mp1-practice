#include "WhatToDo.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ToDoList list;
	int f = 0;
	do {
		try
		{
			list.read_tasks();
			f = 1;
		}
		catch (const char* k)
		{
			cout << k << endl;
			char stop;
			cin >> stop;
			return 1;
		}
	} while (f != 1);
	f = 0;
	/*do {
		try
		{
			list.print_tasks();
			f = 1;
		}
		catch (const char* k)
		{
			cout << k << endl;
		}
	} while (f != 1);
	f = 0;
	//uncommit it to see in console what is in your file
	*/
	do {
		try
		{
			list.print_tasks_by_date();
			f = 1;
		}
		catch (const char* k)
		{
			cout << k << endl;
		}
	} while (f != 1);
	char stop1;
	cin >> stop1;
	return 1;
}