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
	banks_library();
	void read_lib(const std::string& fr);
	void cnt_banks(const std::string& fr);
	void make_list();
	bank& find(const std::string& str);
	~banks_library();
};
#endif 
