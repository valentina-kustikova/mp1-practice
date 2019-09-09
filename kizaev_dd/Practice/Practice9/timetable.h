#pragma once
#include "task.h"

class timetable
{
private:
    task** todo;
    unsigned count;
public: 
    timetable();
    timetable(unsigned n);
    ~timetable();

    void print(date d) const;
    void read (const string s);
};
