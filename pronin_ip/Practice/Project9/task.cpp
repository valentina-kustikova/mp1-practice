#include "task.h"
Task::~Task()
{
	discription = "0";
	date.~Date();
}