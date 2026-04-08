#include <iostream>
#include <chrono>
#include <vector>
#include "hr_db.hpp"
#include "parse.hpp"

Employee::Employee(const std::string& s) {
	std::vector<std::string> fields = parse::split(s, ';');
	try {
		passport.series = std::stoi(fields[0]);
		passport.number = std::stoi(fields[1]);
		passport.issued_by = fields[2];
		passport.issue_date = parse::parse_date(fields[3]);
		passport.birthday = parse::parse_date(fields[4]);
		passport.place_of_residence = fields[5];

		education = fields[6];
		specialty = fields[7];
		department = fields[8];
		position = fields[9];
		salary = std::stoi(fields[10]);

		entry_date = parse::parse_date(fields[11]);
		last_designation_date = parse::parse_date(fields[12]);
	}
	catch (const std::exception& e) {
		throw e;
	}
}

int Employee::age_by_date(std::chrono::year_month_day date) const {
	auto birth_sys = std::chrono::sys_days(passport.birthday);
	auto date_sys = std::chrono::sys_days(date);
	auto year_diff = date.year() - passport.birthday.year();
	int age = static_cast<int>(year_diff.count());
	if (date_sys < birth_sys + std::chrono::years(age))
		age--;
	return age;
}

Employees::Employees(const Employees& empl): n(empl.n), employees(new Employee[n]) {
	for (int i = 0; i < n; i++)
		employees[i] = empl.employees[i];
}

Employees::Employees(Employees&& empl) {
	n = empl.n;
	employees = nullptr;
	std::swap(employees, empl.employees);
}

Employee& Employees::operator[](size_t ind) {
	if (ind >= n)
		throw std::out_of_range("Out of range");
	return employees[ind];
}

Employees Employees::pension_employees(std::chrono::year_month_day date) const {
	std::vector<int> ind;
	for (int i = 0; i < n; i++)
		if (employees[i].age_by_date(date) > 55)
			ind.push_back(i);
	Employees pension(ind.size());
	for (int i = 0; i < ind.size(); i++)
		pension.employees[i] = employees[ind[i]];
	return pension;
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

std::ostream& operator<<(std::ostream& out, Employees& empl) {
	for (int i = 0; i < empl.n; i++)
		out << empl.employees[i] << "\n";
	return out;
}