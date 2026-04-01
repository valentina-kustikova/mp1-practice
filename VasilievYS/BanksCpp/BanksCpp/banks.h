#ifndef __F
#define __F
#define MAX_LEN 512
#include <string>
//typedef struct
//{
//	char name[MAX_LEN];
//	float percentage;
//} deposit;
struct deposit{
	std::string name;
	float percentage;

	deposit();
};
//typedef struct
//{
//	char name[MAX_LEN];
//	char owner[MAX_LEN];
//	deposit* deposites;
//	int deposits_count;
//}bank;
struct bank{
	std::string name;
	std::string owner;
	deposit* deposites;
	int depostes_cnt;

	bank();
	void print();
};
//typedef struct
//{
//	bank* banks;
//	int cnt;
//} banks_library;
struct banks_library{
	bank* banks;
	int cnt;

	banks_library();
	void read_lib(const char* fr);
	void cnt_banks(const char* fr);
	void free_lib();
	bank& find(const std::string str )
};
int find(banks_library* library, char* udep);
#endif 
