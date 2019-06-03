#include "Time.h" 
#include "Exception.h" 
#include <iostream> 
using namespace std;

Time::Time()
{
	h = 0;
	min = 0;
	
}

Time::Time(int _h, int _min)
{
	if ((_h < 0) || (_h > 24))
	{
		throw Exception("This hours does not exist");
	}
	if ((_min < 0) || (_min > 60))
	{
		throw Exception("This minutes does not exist");
	}
	
	h = _h;
	min = _min;

}

//Копирование 
Time::Time(const Time& x)
{
	h = x.h;
	min = x.min;
}

//Деструктор 
Time::~Time()
{
	h = 0;
	min = 0;
}


const Time& Time::operator=(const Time& x)
{
	if (&x == this)
		return *this;
	h = x.h;
	min = x.min;
	return *this;
}

void Time::Print()
{
	cout << "Your time: " << endl;
	cout << h << ":" << min << endl;
}

ostream & operator<<(ostream & o, const Time & x)
{
	o << x.h << x.min << " ";
	return o;
}

istream & operator>>(istream & o, Time & x)
{
	o >> x.h >> x.min;
	return o;
}