#include <iostream>
#include "task.h"
#pragma once
using namespace std;
class Taskall : public Task
{
public:
	Taskall();
	Taskall(string, Date);
	Taskall(const Taskall&);
	~Taskall();
	void print();
};
