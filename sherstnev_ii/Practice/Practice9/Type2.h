#pragma once

#include "Task.h"
#include "Time.h"

class Type2 : public Task {
	Time Duration;
public:
	Type2(Date, string, Time);
	string getDescription();
	void Print();
};