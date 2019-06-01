#pragma once
#include <iostream>
#include "ToDoList.h"
#include "TaskTypes.h"
#include"Date.h"
#include "Time.h"
#include <fstream>
#include <string>
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
void ToDoList::Read(char* a)
{
	int buff = 50;
	ifstream file(a);
	if (!file.is_open())
		throw "File is not open";
	file >> buff;
	amount_of_tasks = buff;
	tasks = new Tasks*[buff];
	int type;
	int day, month, year;
	unsigned minutes, hours, duration;
	char* b = new char[50];
	string s, ss; //строка и подстрока
	for (int i = 0; i < buff; i++)
	{
		file >> type;
		if (type == 1)
		{
			int start, end;
			file.getline(b, 50);
			s = string(b);
			end = s.find(".");	
			start = s.rfind(" ", end);
			ss = s.substr(start + 1, end - start - 1);
			day = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find(".", start + 1);
			ss = s.substr(start + 1, end - start - 1);
			month = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find(" ", start);
			ss = s.substr(start + 1, end - start - 1);
			year = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find("\0", start);
			ss = s.substr(start + 1, end - start - 1);//описание
			Date date = Date(day, month, year);
			tasks[i] = new Type1(ss, date);
		}
		if (type == 2)
		{
			int start, end;
			file.getline(b, 50);
			s = string(b);
			end = s.find(".");
			start = s.rfind(" ", end);
			ss = s.substr(start + 1, end - start - 1);
			day = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find(".", start + 1);
			ss = s.substr(start + 1, end - start - 1);
			month = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find(" ", start);
			ss = s.substr(start + 1, end - start - 1);
			year = atoi(ss.c_str());
			ss = "";
			end = s.find(":");
			start = s.rfind(" ", end);
			ss = s.substr(start + 1, end - start - 1);
			hours = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find(" ", start);
			ss = s.substr(start + 1, end - start - 1);
			minutes = atoi(ss.c_str());
			ss = "";
			start = s.find_first_of("0123456789", end);
			end = s.find(" ", start);
			ss = s.substr(start, end - start);
			duration = atoi(ss.c_str());
			ss = "";
			start = end;
			end = s.find("\0", start);
			ss = s.substr(start + 1, end - start - 1);

			Date date = Date(day, month, year);
			Time time = Time(hours, minutes);
			
			tasks[i] = new Type2(ss, date, duration, time);
		}
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