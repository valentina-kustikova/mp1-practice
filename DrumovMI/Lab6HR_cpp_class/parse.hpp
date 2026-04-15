#ifndef __PARSE_HPP
#define __PARSE_HPP

#include <vector>
#include "hr_db.hpp"

Employees read_employees(const char* fn);

namespace parse {
    int line_count(const char* fn);
    std::vector<std::string> split(const std::string& str, char delim);
    std::chrono::year_month_day parse_date(const std::string& date_str);
}

#endif