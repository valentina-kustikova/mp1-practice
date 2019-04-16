#ifndef _TODOLIST_TIME_H_
#define _TODOLIST_TIME_H_
#include <iostream>
#include <fstream>

namespace TodoList
{
	class time
	{
		unsigned m;
	public:
		time();
		time(unsigned, unsigned);
		explicit time(unsigned);
		time(float);  // ;)
		
		time& set_hour(unsigned);
		time& set_min(unsigned);

		unsigned get_hour() const;
		unsigned get_min() const;
		unsigned get_mins() const;

		time& operator()(unsigned, unsigned);
		const unsigned operator[](char field) const;

		bool operator==(const time&) const;
		bool operator!=(const time&) const;
		bool operator>(const time&) const;
		bool operator>=(const time&) const;
		bool operator<(const time&) const;
		bool operator<=(const time&) const;

		const time& operator=(const time&);
		time operator+(const time&) const;
		time operator-(const time&) const;
		const time& operator+=(const time&);
		const time& operator-=(const time&);

		friend std::ostream& operator<<(std::ostream&, const time&);

		//operator unsigned() const;
	};

	namespace time_exception
	{
		class bad_hour : std::exception
		{
			const std::string what_str = "Incorrect hours.";
			unsigned value;
		public:
			bad_hour();
			bad_hour(unsigned);
			const char* what() const;
		};

		class bad_min : std::exception
		{
			const std::string what_str = "Incorrect minutes.";
			unsigned value;
		public:
			bad_min();
			bad_min(unsigned);
			const char* what() const;
		};

		class bad_mins : std::exception
		{
			const std::string what_str = "Incorrect timestamp.";
			unsigned value;
		public:
			bad_mins();
			bad_mins(unsigned);
			const char* what() const;
		};

		class bad_mask : std::exception
		{
			const std::string what_str = "Incorrect float-mask.";
			float value;
		public:
			bad_mask();
			bad_mask(float);
			const char* what() const;
		};
	}
}

#endif