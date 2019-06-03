#include "WhatToDo.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Time::Time()
{
	hour = 0;
	min = 0;
}

Time::Time(unsigned _hour, unsigned _min)
{
	if (_hour >= 24)
	{
		throw "Hour error";
	}
	if (_min >= 60)
	{
		throw "Minute error";
	}
	hour = _hour;
	min = _min;
}

Time::Time(const Time& _Time)
{
	hour = _Time.hour;
	min = _Time.min;
}

const Time & Time::operator=(const Time& _Time)
{
	hour = _Time.hour;
	min = _Time.min;
	return *this;
}

std::ostream & operator<<(std::ostream& x, const Time& _Time)
{
	if (_Time.hour < 10)
		x << "0" << _Time.hour << ":";
	else
		x << _Time.hour << ":";
	if (_Time.min < 10)
		x << "0" << _Time.min;
	else
		x << _Time.min;
	return x;
}

/////////////////////////////////////////////////////////////////////////

Date::Date()
{
	day = 0;
	mon = 0;
	year = 0;
}

Date::Date(unsigned _day, unsigned _mon, unsigned _year)
{
	if (_day > 31)
	{
		throw "Day error";
	}
	if (_mon > 12)
	{
		throw "Month error";
	}
	if ((_year % 400 == 0) || ((_year % 100 != 0) && (_year % 4 == 0)))
	{
		if ((_mon == 2) && (_day > 29))
			throw "February error (leap year)";
	}
	else
	{
		if ((_mon == 2) && (_day > 28))
			throw "February error (non-leap year)";
	}
	if ((_mon == 4) || (_mon == 6) || (_mon == 9) || (_mon == 11))
	{
		if (_day >= 31)
			throw "Day error (there is 30 days in this month)";
	}
	day = _day;
	mon = _mon;
	year = _year;
}

Date::Date(const Date& _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
}

const Date& Date::operator=(const Date & _Date)
{
	day = _Date.day;
	mon = _Date.mon;
	year = _Date.year;
	return *this;
}

bool Date::operator==(const Date& _Date)
{
	if ((day == _Date.day) && (mon == _Date.mon) && (year == _Date.year))
		return true;
	return false;
}

std::ostream & operator<<(std::ostream & x, const Date & _Date)
{
	if (_Date.day < 10)
		x << "0" << _Date.day << ".";
	else
		x << _Date.day << ".";
	if (_Date.mon < 10)
		x << "0" << _Date.mon << ".";
	else
		x << _Date.mon << ".";
	x << _Date.year;
	return x;
}

/////////////////////////////////////////////////////////////////////////

Task::Task()
{
	id = 0;
}

Task::~Task()
{
	id = 0;
	task = nullptr;
}
 
/////////////////////////////////////////////////////////////////////////

Type1::Type1()
{
	id = 1;
}

Type1::~Type1()
{
	id = 1;
	task = nullptr;
}

void Type1::print()
{
	std::cout << " " << date << " " << task << std::endl;
}

/////////////////////////////////////////////////////////////////////////

Type2::Type2()
{
	id = 2;
}

Type2::~Type2()
{
	id = 2;
	task = nullptr;
}

void Type2::set_start(Time x)
{
	time_1 = x;
}

void Type2::set_end(Time x)
{
	time_2 = x;
}

void Type2::print()
{
	std::cout << " " << date << " start: " << time_1 << " end: " << time_2 << " " << task << std::endl;
}

////////////////////////////////////////////////////////////////////////////////

void ToDoList::read_tasks()
{
	std::string str;
	std::ifstream file;
	char number_tasks[2];
	file.open("paper.txt");
	if (!file.is_open())
	{
		throw "Can't open this file";
	}
	file >> number_tasks;
	number = unsigned(stoul(number_tasks));
	tasks = new Task*[number];
	getline(file, str);
	for (int i = 0; i < number; i++)
	{
		getline(file, str);
		int _type = stoi(str);
		unsigned _day = unsigned(stoul(str.substr(2, 2)));
		unsigned _mon = unsigned(stoul(str.substr(5, 2)));
		unsigned _year = unsigned(stoul(str.substr(8, 4)));
		Date tmp(_day, _mon, _year);
		if (_type == 1)
		{
			Task* type1 = new Type1;
			type1->date = tmp;
			type1->task = str.substr(13);
			tasks[i] = type1;
		}
		else if (_type == 2)
		{
			Task* type2 = new Type2;
			type2->date = tmp;
			unsigned _h_start = unsigned(stoul(str.substr(13, 2)));
			unsigned _m_start = unsigned(stoul(str.substr(16, 2)));
			Time _start(_h_start, _m_start);
			type2->set_start(_start);
			unsigned _h_end = unsigned(stoul(str.substr(19, 2)));
			unsigned _m_end = unsigned(stoul(str.substr(22, 2)));
			type2->task = str.substr(25);
			Time _end(_h_end, _m_end);
			type2->set_end(_end);
			tasks[i] = type2;
		}
		else throw "Wrong type";
	}
	file.close();
}

void ToDoList::print_tasks()
{
	cout << "Your tasks: " << endl;
	for (int i = 0; i < number; i++)
		tasks[i]->print();
}

void ToDoList::print_tasks_by_date()
{
	unsigned _year, _mon, _day;
	cout << "Enter day: ";
	cin >> _day;
	cout << endl;
	cout << "Enter month: ";
	cin >> _mon;
	cout << endl;
	cout << "Enter year: ";
	cin >> _year;
	cout << endl;
	Date tmp(_day, _mon, _year);
	int flag = 0;
	for (int i = 0; i < number; i++)
	{
		if (tmp == tasks[i]->date)
		{
			tasks[i]->print();
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "This day is absolutely free, do whatever you want" << endl;
	}
}