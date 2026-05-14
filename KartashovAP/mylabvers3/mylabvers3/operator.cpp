#include "roster.h"

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
    string ds, ms, ys;
    getline(in, ds, ';');
    getline(in, ms, ';');
    getline(in, ys, ';');
    a.day = stoi(ds);
    a.month = stoi(ms);
    a.year = stoi(ys);
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

istream& operator>>(istream& in, Person& p) {
    in >> p.full_name;
    string gender_str;
    getline(in, gender_str, ';');
    if (gender_str == "M" || gender_str == "Male")
        p.gender = male;
    else if (gender_str == "F" || gender_str == "Female")
        p.gender = female;
    else
        p.gender = unknown;
    in >> p.birth_date;
    return in;
}

ostream& operator<<(ostream& out, const Person& p) {
    p.print(out);
    return out;
}

istream& operator>>(istream& in, Student& s) {
    string line;
    getline(in, line);
    if (line.empty()) return in;

    stringstream ss(line);

    string surname, name, patronymic, class_name, gender_str;
    string day_str, month_str, year_str;

    string postal_code, country, region, district, city, street, house, apartment;

    getline(ss, surname, ';');
    getline(ss, name, ';');
    getline(ss, patronymic, ';');
    getline(ss, class_name, ';');
    getline(ss, gender_str, ';');
    getline(ss, day_str, ';');
    getline(ss, month_str, ';');
    getline(ss, year_str, ';');
    getline(ss, postal_code, ';');
    getline(ss, country, ';');
    getline(ss, region, ';');
    getline(ss, district, ';');
    getline(ss, city, ';');
    getline(ss, street, ';');
    getline(ss, house, ';');
    getline(ss, apartment);

    s.full_name = FullName(surname, name, patronymic);
    s.class_name = class_name;

    if (gender_str == "M" || gender_str == "Male")
        s.gender = male;
    else if (gender_str == "F" || gender_str == "Female")
        s.gender = female;
    else
        s.gender = unknown;

    s.birth_date = Date(stoi(day_str), stoi(month_str), stoi(year_str));

    Address addr;
    addr.setPostalCode(postal_code);
    addr.setCountry(country);
    addr.setRegion(region);
    addr.setDistrict(district);
    addr.setCity(city);
    addr.setStreet(street);
    addr.setHouse(house);
    addr.setApartment(apartment);
    s.address = addr;

    return in;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << "  ";
    s.print(out);
    return out;
}

istream& operator>>(istream& in, ClassGroup& a) {
    return in;
}

ostream& operator<<(ostream& out, const ClassGroup& a) {
    out << "\n========== Class " << a.class_name
        << " (" << a.count << " students) ==========\n";
    for (int i = 0; i < a.count; i++)
        out << a.students[i] << "\n\n";
    return out;
}

istream& operator>>(istream& in, School& school) {
    Student all_students[100];
    int student_count = 0;
    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Student s;

        string surname, name, patronymic, class_name, gender_str;
        string day_str, month_str, year_str;
        string postal_code, country, region, district, city, street, house, apartment;

        getline(ss, surname, ';');
        getline(ss, name, ';');
        getline(ss, patronymic, ';');
        getline(ss, class_name, ';');
        getline(ss, gender_str, ';');
        getline(ss, day_str, ';');
        getline(ss, month_str, ';');
        getline(ss, year_str, ';');
        getline(ss, postal_code, ';');
        getline(ss, country, ';');
        getline(ss, region, ';');
        getline(ss, district, ';');
        getline(ss, city, ';');
        getline(ss, street, ';');
        getline(ss, house, ';');
        getline(ss, apartment);

        s.setFullName(FullName(surname, name, patronymic));
        s.setClassName(class_name);

        if (gender_str == "M")
            s.setGender(male);
        else if (gender_str == "F")
            s.setGender(female);
        else
            s.setGender(unknown);

        s.setBirthDate(Date(stoi(day_str), stoi(month_str), stoi(year_str)));

        Address addr;
        addr.setPostalCode(postal_code);
        addr.setCountry(country);
        addr.setRegion(region);
        addr.setDistrict(district);
        addr.setCity(city);
        addr.setStreet(street);
        addr.setHouse(house);
        addr.setApartment(apartment);
        s.setAddress(addr);

        all_students[student_count++] = s;
    }

    string unique_classes[50];
    int unique_count = 0;

    for (int i = 0; i < student_count; i++) {
        bool found = false;
        for (int j = 0; j < unique_count; j++) {
            if (all_students[i].getClassName() == unique_classes[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            unique_classes[unique_count] = all_students[i].getClassName();
            unique_count++;
        }
    }

    school.class_count = unique_count;
    school.classes = new ClassGroup[unique_count];

    for (int i = 0; i < unique_count; i++) {
        school.classes[i] = ClassGroup(unique_classes[i]);
    }

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < unique_count; j++) {
            if (all_students[i].getClassName() == school.classes[j].getClassName()) {
                school.classes[j].addStudent(all_students[i]);
                break;
            }
        }
    }

    return in;
}

ostream& operator<<(ostream& out, const School& a) {
    for (int i = 0; i < a.class_count; i++)
        out << a.classes[i];
    return out;
}