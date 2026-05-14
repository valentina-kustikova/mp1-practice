#include "roster.h"
#include <sstream>

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

School::School() : classes(nullptr), class_count(0) {}

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

void School::sortSchool() {
    for (int i = 0; i < class_count; i++) {
        if (classes[i].students == nullptr || classes[i].count <= 1) continue;

        for (int j = 0; j < classes[i].count - 1; j++) {
            int min_idx = j;
            for (int k = j + 1; k < classes[i].count; k++) {
                if (classes[i].students[k] < classes[i].students[min_idx]) {
                    min_idx = k;
                }
            }
            if (min_idx != j) {
                Student temp = classes[i].students[j];
                classes[i].students[j] = classes[i].students[min_idx];
                classes[i].students[min_idx] = temp;
            }
        }
    }
}

bool Student::operator<(const Student& other) const {
    if (full_name.surname != other.full_name.surname)
        return full_name.surname < other.full_name.surname;
    if (full_name.name != other.full_name.name)
        return full_name.name < other.full_name.name;
    return full_name.patronymic < other.full_name.patronymic;
}