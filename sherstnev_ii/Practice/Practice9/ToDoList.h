#pragma once
#include "Task.h"

class ToDoList {
	unsigned int count;
	Task** tasks;
public:
	ToDoList(int);
	void Print(int);
	void Print(Date);
	void Read(string&, int);
	int GetCount();
};