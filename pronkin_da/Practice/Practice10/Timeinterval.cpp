#include "Timeinterval.h"

Timeinterval::Timeinterval(string _task, Date &_date, Time &_time) : Task(_task, _date) {
	time = _time;
}

void Timeinterval::print() {
	cout << task << " ";
	date.out();
	time.out();
}