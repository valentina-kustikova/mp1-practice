#pragma once

#include "task.h"
#include "date.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class task;

class timetable
{
private:
	task** todo;
public: 
    unsigned count;
    timetable();
    timetable(unsigned n);
    ~timetable();
	
    void print(date d) const;
    void read (const string s);
	void counttasks (const date& d) const;
	void getcalendar(int type, istream& f, int i);
};
