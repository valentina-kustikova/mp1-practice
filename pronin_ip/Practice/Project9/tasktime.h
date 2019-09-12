#pragma once
#include <iostream>
#include "task.h"
#include "time.h"
using namespace std;
class Tasktime : public Task
{
private:
	Time starttime;
	Time finishtime;
public:
	Tasktime();
	Tasktime(string, Date, Time, Time);
	Tasktime(const Tasktime&);
	~Tasktime();
	void print();
};
