#ifndef BANKS
#define BANKS
#include<string>
#include<iostream>
class deposit {
	std::string name;
	float percentage;
public:
	deposit(const std::string& _n, const float _p) :
		name(_n), percentage(_p) {};
	deposit() :percentage(0) {};
	const std::string get_name() const;
	const float get_perc() const;
	const deposit& operator = (const deposit&);
};

class bank {
	std::string name;
	std::string owner;
	deposit* deposites;
	int depostes_cnt;
public:
	bank() : deposites(nullptr), depostes_cnt(0) {};
	bank(const std::string& _n, const std::string& _o,
		deposit* _d, const int d_cnt);
	bank(const bank& b);
	const int get_deps_cnt() const;
	const std::string get_name() const;
	const std::string get_owner() const;
	const bank& operator=(const bank& b);
	deposit& operator[](int j);
	friend std::ostream& operator<<(std::ostream& os, const bank& b);
	~bank();
};

class banks_library {
	bank* banks;
	int cnt;
public:
	banks_library(const std::string& fr);
	const bank find(const std::string& str) const;
	friend std::ostream& operator<<(std::ostream& os, const banks_library& lib);
	~banks_library();
};
#endif 