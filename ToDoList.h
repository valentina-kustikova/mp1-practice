#pragma once
#include "TaskTypes.h"
class ToDoList
{
private:
	Tasks** tasks;
	int amount_of_tasks;
public:
	ToDoList();
	ToDoList(int amount_of_tasks);
	~ToDoList();
	void Read(const char* a);
	void Print(Date date) const;
};
