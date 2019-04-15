#include "../headers/Time.h"

// code here...

TodoList::time::time()
{
	this->m = 0;
}

TodoList::time::time(unsigned h, unsigned m)
{
	this->m = 0;
	h = h > 23 ? 0 : h;
	m = m > 59 ? 0 : m;
	this->m = 60 * h + m;
}

TodoList::time::time(unsigned m)
{
	this->m = 0;
	this->m = m > 1440 ? 0 : m;
}

TodoList::time::time(float mask)
{
	this->m = 0;
	int imask = (int)(mask * 100);
	set_hour(imask / 100);
	set_min(imask % 100);
}

TodoList::time& TodoList::time::set_hour(unsigned h)
{
	if (h <= 23)
		this->m = h * 60 + get_min();
	return *this;
}

TodoList::time& TodoList::time::set_min(unsigned m)
{
	if (m <= 59)
		this->m = get_hour() * 60 + m;
	return *this;
}

unsigned TodoList::time::get_hour() const
{
	return m / 60U;
}

unsigned TodoList::time::get_min() const
{
	return m % 60U;
}

unsigned TodoList::time::get_mins() const
{
	return m;
}

TodoList::time& TodoList::time::operator()(unsigned h, unsigned m)
{
	set_hour(h);
	set_min(m);
	return *this;
}

bool TodoList::time::operator==(const time& t) const
{
	return this->m == t.m;
}

bool TodoList::time::operator!=(const time& t) const
{
	return !(*this == t);
}

bool TodoList::time::operator>(const time& t) const
{
	return this->m > t.m;
}

bool TodoList::time::operator>=(const time& t) const
{
	return (*this == t) || (*this > t);
}

bool TodoList::time::operator<(const time& t) const
{
	return this->m < t.m;
}

bool TodoList::time::operator<=(const time& t) const
{
	return (*this == t) || (*this < t);
}

const TodoList::time& TodoList::time::operator=(const time& t)
{
	this->m = t.m;
	return *this;
}

TodoList::time TodoList::time::operator+(const time& t) const
{
	time result(*this);
	unsigned tmp = this->m + t.m;
	result.m = tmp > 1440 ? tmp % 1440 : tmp;
	return result;
}

TodoList::time TodoList::time::operator-(const time& t) const
{
	time result(*this);
	unsigned tmp = this->m - t.m;
	result.m = tmp > 1440 ? 1440 - (UINT16_MAX - tmp) % 1440 : tmp;
	return result;
}

const TodoList::time& TodoList::time::operator+=(const time& t)
{
	*this = *this + t;
	return *this;
}

const TodoList::time& TodoList::time::operator-=(const time& t)
{
	*this = *this - t;
	return *this;
}

TodoList::time::operator unsigned() const
{
	return m;
}

std::ostream& TodoList::operator<<(std::ostream& out, const time& t)
{
	out << t.get_hour() << ':' << t.get_min();
	return out;
}

std::ofstream& TodoList::operator<<(std::ofstream& fout, const time& t)
{
	//fout << t.get_hour() << ':' << t.get_min();
	return fout;
}
