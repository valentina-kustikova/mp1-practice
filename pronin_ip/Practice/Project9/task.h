#pragma once
#include <iostream>
#include <string>
#include "date.h"
using namespace std;
class Task
{
public:
	std::string discription;
	Date date;
public:
	virtual ~Task();
	virtual void print() = 0;
};
