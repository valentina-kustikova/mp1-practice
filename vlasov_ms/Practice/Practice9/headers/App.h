#ifndef _TODOLIST_APP_H_
#define _TODOLIST_APP_H_
#include <iostream>
#include <fstream>
#include <list>
#include "TaskDay.h"
#include "TaskStd.h"

namespace TodoList
{
	class app
	{
		std::list<ctask*> tasks;
		size_t tcount;
		std::string filename;
	public:
		app();
		~app();

		bool add(std::string&, task::type, date);
		bool add(std::string&, date, time, time);
		bool add(std::string&, date);
		bool remove(ctask*);
		bool remove(unsigned);

		void print();
		void print(date);
		void print(unsigned);

		bool open(std::string&);
		bool create(std::string&);
		bool save();

		void start();
		void reset();
	};
}

#endif