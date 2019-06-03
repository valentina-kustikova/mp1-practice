#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include <string>
#include "Date.h"
#include "Task.h"

using namespace std;

class Todolist
{
	Task **task;
	int n;
public:
	Todolist();
	~Todolist();
	void read();
	void print(Date);
};

#endif