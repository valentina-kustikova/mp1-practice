#include <stdio.h>
#include <stdlib.h>
#include "roster.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    School* school = (School*)malloc(sizeof(School));
    if (school == NULL) {
        printf("failed\n");
        return 1;
    }

    init_school(school);
    load_students(school, argv[1]);
    sort_school(school);
    print_school(school);
    free_school(school);
    free(school);

    return 0;
}