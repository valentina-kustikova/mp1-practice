#include <iostream>
#include <fstream>
#include <vector>
#include "hr_db.hpp"
#include "parse.hpp"

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "Usage: " << argv[0] << " <filename> <date>\n";
		return 1;
	}
	vector<Employee> employees = read_employees(argv[1]);
}