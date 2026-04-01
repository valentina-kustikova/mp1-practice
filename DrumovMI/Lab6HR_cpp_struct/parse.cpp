#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <chrono>
#include "hr_db.hpp"
#include "parse.hpp"

std::vector<std::string> split(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Формат даты: %d/%m/%Y
std::chrono::year_month_day parse_date(const std::string& date_str) {
    std::istringstream iss(date_str);
    std::chrono::year_month_day ymd;
    const std::string format = "%d/%m/%Y";
    if (!(iss >> std::chrono::parse(format, ymd))) {
        throw std::runtime_error("Invalid date format: " + date_str);
    }
    return ymd;
}

std::vector<Employee> read_employees(const char* fn) {
    std::ifstream in(fn);
    if (!in.is_open()) {
        throw std::runtime_error(std::string("Error opening file: ") + fn);
    }

    std::vector<Employee> employees;
    std::string line;
    while (std::getline(in, line)) {
        std::vector<std::string> fields = split(line, ';');

        Employee emp;
        emp.passport.series = std::stoi(fields[0]);
        emp.passport.number = std::stoi(fields[1]);
        emp.passport.issued_by = fields[2];
        emp.passport.issue_date = parse_date(fields[3]);
        emp.passport.birthday = parse_date(fields[4]);
        emp.passport.place_of_residence = fields[5];

        emp.education = fields[6];
        emp.specialty = fields[7];
        emp.department = fields[8];
        emp.position = fields[9];
        emp.salary = std::stoi(fields[10]);

        emp.entry_date = parse_date(fields[11]);
        emp.last_designation_date = parse_date(fields[12]);

        employees.push_back(emp);
    }
    return employees;
}