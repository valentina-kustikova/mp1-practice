#include <iostream>
#include <string>
#include "Task.h"
#include "Date.h"
#include "Time.h"
using namespace std;

Task::Task()
{
	date = Date(0,0,0);
	description = "";
}

Task::~Task()
{
	date.~Date();
	description = "";
}
Type1::Type1()
{
	date = Date(0,0,0);
	description = "";
}
Type1::Type1(Date _date, std::string _description)
{
	date = _date;
	description = _description;
}
Type1::~Type1()
{
	date.~Date();
	description.clear();
}
void Type1::Print()
{
	cout <<  date.Getd() << "/" << date.Getm() << "/" << date.Gety() << "  ";
	cout << description << endl;
	cout << endl;
}
Type2::Type2()
{
	date = Date(0,0,0);
	description = "";
	duration = 0;
	time = Time(0,0);
}
Type2::Type2(Date _date, std::string _description, int _duration, Time _time)
{
	date = _date;
	description = _description;
	duration = _duration;
	time = _time;
}
Type2::~Type2()
{
	duration = 0;
	time.~Time();
	date.~Date();
	description.clear();
}
void Type2::Print()
{
	cout <<  date.Getd() << "/" << date.Getm() << "/" << date.Gety() << "  ";
	cout << time.Geth() << ":" << time.Getmin() << "  ";
	cout << description << endl;
}