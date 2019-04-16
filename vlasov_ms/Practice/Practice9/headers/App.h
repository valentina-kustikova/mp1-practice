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

	namespace app_exception
	{
		class parsing : std::exception
		{
			const std::string what_str = "File can't be parsed because of syntax error.";
		public:
			std::string value;
			parsing();
			parsing(std::string);
			const char* what() const;
		};

		class file_open : std::exception
		{
			const std::string what_str = "File can't be opened (it may not exist).";
		public:
			std::string value;
			file_open();
			file_open(std::string);
			const char* what() const;
		};

		class file_write : std::exception
		{
			const std::string what_str = "File can't be overwritten (it may not exist).";
		public:
			std::string value;
			file_write();
			file_write(std::string);
			const char* what() const;
		};

		class bad_uid : std::exception
		{
			const std::string what_str = "UID not found in this list.";
			unsigned value;
		public:
			bad_uid();
			bad_uid(unsigned);
			const char* what() const;
		};
	}
}

#endif