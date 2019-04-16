#ifndef _TODOLIST_TASKSTD_H_
#define _TODOLIST_TASKSTD_H_
#include "Task.h"

namespace TodoList
{
	namespace task
	{
		class std : public ctask
		{
		public:
			time t_start;
			time t_end;
			std();
			std(const std&);
			std(::std::string&);
			std(::std::string&, date);
			std(::std::string&, date, time, time);
			~std();

			time get_start();
			time get_end();
			time set_start(time);
			time set_end(time);

			void print();
			void print(::std::ofstream&);
		};
	}
}

#endif