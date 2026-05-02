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

	banks_library(const std::string& fr);
	const bank& find(const std::string& str) const;
	friend std::ostream& operator<<(std::ostream& os, const banks_library& lib);
	~banks_library();
};
#endif 
