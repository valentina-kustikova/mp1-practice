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
	};

	namespace date_exception
	{
		class bad_day : std::exception
		{
			const std::string what_str = "Incorrect day.";
			unsigned value;
		public:
			bad_day();
			bad_day(unsigned);
			const char* what() const;
		};

		class bad_month : std::exception
		{
			const std::string what_str = "Incorrect month.";
			unsigned value;
		public:
			bad_month();
			bad_month(unsigned);
			const char* what() const;
		};

		class bad_year : std::exception
		{
			const std::string what_str = "Incorrect year.";
			unsigned value;
		public:
			bad_year();
			bad_year(unsigned);
			const char* what() const;
		};
	}
}

#endif