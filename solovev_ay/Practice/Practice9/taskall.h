#pragma once
#include "date.h"
#include <iostream>
#include <string>
#include "task.h"
class taskall : public task
{
public:
	taskall();
	~taskall();
	taskall(const taskall&tmp);
	date proverka();
	void settime(time);
	void settimeend(time);
	void fwrite(ofstream& file);
	void input();
	void print();
};