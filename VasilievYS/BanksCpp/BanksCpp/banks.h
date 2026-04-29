#ifndef __F
#define __F
#include <string>

struct deposit{
	std::string name;
	float percentage;
};

struct bank{
	std::string name;
	std::string owner;
	deposit* deposites;
	int depostes_cnt;
	
	friend std::ostream& operator<<(std::ostream& os, const bank& b);
};

struct banks_library{
	bank* banks;
	int cnt;

	void cnt_banks(const std::string& fr);

	banks_library(); // banks_library(const std::string& fr)
	banks_library(const std::string& fr);
	void read_lib(const std::string& fr); // remove
	void make_list(); // remove
	bank find(const std::string& str) const;
	void show_data(); //operator<<
	~banks_library();
};
#endif 
