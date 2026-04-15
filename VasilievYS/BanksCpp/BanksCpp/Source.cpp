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
	try
	{

	}//todo: try/catch, operator > (deps cmpr)

	return 0;
}