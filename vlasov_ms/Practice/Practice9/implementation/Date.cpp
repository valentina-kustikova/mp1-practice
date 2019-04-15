#include "../headers/Date.h"

// code here...

unsigned TodoList::date::fix_day(unsigned d)
{
	if (d <= 28)
		return d;
	if ((this->m == 4U) || (this->m == 6U) || (this->m == 9U) || (this->m == 11U))
		d = d > 30U ? 30U : d;
	if (this->m == 2)
		if (bissextile())
			d = d > 29U ? 29U : d;
		else
			d = d > 28U ? 28U : d;
	d = d > 31U ? 31U : d;
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
	if ((d > 31U) || (m > 12U) || (y < 1970U))
	{
		d = 1U;
		m = 1U;
		y = 1970U;
		return;
	}
	this->y = y;
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

TodoList::date& TodoList::date::set_day(unsigned d)
{
	this->d = fix_day(d);
	return *this;
}

TodoList::date& TodoList::date::set_month(unsigned m)
{
	this->m = m > 12U ? 12U : m;
	this->d = fix_day(d);
	return *this;
}

TodoList::date& TodoList::date::set_year(unsigned y)
{
	this->y = y < 1970U ? 1970U : y;
	return *this;
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
	out << D.d;
	out.width(2);
	out << D.m;
	out.width(4);
	out << D.y;
	return out;
}

std::ofstream& TodoList::operator<<(std::ofstream& fout, const date& D)
{
	fout.width(2);
	fout << D.d;
	fout.width(2);
	fout << D.m;
	fout.width(4);
	fout << D.y;
	return fout;
}
