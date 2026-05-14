#include "roster.h"
#include <sstream>

istream& operator>>(istream& in, FullName& a) {
    getline(in, a.surname, ';');
    getline(in, a.name, ';');
    getline(in, a.patronymic, ';');
    return in;
}

ostream& operator<<(ostream& out, const FullName& a) {
    out << a.surname << " " << a.name << " " << a.patronymic;
    return out;
}

istream& operator>>(istream& in, Date& a) {
    string day_str, month_str, year_str;
    getline(in, day_str, ';');
    getline(in, month_str, ';');
    getline(in, year_str, ';');
    a.day = stoi(day_str);
    a.month = stoi(month_str);
    a.year = stoi(year_str);
    return in;
}

ostream& operator<<(ostream& out, const Date& a) {
    out << (a.day < 10 ? "0" : "") << a.day << "."
        << (a.month < 10 ? "0" : "") << a.month << "."
        << a.year;
    return out;
}

istream& operator>>(istream& in, Address& a) {
    getline(in, a.postal_code, ';');
    getline(in, a.country, ';');
    getline(in, a.region, ';');
    getline(in, a.district, ';');
    getline(in, a.city, ';');
    getline(in, a.street, ';');
    getline(in, a.house, ';');
    getline(in, a.apartment);
    return in;
}

ostream& operator<<(ostream& out, const Address& a) {
    out << a.postal_code << ", " << a.country << ", " << a.region
        << ", " << a.district << ", " << a.city << ", "
        << a.street << ", " << a.house;
    return out;
}

