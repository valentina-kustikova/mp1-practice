#pragma once
#include "Date.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

class Task {
protected:
	string task;
	Date date;
public:
	Task();
	Task(string, Date&);
	virtual void print() = 0;
	Date rdate();
};
