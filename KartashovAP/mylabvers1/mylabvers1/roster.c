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
    if (school == NULL) return;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        init_school(school);
        return;
    }

    char buffer[BUFFER_SIZE];
    int total_lines = 0;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        total_lines++;
    }
    rewind(fp);

    Student* all_students = (Student*)malloc(total_lines * sizeof(Student));
    if (all_students == NULL) {
        printf("Memory allocation error\n");
        fclose(fp);
        init_school(school);
        return;
    }

    int student_count = 0;

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        char line[BUFFER_SIZE];
        strcpy(line, buffer);

        char* surname = strtok(line, ";");
        char* name = strtok(NULL, ";");
        char* patronymic = strtok(NULL, ";");
        char* class_name = strtok(NULL, ";");
        char* gender_str = strtok(NULL, ";");
        char* year_str = strtok(NULL, ";");
        char* month_str = strtok(NULL, ";");
        char* day_str = strtok(NULL, ";");
        char* postal = strtok(NULL, ";");
        char* country = strtok(NULL, ";");
        char* region = strtok(NULL, ";");
        char* district = strtok(NULL, ";");
        char* city = strtok(NULL, ";");
        char* street = strtok(NULL, ";");
        char* house = strtok(NULL, ";");
        char* apartment = strtok(NULL, ";");

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
                all_students[student_count] = *s;
                free(s);
                student_count++;
            }
        }
        else {
            printf("Warning: Skipping malformed line: %s\n", buffer);
            printf("  Expected 16 fields\n");
        }
    }
    fclose(fp);

    if (student_count == 0) {
        printf("No valid student data found\n");
        free(all_students);
        init_school(school);
        return;
    }

    school->class_count = 0;
    ClassGroup* temp_classes = NULL;

    for (int i = 0; i < student_count; i++) {
        int found = -1;
        for (int j = 0; j < school->class_count; j++) {
            if (temp_classes && strcmp(temp_classes[j].class_name, all_students[i].class) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            temp_classes = (ClassGroup*)realloc(temp_classes, (school->class_count + 1) * sizeof(ClassGroup));
            if (temp_classes == NULL) {
                printf("Memory reallocation error\n");
                for (int k = 0; k < student_count; k++) {
                    free_student(&all_students[k]);
                }
                free(all_students);
                return;
            }
            strcpy(temp_classes[school->class_count].class_name, all_students[i].class);
            temp_classes[school->class_count].students = NULL;
            temp_classes[school->class_count].count = 0;
            found = school->class_count;
            school->class_count++;
        }

        temp_classes[found].students = (Student*)realloc(temp_classes[found].students,(temp_classes[found].count + 1) * sizeof(Student));

        if (temp_classes[found].students == NULL) {
            printf("Memory reallocation error for students\n");
            for (int k = 0; k < student_count; k++) {
                free_student(&all_students[k]);
            }
            free(all_students);
            return;
        }

        temp_classes[found].students[temp_classes[found].count] = all_students[i];
        temp_classes[found].count++;
    }

    school->classes = temp_classes;
    free(all_students);

    printf("Successfully loaded %d students into %d classes\n", student_count, school->class_count);
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
    }
    free(school->classes);
    school->classes = NULL;
    school->class_count = 0;
}