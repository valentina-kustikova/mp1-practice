#pragma once

#include "Task.h"
#include <fstream>
#include "Allday.h"
#include "Timeinterval.h"

using namespace std;

class ToDoList {
	Task** task;
	int n;
public:
	ToDoList();
	~ToDoList();
	void read(string);
	void write(Date);
};
