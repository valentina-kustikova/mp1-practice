#include "Todolist.h"
#include "Time.h"
#include "Date.h"
#include "Exception.h" 
#include <iostream>
#include <conio.h>
#include "Task.h"
using namespace std;

int main()
{
	
	try
	{
		Todolist l;
		Date d;
		cout << "Enter date: ";
		cin >> d;
		l.read();
		l.print(d);
	}
	catch (Exception e)
	{
		e.Print();
	}
}