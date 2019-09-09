#pragma once
#include "date.h"
#include "time.h"
#include <string>
using namespace std;

class task
{
protected:
    string info;
    date note;
public:
    task();
    virtual ~task();
    
	virtual date GetNote()const;
	virtual void print()const = 0;
};

class task1 : public task
{
public:
    task1();
    task1(string s, date d);
    ~task1();
    date GetNote()const;

    void print()const;
    const task1& operator= (const task1& t);
};

class task2 : public task
{
private:
    time clock;
    unsigned duration;
public:
    task2();
    task2(string s, date d, time t, unsigned dur);
    ~task2();
    date GetNote()const;

    void print()const;
    const task2& operator= (const task2& t);
};
