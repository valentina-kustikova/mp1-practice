#ifndef AUXLI_H
#define AUXLI_H

#include "roster.h"

// Вспомогательные функции для работы со студентами
void sort_students_in_class(ClassGroup* class_group);
void print_student(const Student* student);
int compare_students(const Student* a, const Student* b);
Student* create_student(const char* surname, const char* name, const char* patronymic,
    const char* class_name, Gender gender, int year, int month, int day,
    const char* postal_code, const char* country, const char* region,
    const char* district, const char* city, const char* street,
    const char* house, const char* apartment);
void free_student(Student* student);

#endif