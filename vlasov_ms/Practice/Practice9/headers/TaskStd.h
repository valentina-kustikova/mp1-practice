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
			time duration;
			std();
			std(const std&);
			~std();

			unsigned get_duration();

			virtual void print();
			void print(::std::ofstream&);
			virtual const char* line();

			friend ::std::ostream& operator<<(::std::ostream&, const std&);
			friend ::std::ofstream& operator<<(::std::ofstream&, const std&);
		};
	}
}

#endif