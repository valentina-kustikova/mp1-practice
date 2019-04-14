#include "../headers/Date.h"

// code here...

TodoList::date::date()
{
	d = m = y = 0U;
}

TodoList::date::date(const date& d)
{
	this->d = d.d;
	this->m = d.m;
	this->y = d.y;
}

TodoList::date::date(unsigned d, unsigned m, unsigned y)
{
	if ((d < 0) || (d > 31) || (m < 0) || (m > 12) || (y < 1970))
	{
		d = m = y = 0U;
		return;
	}
	// todo...
}

TodoList::date::~date()
{
	d = m = y = 0U;
}

unsigned TodoList::date::day()
{
	return d;
}

unsigned TodoList::date::month()
{
	return m;
}

unsigned TodoList::date::year()
{
	return y;
}

unsigned TodoList::date::operator[](char field)
{
	switch (field)
	{
	case 'd':
	case 'D':
	case 'j':
		return d;
	case 'm':
	case 'n':
	case 'M':
		return m;
	case 'y':
	case 'Y':
		return y;
	default:
		return 0U;
	}
}
