#include<cstdio>
#include<cstdlib>
#include<iostream>
#include"banks.h"
#include"auxiliary.h"
#include<cstring>

int main(int argc, char** argv)
{
	std::string udep;
	banks_library lib;
	if (argc < 2) { return 1; }
	lib.cnt_banks(argv[1]);
	lib.make_list();
	getline(std::cin, udep);
	to_low(udep);
	std::cout << udep << std::endl;
	try
	{
		lib.read_lib(argv[1]);
		bank ans = lib.find(udep);
		std::cout << ans;
	}
	catch (...)
	{
		std::cout << 121 << std::endl;
		std::cout << std::exception().what()<<222<<std::endl;
	}
	return 0;
}