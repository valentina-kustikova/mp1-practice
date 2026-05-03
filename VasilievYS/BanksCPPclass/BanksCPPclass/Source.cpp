#include<iostream>
#include"banks.h"
#include"auxiliary.h"
int main(int argc, char** argv)
{
	if (argc < 2) { return 1; }
	try
	{
		std::string udep;
		banks_library lib(argv[1]);
		std::cout << lib;
		getline(std::cin, udep);
		to_low(udep);
		const bank& ans = lib.find(udep);
		std::cout << ans << std::endl;
	}
	catch (const std::string ex)
	{
		std::cout << ex << std::endl;
	}
	return 0;
}