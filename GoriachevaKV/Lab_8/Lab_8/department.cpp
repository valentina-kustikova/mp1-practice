#include <fstream>
#include <sstream>
#include <iostream>
#include "department.h"
#include "auxdep.h"


Date::Date(unsigned int d, unsigned int m, unsigned int y) {
    bool correct_date = true;
    if (y < 1900 || y > 2026) correct_date = false;
    if (m < 1 || m > 12) correct_date = false;
    if (d < 1 || d > 31) correct_date = false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) correct_date = false;
    if (m == 2 && d > 29) correct_date = false;

    if (correct_date) {
        day = d;
        month = m;
        year = y;
    }
    else {
        std::cerr << "Warning: invalid date " << d << "." << m << "." << y
            << " replaced with 1.1.1900" << std::endl;
        day = 1;
        month = 1;
        year = 1900;
    }
}


//overloading
std::ostream& operator<<(std::ostream& out, const FullName& fn) {
    out << fn.surname << " " << fn.name << " " << fn.patronymic;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Date& dt) {
    out << dt.day << "." << dt.month << "." << dt.year;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Owner& own) {
    out << own.full_name << ", " << own.birth_date << ", "
        << own.auto_number << ", " << own.pass_number << ", "
        << own.phone_number << ", " << own.department;
    return out;
}


//OwnerLib
OwnerLib::OwnerLib() : owners(nullptr), count(0) {}

OwnerLib::OwnerLib(const std::string& filename) : owners(nullptr), count(0) {
    int rows = countRowsInFile(filename);
    if (rows <= 0) {
        std::cerr << "Error: cannot read file or empty file." << std::endl;
        return;
    }
    count = rows;
    owners = new Owner[count];
    std::ifstream f(filename);
    if (!f.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        delete[] owners;
        owners = nullptr;
        count = 0;
        return;
    }
    fillOwnersArray(f, owners, count);
    f.close();
    std::cout << "The database found. " << count << " owners.\n" << std::endl;
}

OwnerLib::~OwnerLib() {
    delete[] owners;
}

const OwnerLib& OwnerLib::operator=(const OwnerLib& other) {
    if (this == &other) return *this;
    if (this->count != other.count) {
        delete[] owners;
        count = other.count;
        owners = new Owner[count];
    }
    for (int i = 0; i < count; i++)
        owners[i] = other.owners[i];
    return *this;
}

OwnerLib OwnerLib::filterByDepartment(const std::string& department) const {
    OwnerLib result;
    int matchCount = 0;
    for (int i = 0; i < count; i++)
        if (owners[i].department == department)
            matchCount++;

    result.count = matchCount;
    if (matchCount > 0) {
        result.owners = new Owner[matchCount];
        int j = 0;
        for (int i = 0; i < count; i++)
            if (owners[i].department == department)
                result.owners[j++] = owners[i];
    }
    else {
        result.owners = nullptr;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const OwnerLib& lib) {
    if (lib.count == 0) {
        out << "No owners in the list." << std::endl;
    }
    else {
        out << "-------------------------------------------------------------------------\n"
            << "FULL NAME, BIRTH DATE, AUTO NUMBER, PASS NUMBER, PHONE NUMBER, DEPARTMENT\n"
            << "-------------------------------------------------------------------------\n";
        for (int i = 0; i < lib.count; i++)
            out << lib.owners[i] << std::endl;
    }
    return out;
}