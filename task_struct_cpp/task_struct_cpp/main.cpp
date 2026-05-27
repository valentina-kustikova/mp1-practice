#include "Header.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    string filename;
    string input;

    if (argc < 2) { 
        throw "Error with argc";
        return 1;
    }

    PersonsLibrary personsLibrary(argv[1]);

    cout << "\nEnter name of sport: ";
    getline(cin, input);

    BestEntries result = personsLibrary.findRecord(input);
    cout << result;
    return 0;
}
