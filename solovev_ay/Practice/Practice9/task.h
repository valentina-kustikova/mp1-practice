#pragma once
#include "date.h"
#include "time.h"
#include <iostream>
#include <fstream>
using namespace std;

class task
{
public:
	date Date;
	std::string descrip;
	task();
	virtual ~task();
	virtual date proverka() = 0;
	virtual void input() = 0;
	virtual void print() = 0;
	virtual void fwrite(ofstream& file) = 0;
	virtual void settime(time) = 0;
	virtual void settimeend(time) = 0;
};