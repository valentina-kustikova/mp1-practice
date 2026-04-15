#ifndef __PARSE_HPP
#define __PARSE_HPP

#include <vector>
#include "hr_db.hpp"

std::vector<Employee> read_employees(const char* fn);

namespace {
    std::vector<std::string> split(const std::string& str, char delim);
    std::chrono::year_month_day parse_date(const std::string& date_str);
}

#endif