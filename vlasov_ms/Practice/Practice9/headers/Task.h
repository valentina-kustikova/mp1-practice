#ifndef _TODOLIST_TASK_H_
#define _TODOLIST_TASK_H_
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Time.h"

namespace TodoList
{
	namespace task
	{
		enum type
		{
			t_std,
			t_day
		};
	}

	class ctask
	{
	protected:
		static unsigned uid_stream;
		unsigned uid;
		task::type type;
	public:
		std::string title;
		date start;

		ctask();
		ctask(const ctask&);
		ctask(std::string&);
		ctask(std::string&, date);
		virtual ~ctask();

		unsigned get_uid();
		task::type get_type();
		virtual time get_start() = 0;
		virtual time get_end() = 0;

		// Do not call this methods with task::day* pointer - they will not work correctly
		virtual time set_start(time);
		virtual time set_end(time);

		virtual void print() = 0;
		virtual void print(std::ofstream&) = 0;

		virtual bool operator>(const ctask&) const;
		virtual bool operator<(const ctask&) const;
		//virtual bool operator>=(const ctask&) const;
		//virtual bool operator<=(const ctask&) const;
	};
}

#endif