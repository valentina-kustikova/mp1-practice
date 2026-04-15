#include <iostream>
#include <chrono>
#include <vector>
#include "hr_db.hpp"

int Employee::age_by_date(std::chrono::year_month_day date) const {
	auto birth_sys = std::chrono::sys_days(passport.birthday);
	auto date_sys = std::chrono::sys_days(date);
	auto year_diff = date.year() - passport.birthday.year();
	int age = static_cast<int>(year_diff.count());
	if (date_sys < birth_sys + std::chrono::years(age))
		age--;
	return age;
}

std::ostream& operator<<(std::ostream& out, Employee employee) {
	out << "Passport: " << employee.passport.series << " " << employee.passport.number
		<< " issued by " << employee.passport.issued_by << " on "
		<< employee.passport.issue_date << ". Born on " << employee.passport.birthday
		<< ". Official residence: " << employee.passport.place_of_residence << "\n";
	out << "Education: " << employee.education << ". Specialty: " << employee.specialty
		<< ".\nDepartment: " << employee.department << ".Position: " << employee.position
		<< ".Salary: " << employee.salary << ".\n";
	out << "Entry date: " << employee.entry_date << ". Last designation: " << employee.last_designation_date;
	return out;
}