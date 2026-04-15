#ifndef __HR_DB_HPP
#define __HR_DB_HPP

#include <vector>
#include <string>
#include <chrono>

struct Employee {
	struct Passport {
		int series, number;
		std::string issued_by;
		std::chrono::year_month_day issue_date;
		std::chrono::year_month_day birthday;
		std::string place_of_residence;
	} passport;
	std::string education;
	std::string specialty;
	std::string department;
	std::string position;
	int salary;
	std::chrono::year_month_day entry_date;
	std::chrono::year_month_day last_designation_date;

	int age_by_date(std::chrono::year_month_day date) const;

	friend std::ostream& operator<<(std::ostream& out, Employee employee);
};

std::vector<int> search_pension(std::vector<Employee> employees, std::chrono::year_month_day date);

#endif