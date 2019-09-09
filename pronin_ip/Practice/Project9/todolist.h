#pragma once
#include <iostream>
#include "task.h"
using namespace std;
class Todolist
{
private:
	int count;
	Task** tasks;
public:
	Todolist();
	Todolist(int);
	Todolist(int, Task**);
	Todolist(const Todolist&);
	~Todolist();
	void Read(const string namefile);
	void Print(Date);
};
