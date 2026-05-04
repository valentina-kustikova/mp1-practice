#include "roster.h"

ostream& operator<<(ostream& out, const FullName& a) {
    out << a.surname << " " << a.name << " " << a.patronymic;
    return out;
}

ostream& operator<<(ostream& out, const Date& a) {
    out << (a.day < 10 ? "0" : "") << a.day << "."
        << (a.month < 10 ? "0" : "") << a.month << "."
        << a.year;
    return out;
}

ostream& operator<<(ostream& out, const Address& a) {
    out << a.postal_code << ", " << a.country << ", " << a.region
        << ", " << a.district << ", " << a.city << ", "
        << a.street << ", " << a.house;
    return out;
}

ostream& operator<<(ostream& out, const Student& a) {
    out << "  " << a.full_name << "\n";
    out << "  Class: " << a.class_name << "\n";
    out << "  Gender: ";
    switch (a.gender) {
    case male: out << "Male"; break;
    case female: out << "Female"; break;
    default: out << "Unknown";
    }
    out << "\n  Birth date: " << a.birth_date << "\n";
    out << "  Address: " << a.address;
    return out;
}

ostream& operator<<(ostream& out, const ClassGroup& a) {
    out << "\n========== Class " << a.class_name
        << " (" << a.count << " students) ==========\n";
    for (int i = 0; i < a.count; i++) {
        out << a.students[i] << "\n\n";
    }
    return out;
}

ostream& operator<<(ostream& out, const School& a) {
    for (int i = 0; i < a.class_count; i++) {
        out << a.classes[i];
    }
    return out;
}