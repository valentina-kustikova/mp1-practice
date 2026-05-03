#ifndef BANKS
#define BANKS
#include<string>
#include<iostream>
class deposit {
public:
	std::string name;
	float percentage;

	void set_name(const std::string&);
	void set_perc(const float&);
	const std::string& get_name() const;
	const float& get_perc() const;
};

class bank {
	std::string name;
	std::string owner;
	deposit* deposites;
	int depostes_cnt;
public:
	bank() : deposites(nullptr), depostes_cnt(0) {};
	bank(const bank& b);
	void alloc_deps();
	void set_dep_cnt(int);
	void set_name(const std::string&);
	void set_owner(const std::string&);
	void set_dep_name(const std::string&, int);
	void set_dep_perc(const float&, int);
	const int& get_deps_cnt() const;
	const std::string& get_name() const;
	const std::string& get_owner() const;
	const std::string& get_dep_name(int j) const;
	const float& get_dep_perc(int j) const;
	bank operator++(int);
	bank& operator-=(int);
	friend std::ostream& operator<<(std::ostream& os, const bank& b);
	~bank();
};

class banks_library {
	bank* banks;
	int cnt;
public:
	banks_library(const std::string& fr);
	const bank& find(const std::string& str) const;
	void set_banks_cnt(const int&);
	friend std::ostream& operator<<(std::ostream& os, const banks_library& lib);
	~banks_library();
};
#endif 