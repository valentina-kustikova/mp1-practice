#pragma once
#include <iostream>
#include "TaskTypes.h"
#include"Date.h"
#include"Time.h"
#include <fstream>
using namespace std;

Tasks::Tasks()
{
	description = NULL;
	date = Date(0, 0, 0);
}
Tasks::~Tasks()
{
	delete[]description;	
}
Type1::Type1()
{
	description = NULL;
}
Type1::Type1(char* description, Date date)
{
	this->description = new char[sizeof(description)];
	memcpy(this->description, description, sizeof(description));
	this->date = date;
}
Type1::~Type1()
{
	delete[]description;
}
void Type1:: Print() const
{
	cout << "For all day: " << description << endl;
}
const Type1& Type1::operator=(const Type1& t)
{
	date = t.date;
	if (description != NULL) delete[] description;
	description = new char[50];
	memcpy(description, t.description, sizeof(t.description));
	return *this;
}
//const Tasks& Tasks::operator=(const Tasks& t)
//{
//	date = t.date;
//	description = new char[50];
//	memcpy(description, t.description, sizeof(t.description));
//	return *this;
//}
Type2 ::Type2()
{
	description = NULL;
	date = Date();
	duration = 0;
	time = Time();
}
Type2 ::Type2(char* des, Date date, unsigned duration, Time time)
{
	this->date = date;
	description = new char[50];
	for (int i = 0; i < 50; i++)
		description[i] = des[i];
	this ->duration = duration;
	this->time = time;

}
Type2 ::~Type2()
{
	delete[]description;
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
	description = t.description;  // !!!!!
	time = t.time;
	duration = t.duration;
	return *this;
}
