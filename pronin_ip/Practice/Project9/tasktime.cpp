#include "tasktime.h"
Tasktime::Tasktime()
{
	discription = "empty";
	date = Date();
	starttime = Time();
	finishtime = Time();
}
Tasktime::Tasktime(string _discription, Date _date, Time _starttime, Time _finishtime)
{
	discription = _discription;
	date = _date;
	starttime = _starttime;
	finishtime = _finishtime;
}
Tasktime::Tasktime(const Tasktime& a)
{
	discription = a.discription;
	date = a.date;
	starttime = a.starttime;
	finishtime = a.finishtime;
}
Tasktime::~Tasktime()
{
	discription = "0";
	date.~Date();
	starttime.~Time();
	finishtime.~Time();
}
void Tasktime::print()
{
	cout << date << " " << starttime << "-" << finishtime << discription << endl;
}
