#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include "hr_db.hpp"
#include "parse.hpp"

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " <filename> <date>\n";
		return 1;
	}

	auto now = std::chrono::system_clock::now();
	auto today = std::chrono::floor<std::chrono::days>(now);
	std::chrono::year_month_day ymd{ today };
	try {
		Employees employees{ read_employees(argv[1]) };
		Employees pension = employees.pension_employees(ymd);
		std::cout << "Pension employees:\n";
		std::cout << pension;
	}
	catch (const std::exception& e) {
		std::cerr << e.what();
	}
	return 0;
}