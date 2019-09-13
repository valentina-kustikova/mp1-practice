#include "taskall.h"
Taskall::Taskall()
{
	discription = "empty";
	date = Date();
}
Taskall::Taskall(string _discription, Date _date)
{
	discription = _discription;
	date = _date;
}
Taskall::Taskall(const Taskall& a)
{
	discription = a.discription;
	date = a.date;
}
Taskall::~Taskall()
{
	discription = "0";
	date.~Date();
}
void Taskall::print()
{
	cout << date << discription << endl;
}