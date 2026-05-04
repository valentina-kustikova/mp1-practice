#include "roster.h"

ClassGroup::ClassGroup() : students(nullptr), count(0) {}

ClassGroup::ClassGroup(const string& name) : class_name(name), students(nullptr), count(0) {}

ClassGroup::ClassGroup(const ClassGroup& other) : class_name(other.class_name), count(other.count) {
    if (count > 0) {
        students = new Student[count];
        for (int i = 0; i < count; i++) {
            students[i] = other.students[i];
        }
    }
    else {
        students = nullptr;
    }
}

ClassGroup::~ClassGroup() {
    delete[] students;
}

ClassGroup& ClassGroup::operator=(const ClassGroup& other) {
    if (this != &other) {
        delete[] students;
        class_name = other.class_name;
        count = other.count;
        if (count > 0) {
            students = new Student[count];
            for (int i = 0; i < count; i++) {
                students[i] = other.students[i];
            }
        }
        else {
            students = nullptr;
        }
    }
    return *this;
}

void ClassGroup::addStudent(const Student& student) {
    Student* new_students = new Student[count + 1];
    for (int i = 0; i < count; i++) {
        new_students[i] = students[i];
    }
    new_students[count] = student;
    delete[] students;
    students = new_students;
    count++;
}

void ClassGroup::sortStudents() {
    if (students == nullptr || count <= 1) return;

    for (int i = 0; i < count - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j] < students[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Student temp = students[i];
            students[i] = students[min_idx];
            students[min_idx] = temp;
        }
    }
}

School::School() : classes(nullptr), class_count(0) {}

School::School(const string& filename) : classes(nullptr), class_count(0) {
    loadFromFile(filename);
}

School::School(const School& other) : class_count(other.class_count) {
    if (class_count > 0) {
        classes = new ClassGroup[class_count];
        for (int i = 0; i < class_count; i++) {
            classes[i] = other.classes[i];
        }
    }
    else {
        classes = nullptr;
    }
}

School::~School() {
    delete[] classes;
}

School& School::operator=(const School& other) {
    if (this != &other) {
        delete[] classes;
        class_count = other.class_count;
        if (class_count > 0) {
            classes = new ClassGroup[class_count];
            for (int i = 0; i < class_count; i++) {
                classes[i] = other.classes[i];
            }
        }
        else {
            classes = nullptr;
        }
    }
    return *this;
}

void School::loadFromFile(const string& filename) {
    ifstream fp(filename);

    if (!fp.is_open()) {
        cout << "Error opening file\n";
        return;
    }

    string line;
    Student* all_students = nullptr;
    int student_count = 0;
    size_t pos;

    while (getline(fp, line)) {
        if (line.empty()) continue;

        Student student;
        string gender_str;
        string year_str, month_str, day_str;

        pos = line.find(';');
        student.full_name.surname = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.full_name.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.full_name.patronymic = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.class_name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        gender_str = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        year_str = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        month_str = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        day_str = line.substr(0, pos);
        line.erase(0, pos + 1);

        student.birth_date.year = stoi(year_str);
        student.birth_date.month = stoi(month_str);
        student.birth_date.day = stoi(day_str);

        pos = line.find(';');
        student.address.postal_code = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.address.country = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.address.region = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.address.district = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.address.city = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.address.street = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find(';');
        student.address.house = line.substr(0, pos);
        line.erase(0, pos + 1);

        student.address.apartment = line;

        if (gender_str == "M" || gender_str == "Male")
            student.gender = male;
        else if (gender_str == "F" || gender_str == "Female")
            student.gender = female;
        else
            student.gender = unknown;

        Student* new_all = new Student[student_count + 1];
        for (int i = 0; i < student_count; i++) {
            new_all[i] = all_students[i];
        }
        new_all[student_count] = student;
        delete[] all_students;
        all_students = new_all;
        student_count++;
    }

    fp.close();

    if (student_count == 0) {
        cout << "No valid student data found\n";
        return;
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

    class_count = unique_count;
    classes = new ClassGroup[class_count];

    for (int i = 0; i < class_count; i++) {
        classes[i].class_name = unique_class_names[i];
    }

    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < class_count; j++) {
            if (all_students[i].class_name == classes[j].class_name) {
                classes[j].addStudent(all_students[i]);
                break;
            }
        }
    }

    delete[] unique_class_names;
    delete[] all_students;
}

void School::sortSchool() {
    for (int i = 0; i < class_count; i++) {
        classes[i].sortStudents();
    }
}

bool Student::operator<(const Student& other) const {
    if (full_name.surname != other.full_name.surname)
        return full_name.surname < other.full_name.surname;
    if (full_name.name != other.full_name.name)
        return full_name.name < other.full_name.name;
    return full_name.patronymic < other.full_name.patronymic;
}