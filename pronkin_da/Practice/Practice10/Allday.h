#pragma once
#include "Task.h"
#include "Date.h"

class Allday : public Task {
public:
	Allday(string, Date&);
	void print();
};
