#include<iostream>
#include"banks.h"
#include"auxiliary.h"

int main(int argc, char** argv)
{
	std::string udep;
	banks_library lib(argv[1]);
	lib.show_data();
	if (argc < 2) { return 1; }
	lib.cnt_banks(argv[1]);
	lib.make_list();
	getline(std::cin, udep);
	to_low(udep);
	try
	{
		lib.read_lib(argv[1]);
		bank ans = lib.find(udep);
		std::cout << ans<<std::endl;
	}
	catch (const std::string ex)
	{
		std::cout << ex <<std::endl;
	}
	return 0;
}