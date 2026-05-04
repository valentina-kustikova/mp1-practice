#include <iostream>
#include "roster.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Incorrect number of arguments\n");
        return 1;
    }

    School school(argv[1]);
    school.sortSchool();
    cout << school;

    return 0;
}