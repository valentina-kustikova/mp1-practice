#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roster.h"
#include "auxli.h"

void init_school(School* school) {
    if (school == NULL) return;
    school->classes = NULL;
    school->class_count = 0;
}

int open_students_file(FILE** fp, const char* filename) {
    *fp = fopen(filename, "r");
    if (*fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        return -1;
    }
    return 0;
}

int count_lines_in_file(FILE* fp) {
    char buffer[BUFFER_SIZE];
    int lines = 0;
    long pos = ftell(fp);

    if (pos == -1) return 0;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        lines++;
    }

    fseek(fp, pos, SEEK_SET);
    return lines;
}

Student* parse_student_line_to_struct(char* line) {
    char buffer[BUFFER_SIZE];
    char* surname, *name, *patronymic, *class_name, *gender_str;
    char* year_str, *month_str, *day_str;
    char* postal, *country, *region, *district, *city, *street, *house, *apartment;
    int year, month, day;
    Gender gender;

    strcpy(buffer, line);

    surname = strtok(buffer, ";");
    name = strtok(NULL, ";");
    patronymic = strtok(NULL, ";");
    class_name = strtok(NULL, ";");
    gender_str = strtok(NULL, ";");
    year_str = strtok(NULL, ";");
    month_str = strtok(NULL, ";");
    day_str = strtok(NULL, ";");
    postal = strtok(NULL, ";");
    country = strtok(NULL, ";");
    region = strtok(NULL, ";");
    district = strtok(NULL, ";");
    city = strtok(NULL, ";");
    street = strtok(NULL, ";");
    house = strtok(NULL, ";");
    apartment = strtok(NULL, ";");

    if (!(surname && name && patronymic && class_name && gender_str &&
        year_str && month_str && day_str && postal && country &&
        region && district && city && street && house && apartment)) {
        printf("Warning: Skipping malformed line: %s\n", line);
        return NULL;
    }

    if (strcmp(gender_str, "M") == 0) gender = male;
    else if (strcmp(gender_str, "F") == 0) gender = female;
    else gender = unknown;

    year = atoi(year_str);
    month = atoi(month_str);
    day = atoi(day_str);

    return create_student(surname, name, patronymic, class_name,
        gender, year, month, day,
        postal, country, region, district,
        city, street, house, apartment);
}

Student* read_all_students_from_file(FILE* fp, int* student_count) {
    char buffer[BUFFER_SIZE];
    int total_lines = count_lines_in_file(fp);
    Student* all_students;
    int count = 0;

    if (total_lines == 0) {
        printf("File is empty\n");
        return NULL;
    }

    rewind(fp);

    all_students = (Student*)malloc((total_lines + 1) * sizeof(Student));
    if (all_students == NULL) {
        printf("Memory allocation error for students array\n");
        return NULL;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        Student* s = parse_student_line_to_struct(buffer);

        if (s != NULL) {
            all_students[count] = *s; 
            free(s);
            count++;
        }
    }

    *student_count = count;
    
    if (count == 0) {
        free(all_students);
        return NULL;
    }

    return all_students;
}

int count_unique_classes(Student* students, int student_count) {
    int unique_count = 0;

    for (int i = 0; i < student_count; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(students[i].class, students[j].class) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_count++;
        }
    }

    return unique_count;
}

