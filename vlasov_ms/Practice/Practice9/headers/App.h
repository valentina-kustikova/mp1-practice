#ifndef _TODOLIST_APP_H_
#define _TODOLIST_APP_H_
#include <iostream>
#include <fstream>
#include "Task.h"

namespace TodoList
{
	class app
	{
		ctask** tasks;
		std::ifstream fin;
		std::ofstream fout;
		static unsigned uid_stream;
	public:
		app();
		~app();

		ctask add();
		void remove(ctask*);
		void remove(unsigned);
		void print();
		void save();
		void save(const char*);
		void open(const char*);
	};
}

#endif