#pragma once
#include "date.h"
#include "time.h"
#include <string>
#include <string.h>
#include "date.h"
#include <iostream>
#include <string>
#include "task.h"
class tasktime : public task
{
public:
	time a;
	time aend;
	date proverka();
	void settime(time);
	void settimeend(time);
	void setend(time);
	void input();
	void print();
	void fwrite(ofstream& file);
	tasktime();
	~tasktime();
	tasktime(time team, time end, date gate);
};