char** get_unique_class_names(Student* students, int student_count, int* unique_count) {
    char** unique_names;
    int count = count_unique_classes(students, student_count);
    int index = 0;

    if (count == 0) {
        *unique_count = 0;
        return NULL;
    }

    unique_names = (char**)malloc(count * sizeof(char*));
    if (unique_names == NULL) {
        printf("Memory allocation error\n");
        *unique_count = 0;
        return NULL;
    }

    for (int i = 0; i < student_count; i++) {
        int found = 0;
        for (int j = 0; j < index; j++) {
            if (strcmp(students[i].class, unique_names[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_names[index] = (char*)malloc(strlen(students[i].class) + 1);
            if (unique_names[index] == NULL) {
                for (int k = 0; k < index; k++) free(unique_names[k]);
                free(unique_names);
                *unique_count = 0;
                return NULL;
            }
            strcpy(unique_names[index], students[i].class);
            index++;
        }
    }

    *unique_count = count;
    return unique_names;
}


ClassGroup* create_class_groups(char** class_names, int class_count) {
    ClassGroup* classes = (ClassGroup*)malloc(class_count * sizeof(ClassGroup));
    if (classes == NULL) {
        printf("Memory allocation error for class groups\n");
        return NULL;
    }

    for (int i = 0; i < class_count; i++) {
        classes[i].class_name = class_names[i];
        classes[i].students = NULL;
        classes[i].count = 0;
    }

    return classes;
}

void count_students_in_classes(ClassGroup* classes, int class_count,
    Student* students, int student_count) {
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < class_count; j++) {
            if (strcmp(classes[j].class_name, students[i].class) == 0) {
                classes[j].count++;
                break;
            }
        }
    }
}

void allocate_memory_for_class_students(ClassGroup* classes, int class_count) {
    for (int i = 0; i < class_count; i++) {
        if (classes[i].count > 0) {
            classes[i].students = (Student*)malloc(classes[i].count * sizeof(Student));
            if (classes[i].students == NULL) {
                printf("Memory allocation error for students in class %s\n",
                    classes[i].class_name);
                return;
            }
            classes[i].count = 0; 
        }
    }
}

void distribute_students_to_classes(ClassGroup* classes, int class_count,
    Student* students, int student_count) {
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < class_count; j++) {
            if (strcmp(classes[j].class_name, students[i].class) == 0) {
                int pos = classes[j].count;
                classes[j].students[pos] = students[i];
                classes[j].count++;
                break;
            }
        }
    }
}

void cleanup_resources(Student* students, ClassGroup* classes, int class_count) {
    if (students != NULL) {
        free(students);
    }

    if (classes != NULL) {
        for (int i = 0; i < class_count; i++) {
            if (classes[i].students != NULL) {
                free(classes[i].students);
            }
            if (classes[i].class_name != NULL) {
                free(classes[i].class_name);
            }
        }
        free(classes);
    }
}

void load_students(School* school, const char* filename) {
    FILE* fp = NULL;
    Student* all_students = NULL;
    ClassGroup* classes = NULL;
    char** unique_class_names = NULL;
    int student_count = 0;
    int unique_count = 0;

    if (school == NULL) {
        return;
    }
  
    if (open_students_file(&fp, filename) != 0) {
        init_school(school);
        return;
    }

    all_students = read_all_students_from_file(fp, &student_count);
    fclose(fp);

    if (all_students == NULL || student_count == 0) {
        printf("No valid student data found\n");
        if (all_students) free(all_students);
        init_school(school);
        return;
    }

    unique_count = count_unique_classes(all_students, student_count);
    unique_class_names = get_unique_class_names(all_students, student_count, &unique_count);


    if (unique_class_names == NULL || unique_count == 0) {
        printf("No classes found\n");
        free(all_students);
        init_school(school);
        return;
    }

    classes = create_class_groups(unique_class_names, unique_count);
    if (classes == NULL) {
        for (int i = 0; i < unique_count; i++) free(unique_class_names[i]);
        free(unique_class_names);
        free(all_students);
        init_school(school);
        return;
    }

    count_students_in_classes(classes, unique_count, all_students, student_count);
    allocate_memory_for_class_students(classes, unique_count);
    distribute_students_to_classes(classes, unique_count, all_students, student_count);
 
    school->classes = classes;
    school->class_count = unique_count;
    free(all_students);

    printf("Successfully loaded %d students into %d classes\n",
        student_count, school->class_count);
}

void sort_school(School* school) {
    if (school == NULL || school->classes == NULL) return;
    for (int i = 0; i < school->class_count; i++) {
        sort_students_in_class(&school->classes[i]);
    }
}

void print_school(const School* school) {
    if (school == NULL || school->classes == NULL || school->class_count == 0) {
        printf("No data to display\n");
        return;
    }
    for (int i = 0; i < school->class_count; i++) {
        printf("\n========== Class %s (%d students) ==========\n",
            school->classes[i].class_name, school->classes[i].count);
        for (int j = 0; j < school->classes[i].count; j++) {
            print_student(&school->classes[i].students[j]);
        }
    }
}

void free_school(School* school) {
    if (school == NULL) return;
    for (int i = 0; i < school->class_count; i++) {
        if (school->classes[i].students != NULL) {
            for (int j = 0; j < school->classes[i].count; j++) {
                free_student(&school->classes[i].students[j]);
            }
            free(school->classes[i].students);
        }
        free(school->classes[i].class_name);
    }
    free(school->classes);
    school->classes = NULL;
    school->class_count = 0;
}