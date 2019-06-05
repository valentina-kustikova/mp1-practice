#pragma once

class date
{
public:
	int day, month, year;
	void input();
	int getday();
	int getmonth();
	int getyear();
	void setday(int a);
	void setmonth(int a);
	void setyear(int a);
	bool operator==(const date&);
	date();
	date(const date&tmp);
	~date();
	date(int, int, int);
	friend ostream& operator<< (ostream& out, const date& a);
};
