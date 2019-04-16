#ifndef _TODOLIST_TASKDAY_H_
#define _TODOLIST_TASKDAY_H_
#include "Task.h"

namespace TodoList
{
	namespace task
	{
		class day : public ctask
		{
		public:
			day();
			day(::std::string&, date);
			day(const day&);
			~day();

			time get_start();
			time get_end();
			
			void print();
			void print(::std::ofstream&);
		};
	}
}

#endif