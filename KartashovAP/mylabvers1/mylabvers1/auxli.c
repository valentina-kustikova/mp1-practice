#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roster.h"
#include "auxli.h"

int compare_students(const Student* a, const Student* b) {
    int cmp = strcmp(a->full_name.surname, b->full_name.surname);
    if (cmp != 0) return cmp;

    cmp = strcmp(a->full_name.name, b->full_name.name);
    if (cmp != 0) return cmp;

    return strcmp(a->full_name.patronymic, b->full_name.patronymic);
}

void sort_students_in_class(ClassGroup* class_group) {
    if (class_group == NULL || class_group->students == NULL || class_group->count <= 1)
        return;

    for (int i = 0; i < class_group->count - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < class_group->count; j++) {
            if (compare_students(&class_group->students[j], &class_group->students[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Student temp = class_group->students[i];
            class_group->students[i] = class_group->students[min_idx];
            class_group->students[min_idx] = temp;
        }
    }
}

void print_student(const Student* student) {
    if (student == NULL) return;

    printf("  %s %s %s ", student->full_name.surname, student->full_name.name, student->full_name.patronymic);

    switch (student->gender) {
    case male: printf("Male  "); break;
    case female: printf("Female  "); break;
    default: printf("Unknown  ");
    }

    printf("%02d.%02d.%04d  ",student->birth_date.day, student->birth_date.month,student->birth_date.year);

    printf("%s, %s, %s, %s, %s, %s, %s, %s\n",
        student->address.postal_code,
        student->address.country,
        student->address.region,
        student->address.district,
        student->address.city,
        student->address.street,
        student->address.house,
        student->address.apartment);
}

Student* create_student(const char* surname, const char* name, const char* patronymic,
    const char* class_name, Gender gender, int year, int month, int day,
    const char* postal_code, const char* country, const char* region,
    const char* district, const char* city, const char* street,
    const char* house, const char* apartment) {

    Student* s = (Student*)malloc(sizeof(Student));
    if (s == NULL) return NULL;

    s->full_name.surname = malloc(strlen(surname) + 1);
    s->full_name.name = malloc(strlen(name) + 1);
    s->full_name.patronymic = malloc(strlen(patronymic) + 1);
    s->class = malloc(strlen(class_name) + 1);
    s->address.postal_code = malloc(strlen(postal_code) + 1);
    s->address.country = malloc(strlen(country) + 1);
    s->address.region = malloc(strlen(region) + 1);
    s->address.district = malloc(strlen(district) + 1);
    s->address.city = malloc(strlen(city) + 1);
    s->address.street = malloc(strlen(street) + 1);
    s->address.house = malloc(strlen(house) + 1);
    s->address.apartment = malloc(strlen(apartment) + 1);

    if (!s->full_name.surname || !s->full_name.name || !s->full_name.patronymic ||
        !s->class || !s->address.postal_code || !s->address.country ||
        !s->address.region || !s->address.district || !s->address.city ||
        !s->address.street || !s->address.house || !s->address.apartment) {
        free_student(s);
        free(s);
        return NULL;
    }

    strcpy(s->full_name.surname, surname);
    strcpy(s->full_name.name, name);
    strcpy(s->full_name.patronymic, patronymic);
    strcpy(s->class, class_name);
    strcpy(s->address.postal_code, postal_code);
    strcpy(s->address.country, country);
    strcpy(s->address.region, region);
    strcpy(s->address.district, district);
    strcpy(s->address.city, city);
    strcpy(s->address.street, street);
    strcpy(s->address.house, house);
    strcpy(s->address.apartment, apartment);

    s->gender = gender;
    s->birth_date.year = year;
    s->birth_date.month = month;
    s->birth_date.day = day;

    return s;
}

void free_student(Student* student) {
    if (student == NULL) return;

    free(student->full_name.surname);
    free(student->full_name.name);
    free(student->full_name.patronymic);
    free(student->class);
    free(student->address.postal_code);
    free(student->address.country);
    free(student->address.region);
    free(student->address.district);
    free(student->address.city);
    free(student->address.street);
    free(student->address.house);
    free(student->address.apartment);
}