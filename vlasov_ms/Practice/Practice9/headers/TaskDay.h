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
			day(const day&);
			~day();

			friend ::std::ostream& operator<<(::std::ostream&, const day&);
			friend ::std::ofstream& operator<<(::std::ofstream&, const day&);
		};
	}
}

#endif