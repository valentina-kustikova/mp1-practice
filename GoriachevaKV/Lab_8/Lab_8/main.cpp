#include <iostream>
#include <string>
#include "department.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Input error: missing filename." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    OwnerLib db_lib(filename);

    std::string requested_department;
    std::cout << "Input the department >> ";
    std::getline(std::cin, requested_department);

    OwnerLib found_lib = db_lib.filterByDepartment(requested_department);

    if (found_lib.count == 0)
        std::cout << "There is no owners in " << requested_department << ".\n" << std::endl;
    else
        std::cout << "There is " << found_lib.count << " owners in " << requested_department << ".\n" << std::endl;

    std::cout << found_lib;

    return 0;
}