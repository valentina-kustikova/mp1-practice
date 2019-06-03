#ifndef _DATE_H_ 
#define _DATE_H_ 
#include <iostream> 

class Date
{
	unsigned int d, m, y;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);
	~Date();
	bool operator==(const Date& x) const;
	const Date& operator=(const Date&);
	friend std::ostream& operator<<(std::ostream &, const Date&);
	friend std::istream& operator>>(std::istream &, Date&);
};
class Date1 : std::exception
{
    const std::string what_str = "This date does not exist";
public:
    const char* what() const;
};

#endif
