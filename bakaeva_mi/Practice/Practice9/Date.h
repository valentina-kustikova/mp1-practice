#ifndef _DATE_H_
#define _DATE_H_
#include "iostream"
using namespace std;

class Date
{
private:
    int y = 0, m = 0, d = 0;
public:
    Date();
    Date(int, int, int);
    ~Date();
    bool operator==(Date) const;
    const Date& operator=(Date&);

    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};

#endif 
