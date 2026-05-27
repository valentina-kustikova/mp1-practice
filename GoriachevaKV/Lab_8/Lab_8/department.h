#ifndef __DEPARTMENT_H_
#define __DEPARTMENT_H_

#include <string>
#include <iostream>

struct FullName {
    std::string surname;
    std::string name;
    std::string patronymic;

    friend std::ostream& operator<<(std::ostream& out, const FullName& fn);
};

struct Date {
    unsigned int day;
    unsigned int month;
    unsigned int year;

    Date() : day(1), month(1), year(1900) {}
    Date(unsigned int d, unsigned int m, unsigned int y);

    friend std::ostream& operator<<(std::ostream& out, const Date& dt);
};

struct Owner {
    FullName full_name;
    Date birth_date;
    std::string auto_number;
    std::string pass_number;
    std::string phone_number;
    std::string department;

    friend std::ostream& operator<<(std::ostream& out, const Owner& own);
};

struct OwnerLib {
    Owner* owners;
    int count;

    OwnerLib();
    explicit OwnerLib(const std::string& filename);
    OwnerLib(const OwnerLib& other);
    ~OwnerLib();

    OwnerLib& operator=(const OwnerLib& other);

    OwnerLib filterByDepartment(const std::string& department) const;

    friend std::ostream& operator<<(std::ostream& out, const OwnerLib& lib);
};

#endif