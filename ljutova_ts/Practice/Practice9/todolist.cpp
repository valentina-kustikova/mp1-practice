#include "todolist.h" 
#include "Type1.h"
#include "Type2.h"
#include <iostream> 
#include <fstream>

using namespace std;

Todolist::Todolist()
{
	n = 0;
}

void Todolist::read(const string namef)
{
	string s;
	string description;
	int type;
	Date date;
	Time t1;
	Time t2;
    ifstream f;
    f.open(namef);
	if (!f.is_open())
		throw T1();
	f >> n; //считываем слова из файла
	task = new Task*[n];
	for (int i = 0; i < n; i++)
	{
		f >> type;
		if (type == 1)
		{
		    f >> date;
		    getline(f, description); //считывание
		    task[i] = new Type1(description, date);
		}
	
		else if (type == 2)
		{
		    f >> date >> t1 >> t2;
		    getline(f, description);
		    task[i] = new Type2(description, date, t1, t2);
		}
		else throw T2();
	}
	f.close();
}

void Todolist::print(Date _d)
{
	int fl = 0;
	
	for (int i = 0; i < n; i++)
	{
		
		if (task[i][0].GetDate() == _d)
		{
			cout << "Your have some plans: " << endl;
			task[i][0].Print();
			fl = 1;
		}
	}
	if (fl == 0)
		throw T3();
}

Todolist::~Todolist()
{
	n = 0;
	delete[] task;
}

const char* T1::what() const
{
    return what_str.c_str();
}
const char* T2::what() const
{
    return what_str.c_str();
}
const char* T3::what() const
{
    return what_str.c_str();
}