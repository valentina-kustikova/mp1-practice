#ifndef _TODOLIST_DATE_H_
#define _TODOLIST_DATE_H_
#include <iostream>
#include <fstream>

namespace TodoList
{
	class date
	{
		unsigned d, m, y;
		unsigned fix_day(unsigned);
	public:
		date();
		date(const date&);
		date(unsigned, unsigned, unsigned);
		~date();

		bool bissextile() const;
		date& set_day(unsigned);
		date& set_month(unsigned);
		date& set_year(unsigned);

		unsigned day() const;
		unsigned month() const;
		unsigned year() const;

		date& operator()(unsigned, unsigned, unsigned);
		unsigned operator[](char field) const;
		const date& operator=(const date&);

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