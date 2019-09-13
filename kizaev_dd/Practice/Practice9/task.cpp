#include "task.h"
#include "timetable.h"

task::task()
{
    note = date();
    info = "";
}

task::~task()
{
    info.clear();
}

date task::GetNote()const
{
    return note;
}

void task::changeinfo(string s)
{
	info = s;
}

task1::task1()
{
    note = date();
    info = "";
}

task1::task1(string s, date d)
{
    note = d;
    info = s;
}

task1::~task1()
{
    info.clear();
}

date task1::GetNote() const
{
    return note;
}

void task1::print() const
{
    cout << "full day task: " << info << endl;
}

const task1& task1::operator= (const task1& t)
{
    note = t.note;
    info = t.info;
    return *this;
}

task2::task2()
{
    note = date();
    info = "";
    clock = time();
    duration = 0;
}

task2::task2(string s, date d, time t, unsigned dur)
{
    note = d; 
    info = s;
    clock = t;
    duration = dur;
}

task2::~task2()
{
    info.clear();
    duration = 0;
}

date task2::GetNote() const
{
    return note;
}

void task2::print() const
{
    cout << "Task: ";
    clock.print();
    cout << info << " duration: " << duration << " min" << endl;
}

const task2& task2::operator= (const task2& t)
{
    note = t.note;
    info = t.info;
    clock = t.clock;
    duration = t.duration;
    return *this;
}