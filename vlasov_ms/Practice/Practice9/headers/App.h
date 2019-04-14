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
		size_t tcount;
		std::ifstream fin;
		std::ofstream fout;
		char* filename;
		static unsigned uid_stream;
	public:
		app();
		~app();

		bool add(const char*, const task::type, const date);
		bool add(const char*, const date, const time);
		bool add(const char*, const date);
		bool remove(ctask*);
		bool remove(unsigned);

		void print();
		void print(const date);
		void print(unsigned);

		bool open(const char*);
		bool create(const char*);
		bool save();

		void start();
		void reset();
	};
}

#endif