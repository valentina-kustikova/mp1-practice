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

void load_students(School* school, const char* filename) {
    char buffer[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int total_lines = 0;
    int student_count = 0;
    int class_index = 0;
    int class_count = 0;
    Student* all_students;
    char* surname;
    char* name;
    char* patronymic;
    char* class_name;
    char* gender_str;
    char* year_str;
    char* month_str;
    char* day_str;
    char* postal;
    char* country;
    char* region;
    char* district;
    char* city;
    char* street;
    char* house;
    char* apartment;
    char** unique_class_names;
    int unique_count = 0;
    ClassGroup* temp_classes;
    int pos;

    if (school == NULL) return;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        init_school(school);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) total_lines++;

    if (total_lines == 0) {
        printf("File is empty\n");
        fclose(fp);
        init_school(school);
        return;
    }
    rewind(fp);

    all_students = (Student*)malloc((total_lines + 1) * sizeof(Student));
    if (all_students == NULL) {
        printf("Memory allocation error\n");
        fclose(fp);
        init_school(school);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';

        strcpy(line, buffer);

        surname = strtok(line, ";");
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

        if (surname && name && patronymic && class_name && gender_str &&
            year_str && month_str && day_str &&
            postal && country && region && district && city && street && house && apartment) {

            Gender gender;
            if (strcmp(gender_str, "M") == 0) gender = male;
            else if (strcmp(gender_str, "F") == 0) gender = female;
            else gender = unknown;

            int year = atoi(year_str);
            int month = atoi(month_str);
            int day = atoi(day_str);

            Student* s = create_student(surname, name, patronymic, class_name,
                gender, year, month, day,
                postal, country, region, district,
                city, street, house, apartment);
            if (s != NULL) {
                all_students[student_count] = *s; //здесь будет bag на С++ 
                free(s);
                student_count++;
            }
        }
        else {
            printf("Warning: Skipping malformed line: %s\n", buffer);
        }
    }
    fclose(fp);

    if (student_count == 0) {
        printf("No valid student data found\n");
        free(all_students);
        init_school(school);
        return;
    }

    //поиск уникальный классов 
    for (int i = 0; i < student_count; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(all_students[i].class, all_students[j].class) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_count++;
        }
    }

    unique_class_names = (char**)malloc(unique_count * sizeof(char*));
    if (unique_class_names == NULL) {
        printf("Memory allocation error for class names\n");
        for (int k = 0; k < student_count; k++) free_student(&all_students[k]);
        free(all_students);
        return;
    }
    //заполняем названия
    for (int i = 0; i < student_count; i++) {
        int found = 0;
        for (int j = 0; j < class_index; j++) {
            if (strcmp(all_students[i].class, unique_class_names[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_class_names[class_index] = (char*)malloc(strlen(all_students[i].class) + 1);
            if (unique_class_names[class_index] != NULL) {
                strcpy(unique_class_names[class_index], all_students[i].class);
            }
            else {
                printf("Memory allocation error for class name\n");
                for (int k = 0; k < student_count; k++) free_student(&all_students[k]);
                free(all_students);
                for (int k = 0; k < class_index; k++) free(unique_class_names[k]);
                free(unique_class_names);
                return;
            }
            class_index++;
        }
    }

    class_count = unique_count;
    
    temp_classes = (ClassGroup*)malloc(class_count * sizeof(ClassGroup));
    if (temp_classes == NULL) {
        printf("Memory allocation error for classes\n");
        for (int k = 0; k < student_count; k++) free_student(&all_students[k]);
        free(all_students);
        for (int k = 0; k < class_count; k++) free(unique_class_names[k]);
        free(unique_class_names);
        return;
    }

    for (int i = 0; i < class_count; i++) {
        temp_classes[i].class_name = unique_class_names[i];
        temp_classes[i].students = NULL;
        temp_classes[i].count = 0;
    }
    free(unique_class_names);

    //подсчёт студентов в каждом классе
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < class_count; j++) {
            if (strcmp(temp_classes[j].class_name, all_students[i].class) == 0) {
                temp_classes[j].count++;
                break;
            }
        }
    }

    //выделение памяти для студентов под каждый класс
    for (int i = 0; i < class_count; i++) {
        if (temp_classes[i].count > 0) {
            temp_classes[i].students = (Student*)malloc(temp_classes[i].count * sizeof(Student));
            if (temp_classes[i].students == NULL) {
                printf("Memory allocation error for students in class %s\n", temp_classes[i].class_name);
                for (int k = 0; k < class_count; k++) {
                    if (temp_classes[k].students) free(temp_classes[k].students);
                    free(temp_classes[k].class_name);
                }
                free(temp_classes);
                for (int k = 0; k < student_count; k++) free_student(&all_students[k]);
                free(all_students);
                return;
            }
            temp_classes[i].count = 0;
        }
    }

    //распределение студентов
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < class_count; j++) {
            if (strcmp(temp_classes[j].class_name, all_students[i].class) == 0) {
                pos = temp_classes[j].count;
                temp_classes[j].students[pos] = all_students[i];
                temp_classes[j].count++;
                break;
            }
        }
    }

    school->classes = temp_classes;
    school->class_count = class_count;
    free(all_students);

    printf("Successfully loaded %d students into %d classes\n", student_count, class_count);
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