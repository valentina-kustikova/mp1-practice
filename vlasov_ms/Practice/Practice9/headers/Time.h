#ifndef _TODOLIST_TIME_H_
#define _TODOLIST_TIME_H_
#include <iostream>
#include <fstream>

namespace TodoList
{
	class time
	{
		unsigned h, m;
	public:
		time();
		time(unsigned, unsigned);

		time set_hour(unsigned);
		time set_min(unsigned);

		time operator()(unsigned, unsigned);
		unsigned& operator[](char field);
		time& operator=(time&);

		bool operator==(const time&) const;
		bool operator!=(const time&) const;
		bool operator>(const time&) const;
		bool operator>=(const time&) const;
		bool operator<(const time&) const;
		bool operator<=(const time&) const;

		friend std::ostream& operator<<(std::ostream&, const time&);
		friend std::ofstream& operator<<(std::ofstream&, const time&);
	};
}

#endif