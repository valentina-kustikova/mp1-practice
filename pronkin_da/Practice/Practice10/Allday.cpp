#include "Allday.h"

Allday::Allday(string _str, Date &_date) : Task(_str, _date) {}

void Allday::print() {
	cout << task << " ";
	date.out();
}

