#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <chrono>
#include "hr_db.hpp"
#include "parse.hpp"

namespace parse {
    int line_count(const char* fn) {
        std::ifstream in(fn);
        if (!in.is_open())
            return 0;
        int nlines = 0;
        std::string line;
        while (std::getline(in, line))
            nlines++;
        return nlines;
    }

    std::vector<std::string> split(const std::string& str, char delim) {
        std::vector<std::string> tokens;
        std::istringstream iss(str);
        std::string token;
        while (std::getline(iss, token, delim)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Формат: %d/%m/%Y
    std::chrono::year_month_day parse_date(const std::string& date_str) {
        std::istringstream iss(date_str);
        std::chrono::year_month_day ymd;
        const std::string format = "%d/%m/%Y";
        if (!(iss >> std::chrono::parse(format, ymd))) {
            throw std::runtime_error("Invalid date format: " + date_str);
        }
        return ymd;
    }
}

Employees read_employees(const char* fn) {
    std::ifstream in(fn);
    if (!in.is_open()) {
        throw std::runtime_error(std::string("Error opening file: ") + fn);
    }

    int nlines = parse::line_count(fn);
    Employees employees(nlines);
    std::string line;
    for (int i = 0; i < nlines; i++) {
        std::getline(in, line);
        employees[i] = Employee(line);
    }
    return employees;
}