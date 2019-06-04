#pragma once
class Date
{
private:
	int d, m, y;
public:
	Date();
	Date(int _d, int _m, int _y);
	Date(const Date& dat);
	~Date();
	void Print() const;
	bool operator==(const Date dat) const;
	Date& operator=(const Date& temp);
};