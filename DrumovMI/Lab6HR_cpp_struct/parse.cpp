#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <chrono>
#include "hr_db.hpp"
#include "parse.hpp"

std::vector<Employee> read_employees(const char* fn) {
	std::ifstream in;
	in.open(fn);
	if (!in.is_open())
		throw std::runtime_error(std::string("Error reading file ") + fn + std::string(".\n"));
	std::vector<Employee> employees;
	std::string line;
	while (std::getline(in, line)) {
		const std::string format = "%d/%m/%Y";
		std::istringstream iss;
		std::stringstream ss(line);
		std::string word;
		Employee employee;
		std::getline(ss, word, ';'); employee.passport.series = std::stoi(word);
		std::getline(ss, word, ';'); employee.passport.number = std::stoi(word);
		std::getline(ss, word, ';'); employee.passport.issued_by = word;
		std::getline(ss, word, ';'); iss = std::istringstream(word); iss >> std::chrono::parse(format, employee.passport.issue_date);
		std::getline(ss, word, ';'); iss = std::istringstream(word); iss >> std::chrono::parse(format, employee.passport.birthday);
		std::getline(ss, word, ';'); employee.passport.place_of_residence = word;
		std::getline(ss, word, ';'); employee.education = word;
		std::getline(ss, word, ';'); employee.specialty = word;
		std::getline(ss, word, ';'); employee.department = word;
		std::getline(ss, word, ';'); employee.position = word;
		std::getline(ss, word, ';'); employee.salary = std::stoi(word);
		std::getline(ss, word, ';'); iss = std::istringstream(word); iss >> std::chrono::parse(format, employee.entry_date);
		std::getline(ss, word, '\n'); iss = std::istringstream(word); iss >> std::chrono::parse(format, employee.last_designation_date);
	}
}