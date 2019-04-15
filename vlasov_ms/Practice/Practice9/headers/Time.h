#ifndef _TODOLIST_TIME_H_
#define _TODOLIST_TIME_H_
#include <iostream>
#include <fstream>

namespace TodoList
{
	class time
	{
		unsigned m;
	public:
		time();
		time(unsigned, unsigned);
		explicit time(unsigned);
		time(float);  // ;)
		
		time& set_hour(unsigned);
		time& set_min(unsigned);

		unsigned get_hour() const;
		unsigned get_min() const;
		unsigned get_mins() const;

		time& operator()(unsigned, unsigned);
		const unsigned operator[](char field) const;

		bool operator==(const time&) const;
		bool operator!=(const time&) const;
		bool operator>(const time&) const;
		bool operator>=(const time&) const;
		bool operator<(const time&) const;
		bool operator<=(const time&) const;

		const time& operator=(const time&);
		time operator+(const time&) const;
		time operator-(const time&) const;
		const time& operator+=(const time&);
		const time& operator-=(const time&);

		friend std::ostream& operator<<(std::ostream&, const time&);
		friend std::ofstream& operator<<(std::ofstream&, const time&);

		operator unsigned() const;
	};
}

#endif