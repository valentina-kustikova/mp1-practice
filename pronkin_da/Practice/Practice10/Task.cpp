#include "Task.h"

Task::Task(string _task, Date &_date) {
	task = _task;
	date = _date;
}

Task::Task() {
	task = new char[1];
}

Date Task::rdate() {
	return date;
}