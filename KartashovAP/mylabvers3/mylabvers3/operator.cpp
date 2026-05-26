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

    int day = stoi(ds);
    int month = stoi(ms);
    int year = stoi(ys);

    bool valid = true;

    if (year < 1900 || year > 2026) valid = false;
    if (month < 1 || month > 12) valid = false;

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[1] = 29;
    }

    if (day < 1 || day > days_in_month[month - 1]) valid = false;

    if (valid) {
        a.setDay(day);
        a.setMonth(month);
        a.setYear(year);
    }
    else {
        cerr << "INVALID DATE: " << day << "." << month << "." << year
            << " -> REPLACED WITH 01.01.2000\n";
        a.setDay(1);
        a.setMonth(1);
        a.setYear(2000);
    }

    return in;
}

ostream& operator<<(ostream& out, const Date& a) {
    out << (a.getDay() < 10 ? "0" : "") << a.getDay() << "."
        << (a.getMonth() < 10 ? "0" : "") << a.getMonth() << "."
        << a.getYear();
    return out;
}

istream& operator>>(istream& in, Address& a) {
    string pc, c, r, d, ct, s, h, ap;
    getline(in, pc, ';');
    getline(in, c, ';');
    getline(in, r, ';');
    getline(in, d, ';');
    getline(in, ct, ';');
    getline(in, s, ';');
    getline(in, h, ';');
    getline(in, ap);

    a.setPostalCode(pc);
    a.setCountry(c);
    a.setRegion(r);
    a.setDistrict(d);
    a.setCity(ct);
    a.setStreet(s);
    a.setHouse(h);
    a.setApartment(ap);

    return in;
}

ostream& operator<<(ostream& out, const Address& a) {
    out << a.getPostalCode() << ", " << a.getCountry() << ", " << a.getRegion()
        << ", " << a.getDistrict() << ", " << a.getCity() << ", "
        << a.getStreet() << ", " << a.getHouse();
    return out;
}

istream& operator>>(istream& in, Person& p) {
    FullName fn;
    in >> fn;
    p.setFullName(fn);

    string gender_str;
    getline(in, gender_str, ';');

    if (gender_str == "M" || gender_str == "Male")
        p.setGender(male);
    else if (gender_str == "F" || gender_str == "Female")
        p.setGender(female);
    else
        p.setGender(unknown);

    Date bd;
    in >> bd;
    p.setBirthDate(bd);

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

    s.setFullName(FullName(surname, name, patronymic));
    s.setClassName(class_name);

    if (gender_str == "M" || gender_str == "Male")
        s.setGender(male);
    else if (gender_str == "F" || gender_str == "Female")
        s.setGender(female);
    else
        s.setGender(unknown);

    Date birth_date(stoi(day_str), stoi(month_str), stoi(year_str));

    int day = stoi(day_str);
    int month = stoi(month_str);
    int year = stoi(year_str);

    bool valid = true;
    if (year < 1900 || year > 2026) valid = false;
    if (month < 1 || month > 12) valid = false;

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_month[1] = 29;
    }
    if (day < 1 || day > days_in_month[month - 1]) valid = false;

    if (valid) {
        s.setBirthDate(Date(day, month, year));
    }
    else {
        cerr << "INVALID DATE: " << day << "." << month << "." << year
            << " -> REPLACED WITH 01.01.2000\n";
        s.setBirthDate(Date(1, 1, 2000));
    }

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
    out << "\n========== Class " << a.getClassName()
        << " (" << a.getCount() << " students) ==========\n";
    for (int i = 0; i < a.getCount(); i++)
        out << a.getStudents()[i] << "\n\n";
    return out;
}

istream& operator>>(istream& in, School& school) {
    Student all_students[1000];
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

        int day = stoi(day_str);
        int month = stoi(month_str);
        int year = stoi(year_str);

        bool valid = true;
        if (year < 1900 || year > 2026) valid = false;
        if (month < 1 || month > 12) valid = false;

        int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_in_month[1] = 29;
        }
        if (day < 1 || day > days_in_month[month - 1]) valid = false;

        if (valid) {
            s.setBirthDate(Date(day, month, year));
        }
        else {
            cerr << "INVALID DATE: " << day << "." << month << "." << year
                << " -> REPLACED WITH 01.01.2000\n";
            s.setBirthDate(Date(1, 1, 2000));
        }

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