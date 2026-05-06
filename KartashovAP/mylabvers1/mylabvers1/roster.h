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
    char* class_name;
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

int open_students_file(FILE** fp, const char* filename);
int count_lines_in_file(FILE* fp);
Student* parse_student_line_to_struct(char* line);
Student* read_all_students_from_file(FILE* fp, int* student_count);
char** poisk_unique_class_names(Student* students, int student_count, int* unique_count);
ClassGroup* create_class_groups(char** class_names, int class_count);
void count_students_in_classes(ClassGroup* classes, int class_count, Student* students, int student_count);
void allocate_memory_for_class_students(ClassGroup* classes, int class_count);
void distribute_students_to_classes(ClassGroup* classes, int class_count, Student* students, int student_count);
void cleanup_resources(Student* students, ClassGroup* classes, int class_count);

#endif