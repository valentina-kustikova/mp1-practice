#include "date.h"

date::date()
{
    year = 0;
    month = 0;
    day = 0;
}

date::date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

date::date(const date& d) // РКС;
{
    year = d.year;
    month = d.month;
    day = d.day;
}

date::~date()
{
    year = 0;
    month = 0;
    day = 0;
}

bool date::operator== (const date& d) const // КМ; РКС;
{
    if ((year != d.year) || (month != d.month) || (day != d.day))
        return false;
    return true;
}

void date::print() const // КМ;
{
    cout << day << "." << month << "." << year << endl;
}

const date& date::operator= (const date& d) // ВКС; РКС;
{
    if (*this == d)
        return *this;
    year = d.year;
    month = d.month;
    day = d.day;
    return *this;
}

// const в начале - метод возвращает константную ссылку на <???> | ВКС
// const в конце - const метод  - не изменяет данные объекта класса; | КМ
// (const <класс>& tmp) - метод работает с const ссылкой - не изменяет аргумент tmp | РКС