istream& operator>>(istream& in, Student& a) {
    string line, gender_str, day_str, month_str, year_str;

    getline(in, line);
    if (line.empty()) return in;

    stringstream ss(line);

    getline(ss, a.full_name.surname, ';');
    getline(ss, a.full_name.name, ';');
    getline(ss, a.full_name.patronymic, ';');
    getline(ss, a.class_name, ';');
    getline(ss, gender_str, ';');
    getline(ss, day_str, ';');
    getline(ss, month_str, ';');
    getline(ss, year_str, ';');

    a.birth_date.day = stoi(day_str);
    a.birth_date.month = stoi(month_str);
    a.birth_date.year = stoi(year_str);

    getline(ss, a.address.postal_code, ';');
    getline(ss, a.address.country, ';');
    getline(ss, a.address.region, ';');
    getline(ss, a.address.district, ';');
    getline(ss, a.address.city, ';');
    getline(ss, a.address.street, ';');
    getline(ss, a.address.house, ';');
    getline(ss, a.address.apartment);

    if (gender_str == "M" || gender_str == "Male")
        a.gender = male;
    else if (gender_str == "F" || gender_str == "Female")
        a.gender = female;
    else
        a.gender = unknown;

    return in;
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

istream& operator>>(istream& in, ClassGroup& a) {
    string line;
    Student* temp_students = nullptr;
    int temp_count = 0;

    while (getline(in, line) && !line.empty()) {
        Student s;
        stringstream ss(line);

        getline(ss, s.full_name.surname, ';');
        getline(ss, s.full_name.name, ';');
        getline(ss, s.full_name.patronymic, ';');

        string class_name_from_line;
        getline(ss, class_name_from_line, ';');

        if (class_name_from_line != a.class_name) {
            continue;
        }

        s.class_name = class_name_from_line;

        string gender_str, day_str, month_str, year_str;
        getline(ss, gender_str, ';');
        getline(ss, day_str, ';');
        getline(ss, month_str, ';');
        getline(ss, year_str, ';');

        s.birth_date.day = stoi(day_str);
        s.birth_date.month = stoi(month_str);
        s.birth_date.year = stoi(year_str);

        getline(ss, s.address.postal_code, ';');
        getline(ss, s.address.country, ';');
        getline(ss, s.address.region, ';');
        getline(ss, s.address.district, ';');
        getline(ss, s.address.city, ';');
        getline(ss, s.address.street, ';');
        getline(ss, s.address.house, ';');
        getline(ss, s.address.apartment);

        if (gender_str == "M" || gender_str == "Male")
            s.gender = male;
        else if (gender_str == "F" || gender_str == "Female")
            s.gender = female;
        else
            s.gender = unknown;

        Student* new_temp = new Student[temp_count + 1];
        for (int i = 0; i < temp_count; i++) {
            new_temp[i] = temp_students[i];
        }
        new_temp[temp_count] = s;
        delete[] temp_students;
        temp_students = new_temp;
        temp_count++;
    }

    a.count = temp_count;
    a.students = temp_students;

    return in;
}

ostream& operator<<(ostream& out, const ClassGroup& a) {
    out << "\n========== Class " << a.class_name
        << " (" << a.count << " students) ==========\n";
    for (int i = 0; i < a.count; i++) {
        out << a.students[i] << "\n\n";
    }
    return out;
}

istream& operator>>(istream& in, School& a) {
    string line;
    Student* all_students = nullptr;
    int student_count = 0;

    while (getline(in, line)) {
        if (line.empty()) continue;

        Student s;
        stringstream ss(line);

        getline(ss, s.full_name.surname, ';');
        getline(ss, s.full_name.name, ';');
        getline(ss, s.full_name.patronymic, ';');
        getline(ss, s.class_name, ';');

        string gender_str, day_str, month_str, year_str;
        getline(ss, gender_str, ';');
        getline(ss, day_str, ';');
        getline(ss, month_str, ';');
        getline(ss, year_str, ';');

        s.birth_date.day = stoi(day_str);
        s.birth_date.month = stoi(month_str);
        s.birth_date.year = stoi(year_str);

        getline(ss, s.address.postal_code, ';');
        getline(ss, s.address.country, ';');
        getline(ss, s.address.region, ';');
        getline(ss, s.address.district, ';');
        getline(ss, s.address.city, ';');
        getline(ss, s.address.street, ';');
        getline(ss, s.address.house, ';');
        getline(ss, s.address.apartment);

        if (gender_str == "M" || gender_str == "Male")
            s.gender = male;
        else if (gender_str == "F" || gender_str == "Female")
            s.gender = female;
        else
            s.gender = unknown;

        Student* new_all = new Student[student_count + 1];
        for (int i = 0; i < student_count; i++) {
            new_all[i] = all_students[i];
        }
        new_all[student_count] = s;
        delete[] all_students;
        all_students = new_all;
        student_count++;
    }

    if (student_count == 0) {
        return in;
    }

    string* unique_class_names = new string[student_count];
    int unique_count = 0;

    for (int i = 0; i < student_count; i++) {
        bool found = false;
        for (int j = 0; j < unique_count; j++) {
            if (all_students[i].class_name == unique_class_names[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique_class_names[unique_count] = all_students[i].class_name;
            unique_count++;
        }
    }

    a.class_count = unique_count;
    a.classes = new ClassGroup[unique_count];

    for (int i = 0; i < unique_count; i++) {
        a.classes[i].class_name = unique_class_names[i];
    }

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < unique_count; j++) {
            if (all_students[i].class_name == a.classes[j].class_name) {
                Student* new_students = new Student[a.classes[j].count + 1];
                for (int k = 0; k < a.classes[j].count; k++) {
                    new_students[k] = a.classes[j].students[k];
                }
                new_students[a.classes[j].count] = all_students[i];
                delete[] a.classes[j].students;
                a.classes[j].students = new_students;
                a.classes[j].count++;
                break;
            }
        }
    }

    delete[] unique_class_names;
    delete[] all_students;

    return in;
}

ostream& operator<<(ostream& out, const School& a) {
    for (int i = 0; i < a.class_count; i++) {
        out << a.classes[i];
    }
    return out;
}