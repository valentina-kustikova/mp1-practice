#include <iostream>
#include <fstream>
#include "roster.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Incorrect number of arguments\n");
        return 1;
    }

    ifstream file(argv[1]);

    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    School school;
    file >> school;
    file.close();

    school.sortSchool();
    cout << school;

    return 0;
}