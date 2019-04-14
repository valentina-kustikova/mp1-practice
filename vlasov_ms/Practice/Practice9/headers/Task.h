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
			std,
			day
		};
	}

	class ctask
	{
		unsigned uid;
		task::type type;
	public:
		std::string title;
		date start;

		ctask();
		ctask(const ctask&);
		virtual ~ctask();

		void set_title(std::string);

		unsigned get_uid();
		task::type get_type();
		virtual unsigned get_duration() = 0;

		virtual void print() = 0;
		virtual void print(std::ofstream&) = 0;
		virtual const char* line() = 0;
	};
}

#endif