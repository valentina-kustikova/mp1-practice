#include <fstream>
#include <sstream>
#include <iostream>
#include "auxdep.h"
#include "department.h"


int countRowsInFile(const std::string& filename) {
    std::ifstream f(filename);
    if (!f.is_open()) return -1;
    int rows = 0;
    std::string s;
    while (std::getline(f, s)) ++rows;
    return rows;
}

void fillOwnersArray(std::ifstream& f, Owner* owners, int count) {
    std::string s, sn, nm, pn, y, m, d, auto_n, pass_n, phone_n, dep;
    for (int i = 0; i < count; ++i) {
        std::getline(f, s);
        std::stringstream ss(s);

        std::getline(ss, sn, ' ');
        std::getline(ss, nm, ' ');
        std::getline(ss, pn, ';');

        owners[i].full_name.surname = sn;
        owners[i].full_name.name = nm;
        owners[i].full_name.patronymic = pn;

        std::getline(ss, y, '-');
        std::getline(ss, m, '-');
        std::getline(ss, d, ';');

        unsigned int year = static_cast<unsigned int>(std::stoul(y));
        unsigned int month = static_cast<unsigned int>(std::stoul(m));
        unsigned int day = static_cast<unsigned int>(std::stoul(d));

        owners[i].birth_date = Date(day, month, year);

        std::getline(ss, auto_n, ';');
        std::getline(ss, pass_n, ';');
        std::getline(ss, phone_n, ';');
        std::getline(ss, dep, '\n');

        owners[i].auto_number = auto_n;
        owners[i].pass_number = pass_n;
        owners[i].phone_number = phone_n;
        owners[i].department = dep;
    }
}