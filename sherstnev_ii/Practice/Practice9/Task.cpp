#include "Task.h"


void Task::Print() {} // virtual

string Task::getDescription()
{
	return description;
}

Date Task::getDate()
{
	return date;
}
