#ifndef _TODOLIST_DATE_H_
#define _TODOLIST_DATE_H_
#include <iostream>
#include <fstream>

namespace TodoList
{
	class date
	{
		unsigned d, m, y;
	public:
		date();
		date(const date&);
		date(unsigned, unsigned, unsigned);    // day, month, year
		date(unsigned, unsigned);              // year, days
		~date();

		bool bissextile();
		date set_day(unsigned);
		date set_month(unsigned);
		date set_year(unsigned);

		unsigned day();
		unsigned month();
		unsigned year();

		unsigned get_days();
		unsigned get_days(unsigned* y);

		date operator()(unsigned, unsigned, unsigned);
		unsigned operator[](char field);
		date& operator=(date&);

		bool operator==(const date&) const;
		bool operator!=(const date&) const;
		bool operator>(const date&) const;
		bool operator>=(const date&) const;
		bool operator<(const date&) const;
		bool operator<=(const date&) const;

		friend std::ostream& operator<<(std::ostream&, const date&);
		friend std::ofstream& operator<<(std::ofstream&, const date&);
	};
}

#endif