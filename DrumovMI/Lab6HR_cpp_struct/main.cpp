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
	std::vector<Employee> employees = read_employees(argv[1]);
	std::vector<Employee> pension_employees;
	for (auto employee : employees) {
		if (employee.age_by_date(ymd) >= 60) {
			pension_employees.push_back(employee);
		}
	}
	std::cout << "Pension employees:\n"; 
	for (auto employee : pension_employees) {
		std::cout << employee << "\n";
	}
	return 0;
}