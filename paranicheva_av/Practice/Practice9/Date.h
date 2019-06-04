#ifndef DATE_H
#define DATE_H

class Date
{
public:
    int d, m, y;

	Date();
	Date(int _d, int _m, int _y);
	~Date();

	void Print();
	const Date& operator=(const Date date);
	bool operator==(const Date& tmp) const;	
};

#endif
