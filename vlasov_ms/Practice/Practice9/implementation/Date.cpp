#include "../headers/Date.h"

// code here...

unsigned TodoList::date::fix_day(unsigned d)
{
	if ((d > 31U) || (d < 1U))
	{
		throw date_exception::bad_day(d);
		return this->d;
	}
	if (d <= 28)
		return d;
	if ((this->m == 4U) || (this->m == 6U) || (this->m == 9U) || (this->m == 11U))
		if (d > 30U)
		{
			throw date_exception::bad_day(d);
			return this->d;
		}
	if (this->m == 2)
		if (bissextile())
			if (d > 29U)
			{
				throw date_exception::bad_day(d);
				return this->d;
			}
		else
			if (d > 28U)
			{
			throw date_exception::bad_day(d);
			return this->d;
			}
	return d;
}

TodoList::date::date()
{
	d = 1U;
	m = 1U;
	y = 1970U;
}

TodoList::date::date(const date& d)
{
	this->d = d.d;
	this->m = d.m;
	this->y = d.y;
}

TodoList::date::date(unsigned d, unsigned m, unsigned y)
{
	d = 1U;
	m = 1U;
	y = 1970U;
	if ((d > 31U) || (d < 1U))
	{
		throw date_exception::bad_day(d);
		return;
	}
	this->y = y;
	if (m > 12U || (m < 1U))
	{
		throw date_exception::bad_month(m);
		return;
	}
	this->m = m;
	this->d = fix_day(d);
}

TodoList::date::~date()
{
	
}

bool TodoList::date::bissextile() const
{
	return !(y % 400U) || ((y % 100U) && !(y % 4U));
}

unsigned TodoList::date::day() const
{
	return d;
}

unsigned TodoList::date::month() const
{
	return m;
}

unsigned TodoList::date::year() const
{
	return y;
}

TodoList::date& TodoList::date::operator()(unsigned d, unsigned m, unsigned y)
{
	this->y = y;
	this->m = m;
	this->d = d;
	return *this;
}

unsigned TodoList::date::operator[](char field) const
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

const TodoList::date& TodoList::date::operator=(const date& D)
{
	this->d = D.d;
	this->m = D.m;
	this->y = D.y;
	return *this;
}

bool TodoList::date::operator==(const date& D) const
{
	return (this->d == D.d) && (this->m == D.m) && (this->y == D.y);
}

bool TodoList::date::operator!=(const date& D) const
{
	return !(*this == D);
}

bool TodoList::date::operator>(const date& D) const
{
	if (*this == D)
		return false;
	if (this->y != D.y)
		return this->y > D.y;
	if (this->m != D.m)
		return this->m > D.m;
	if (this->d != D.d)
		return this->d > D.d;
	return false;
}

bool TodoList::date::operator>=(const date& D) const
{
	return (*this == D) || (*this > D);
}

bool TodoList::date::operator<(const date& D) const
{
	if (*this == D)
		return false;
	if (this->y != D.y)
		return this->y < D.y;
	if (this->m != D.m)
		return this->m < D.m;
	if (this->d != D.d)
		return this->d < D.d;
	return false;
}

bool TodoList::date::operator<=(const date& D) const
{
	return (*this == D) || (*this < D);
}

std::ostream& TodoList::operator<<(std::ostream& out, const date& D)
{
	out.width(2);
	out.fill('0');
	out << D.d;
	out.width(2);
	out.fill('0');
	out << D.m;
	out.width(4);
	out.fill('0');
	out << D.y;
	return out;
}

TodoList::date_exception::bad_day::bad_day()
{
	this->value = 0U;
}

TodoList::date_exception::bad_day::bad_day(unsigned value)
{
	this->value = value;
}

const char* TodoList::date_exception::bad_day::what() const
{
	return what_str.c_str();
}

TodoList::date_exception::bad_month::bad_month()
{
	this->value = 0U;
}

TodoList::date_exception::bad_month::bad_month(unsigned value)
{
	this->value = value;
}

const char* TodoList::date_exception::bad_month::what() const
{
	return what_str.c_str();
}

TodoList::date_exception::bad_year::bad_year()
{
	this->value = 0U;
}

TodoList::date_exception::bad_year::bad_year(unsigned value)
{
	this->value = value;
}

const char* TodoList::date_exception::bad_year::what() const
{
	return what_str.c_str();
}
