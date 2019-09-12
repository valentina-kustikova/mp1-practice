#pragma once

#include "Task.h"

class Type1 : public Task
{
public:
	Type1(Date, string);
	string getDescription();
	void Print();
};