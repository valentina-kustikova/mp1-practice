#ifndef ROSTER_H
#define ROSTER_H

#define MAX_LEN 256
#define BUFFER_SIZE 1024


typedef enum {
    male,
    female,
    unknown
} Gender;

typedef struct {
    char* surname;
    char* name;
    char* patronymic;
} FullName;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char* postal_code;
    char* country;
    char* region;
    char* district;
    char* city;
    char* street;
    char* house;
    char* apartment;
} Address;

typedef struct {
    FullName full_name;
    char* class;
    Gender gender;
    Date birth_date;
    Address address;
} Student;

typedef struct {
    char class_name[20];
    Student* students;
    int count;
} ClassGroup;

typedef struct {
    ClassGroup* classes;
    int class_count;
} School;

void init_school(School* school);
void load_students(School* school, const char* filename);
void sort_school(School* school);
void print_school(const School* school);
void free_school(School* school);

#endif