#pragma once
#include <iostream>
#include "Time.h"
#include <fstream>
using namespace std;
Time::Time()
{
	h = 0;
	m = 0;
}
Time::Time(unsigned h, unsigned m)
{
	this->h = h;
	this->m = m;
}
Time::Time(const Time& t)
{
	h = t.h;
	m = t.m;
}
Time ::~Time()
{
	h = 0;
	m = 0;
}
void Time::PrintTime()const
{
	cout << h << ":" << m;
}
bool Time :: operator== (const Time& t)const
{
	if ((h == t.h) && (m == t.m))
		return true;
	return false;
}
Time& Time ::operator = (const Time& t)
{
	if (*this == t)
		return *this;
	h = t.h;
	m = t.m;
	return *this;
}