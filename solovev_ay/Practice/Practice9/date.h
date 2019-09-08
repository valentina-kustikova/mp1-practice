#pragma once

class date
{
public:
	int day, month, year;
	bool operator==(const date&)const;
	date();
	date(const date&tmp);
	~date();
	date(int, int, int);
	friend ostream& operator<< (ostream& out, const date& a);
};
