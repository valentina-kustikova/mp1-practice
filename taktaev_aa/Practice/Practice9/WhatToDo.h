#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Time
{
	unsigned hour;
	unsigned min;
public:
	Time();
	Time(unsigned, unsigned);
	Time(const Time&);
	const Time& operator=(const Time&);
	friend std::ostream& operator<<(std::ostream&, const Time&);
};

///////////////////////////////////////

class Date
{
	unsigned day;
	unsigned mon;
	unsigned year;
public:
	Date();
	Date(unsigned, unsigned, unsigned);
	Date(const Date&);
	const Date& operator=(const Date&);
	bool operator==(const Date&);
	friend std::ostream& operator<<(std::ostream&, const Date&);
};

///////////////////////////////////////

class Task
{
public:
	Date date;
	std::string task;
	unsigned id;
	Task();
	virtual ~Task();
	virtual void set_start(Time) {};
	virtual void set_end(Time) {};
	virtual void print() = 0;
};

///////////////////////////////////////

class Type1 : public Task
{
public:
	Type1();
	~Type1();
	void print();
};

///////////////////////////////////////

class Type2 : public Task
{
private:
	Time time_1, time_2;
public:
	Type2();
	~Type2();
	void set_start(Time);
	void set_end(Time);
	void print();
};

///////////////////////////////////////

class ToDoList
{
	Task** tasks;
public:
	unsigned number;
	void read_tasks();
	void print_tasks();
	void print_tasks_by_date();
};