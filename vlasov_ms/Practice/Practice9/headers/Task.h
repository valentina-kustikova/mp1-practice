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
		std::string title;
	public:
		date start;

		ctask();
		ctask(const ctask&);
		virtual ~ctask();

		ctask set_title(std::string);
		task::type get_type();

		virtual friend std::ostream& operator<<(std::ostream&, const ctask&) = 0;
		virtual friend std::ofstream& operator<<(std::ofstream&, const ctask&) = 0;
	};
}

#endif