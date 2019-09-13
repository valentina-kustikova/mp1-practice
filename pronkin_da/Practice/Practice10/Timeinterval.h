#pragma once
#include "Task.h"

class Timeinterval : public Task {
	Time time;
public:
	Timeinterval(string, Date&, Time&);
	void print();
};
