#include "Task.h" 
#include "Date.h" 
#include <iostream> 
using namespace std;

Task::Task()
{
}

Task::Task(string _des, Date _date)
{
	description = _des;
	date = _date;
}

Task::~Task()
{
	description = nullptr;
}

Date Task::GetDate()
{
	return date;
}


