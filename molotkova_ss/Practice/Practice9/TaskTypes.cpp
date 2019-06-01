#pragma once
#include <iostream>
#include "TaskTypes.h"
#include"Date.h"
#include"Time.h"
#include <fstream>
#include <string>
using namespace std;

Tasks::Tasks()
{
	description = "";
	date = Date(0, 0, 0);
}
Tasks::~Tasks()
{
	description.clear();	
}
Type1::Type1()
{
	description = "";
}
Type1::Type1(string description, Date date)
{
	this->description = description;
	this->date = date;
}
Type1::~Type1()
{
	description.clear();
}
void Type1:: Print() const
{
	cout << "For all day: " << description << endl;
}
const Type1& Type1::operator=(const Type1& t)
{
	date = t.date;
	if (description != "") description.clear();
	description = t.description;
	return *this;
}

Type2 ::Type2()
{
	description = "";
	date = Date();
	duration = 0;
	time = Time();
}
Type2 ::Type2(string des, Date date, unsigned duration, Time time)
{
	this->date = date;
	this-> description  = des;
	for (int i = 0; i < 50; i++)
		description[i] = des[i];
	this ->duration = duration;
	this->time = time;

}
Type2 ::~Type2()
{
	description.clear();
	date.~Date();
	duration = 0;
	time.~Time();
}
void Type2 :: Print()const
{
	cout << "Not for all day: " << endl;
	time.PrintTime();
	cout <<description<<"For " << duration << "minutes";
}
const Type2& Type2 ::operator= (const Type2& t)
{
	date = t.date;
	description.clear();
	description = t.description; 
	time = t.time;
	duration = t.duration;
	return *this;
}