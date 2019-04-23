#pragma once
class Date
{
private:
	int day;
	int month;
	int year;

public:
	void PrintDate()const;
	Date();
	Date(int day, int month, int year);
	Date(const Date& t);
	~Date();
	bool operator == (const Date &date1)const;
	const Date& operator = (const Date& t);
};
