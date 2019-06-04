#include <iostream>
#include <fstream>
#include <string>
#include "Task.h"
#include "Date.h"
#include "Time.h"
#include "ToDoList.h"

using namespace std;

Todolist::Todolist()
{
    tasks = NULL;
    count = 0;
}

Todolist::Todolist(int _count)
{
    count = _count;
    tasks = new Task*[count];
}

Todolist::~Todolist()
{
    for (int i = 0; i < count; i++)
        delete[] tasks[i];
    delete[] tasks;
    count = 0;
}

void Todolist::Read(std::string &path)
{
	fstream file;
	file.open(path);
	if (!file.is_open())
		throw "File not found";

	string c;
	getline(file, c);// считывание кол-ва задач всего
	count = atoi(c.c_str());

	tasks = new Task*[count]; 
	int _d, _m, _y, _min, _h, _duration, _type;
	string str;
	int k = 0, n, nn;

	do
	{
		getline(file, str);
		char _description[100] = {0};
		char ss[2] = {0};
		char sss[4] = {0};
		n = str.find_first_not_of("Type ");
		ss[0] = str[n];
		_type = atoi(ss);
		cout << "Type " << _type << "  ";
		

		nn = str.find_first_of("1234567890", n + 1);
		ss[0] = str[nn];
		ss[1] = str[nn + 1];
		_d = atoi(ss);
		cout <<  _d << "/";

		n = str.find("/");
		nn = str.find_first_of("1234567890", n + 1);
		ss[0] = str[nn];
		ss[1] = str[nn + 1];
		_m = atoi(ss);
		cout << _m << "/";

		n = str.find_last_of("/");
		nn = str.find_first_of("1234567890", n + 1);
		for(int i = 0; i < 4; i++)
			sss[i] = str[nn + i];
		_y = atoi(sss);
		cout << _y << "  ";

		if (_type == 2)
		{
		n = str.find_first_of("1234567890", nn + 4);
		ss[0] = str[n];
		ss[1] = str[n + 1];
		_h = atoi(ss);
		cout << _h << ":";

		n = str.find(":");
		nn = str.find_first_of("1234567890", n + 1);
		ss[0] = str[nn];
		ss[1] = str[nn + 1];
		_min = atoi(ss);
		cout << _min << "  ";
		}

		n = str.find("\"");
		nn = str.find_last_of("\"");
		for(int i = n; i < nn + 1; i++)
		_description[i - n] = str[i];
		_description[nn + 1] = '\0';
		cout << _description << "  ";
		if (_type == 2)
		{
		n = str.find_first_of("1234567890", nn + 1);
		ss[0] = str[n];
		ss[1] = str[n + 1];
		_duration = atoi(ss);
		cout << _duration;
		}
		cout <<  endl;

			

		if (_type == 1)
		{
			Date _date(_d, _m, _y);
			tasks[k] = new Type1(_date, _description);
		}
		if (_type == 2)
		{
			cout << _y << endl;
			Date _date = Date(_d, _m, _y);
			Time _time = Time(_min, _h);
			tasks[k] = new Type2(_date, _description, _duration, _time);
		}
		k++;
	}
	while (!file.eof());
	file.close();
}
void Todolist::Print()
{
	cout << "Enter the date you are interested in" << endl;
	int _d, _m, _y;
	cout << "Day is " << endl;
	cin >> _d;
	cout << "Month is " << endl;
	cin >> _m;
	cout << "Year is " << endl;
	cin >> _y;
	Date tada(_d, _m, _y);

	cout << "List of your tasks:" << endl;
	int k = 0;
	for (int i = 0; i < count; i++)
	{
		if (tasks[i]->date == tada)
		{
		tasks[i]->Print();
		k++;
		}
	}
	cout << "The number of tasks on the selected day  " << k << endl;
}
