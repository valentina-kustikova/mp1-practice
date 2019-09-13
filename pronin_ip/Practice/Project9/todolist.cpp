#include "todolist.h"
#include <fstream>
#include <string>
#include "taskall.h"
#include "tasktime.h"
#include "time.h"
using namespace std;
Todolist::Todolist()
{
	count = 0;
	tasks = NULL;
}
Todolist::Todolist(int _count)
{
	count = _count;
	tasks = new Task*[count];
}
Todolist::Todolist(int _count, Task** _tasks)
{
	count = _count;
	tasks = new Task*[count];
	for (int i = 0; i < count; i++)
	{
		tasks[i] = _tasks[i];
	}
}
Todolist::Todolist(const Todolist& a)
{
	count = a.count;
	tasks = new Task*[count];
	for (int i = 0; i < count; i++)
		tasks[i] = a.tasks[i];
}
Todolist::~Todolist()
{
	count = 0;
	delete *tasks;
}
void Todolist::Read(const string namefile)
{
	ifstream file;
	file.open(namefile);
	if (!file.is_open())
	{
		cout << "Cant open this file" << endl;
	}
	else
	{
		cout << "File is open" << endl;
		int type;
		Date date;
		Time timestart;
		Time timefinish;
		string discription;
		file >> count;
		tasks = new Task*[count];
		for (int i = 0; i < count; i++)
		{
			file >> type;
			if (type == 1)
			{
				file >> date;
				getline(file, discription);
				tasks[i] = new Taskall(discription, date);
			}
			if (type == 2)
			{
				file >> date;
				file >> timestart;
				file >> timefinish;
				getline(file, discription);
				tasks[i] = new Tasktime(discription, date, timestart, timefinish);
			}
		}
	}
	file.close();
}
void Todolist::Print(Date _date)
{
	bool flag = 0;
	for (int i = 0; i < count; i++)
	{
		if (tasks[i]->date == _date)
		{
			tasks[i]->print();
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "Date is not found" << endl;
}