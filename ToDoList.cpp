#pragma once
#include <iostream>
#include "ToDoList.h"
#include "TaskTypes.h"
#include"Date.h"
#include "Time.h"
#include <fstream>
using namespace std;

ToDoList::ToDoList()
{
	tasks = NULL;
	amount_of_tasks = 0;
}
ToDoList::ToDoList(int amount_of_tasks)
{
	this->amount_of_tasks = amount_of_tasks;
	tasks = new Tasks*[amount_of_tasks];
}
ToDoList::~ToDoList()
{
	for (int i = 0; i < amount_of_tasks; i++)
		delete[]tasks[i];
	delete[]tasks;
	amount_of_tasks = 0;
}
void ToDoList::Read(const char* a)
{
	int buff = 50;
	ifstream file(a);
	if (!file.is_open())
		throw "File is not open";
	file >> buff;
	int type;
	int day, month, year;
	unsigned minutes, hours, duration;
	char* b = new char[50];
	for (int i = 0; i < buff; i++)
	{
		file >> type;
		if (type == 1)
		{
			file >> day >> month >> year;
			file.getline(b, 50);
			Date date = Date(day, month, year);
			tasks[i] = new Type1(b, date);
		}
		if (type == 2)
			file >> day >> month >> year >> minutes >> duration;
			Date date = Date(day, month, year);
			Time time = Time(hours, minutes);
			file.getline(b, 50);
			tasks[i] = new Type2(b, date, duration, time);

	}
	file.close();
	
}
void ToDoList::Print(Date d)const
{
	cout << "Date: ";
	d.PrintDate();
	for (int i = 0; i < amount_of_tasks; i++)
		if (tasks[i] -> GetDate() == d)
	{
		tasks[i]->Print();
		cout << endl;
	}
		
}